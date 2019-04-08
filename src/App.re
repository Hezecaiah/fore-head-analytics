type route =
	| LogIn
	| Dashboard
	| JudgementPage;

type streamerJSON = {
	followed_at: string,
	to_id: string,
	to_name: string
}

type userJSON = {
	total: int,
	data: array(streamerJSON)
};

module Decode = {
	let decodeStreamer = json =>
		Json.Decode.{
			followed_at: json |> field("followed_at", string),
			to_id: json |> field("to_id", string),
			to_name: json |> field("to_name", string)
		};

	let decodeUser = json => 
		Json.Decode.{
			total: json |> field("total", int),
			data: json |> field("data", array(decodeStreamer))
		};
};

module type Mapper = {
  let toPage: ReasonReact.Router.url => route;
  let toUrl: route => string;
};

module Mapper: Mapper = {
  let toPage = (url: ReasonReact.Router.url) =>
		switch (url.path) {
			| ["login"] => LogIn
			| ["dashboard"] => Dashboard
			| ["judgement"] => JudgementPage
			| _ => Dashboard;
    };
  let toUrl = page =>
    switch (page) {
			| LogIn => "login"
			| Dashboard => "dashboard"
			| JudgementPage => "judgement";
	};
};

type state = {
	route: route,
	loggedIn: bool,
	credentials: (string, string),
	followData: array(userJSON)
};

type action = 
	| ChangeRoute(route)
	| SetData(userJSON);

let component = ReasonReact.reducerComponent("App");

let make = (_children) => {
  ...component,

	initialState: () => {
		route: ReasonReact.Router.dangerouslyGetInitialUrl() 
			|> Mapper.toPage,
		loggedIn: true,
		credentials: ("", ""),
		followData: [||]
	},
	
	reducer: (action, state) => {
		switch (action) {
			| ChangeRoute(route) => 
					ReasonReact.Router.replace(Mapper.toUrl(route))
					ReasonReact.Update({...state, route:route})
			| SetData(data) => 
				Js.log(Array.make(1, data))

				ReasonReact.Update({...state, followData: Array.make(1, data)})
		}
	},

	didMount: self => {
		let watcherID = () =>
			ReasonReact.Router.watchUrl(url =>
				self.send(ChangeRoute(Mapper.toPage(url)))
			)
		self.onUnmount(() => ReasonReact.Router.unwatchUrl(watcherID()));
		Js.Promise.(
			Fetch.fetchWithInit("https://api.twitch.tv/helix/users/follows?from_id=114494398",
			Fetch.RequestInit.make(
        ~headers=Fetch.HeadersInit.make({"Client-ID": "re6wrq92zpvgqndlc8mokgr97j09l9"}),
        ()
      ))
			|> then_(Fetch.Response.json)
			|> then_(json =>
				json	|> Decode.decodeUser
							|> decodedJSON => self.send(SetData(decodedJSON))
							|> resolve
			)
			/* |> catch(err => resolve(Js.Promise.resolve(self.send))) */
			|> ignore
		)
	},

  render: self => {
		<div>
			<ul>
				<li><button onClick={_event => self.send(ChangeRoute(LogIn))}>{ReasonReact.string("Log In")}</button></li>
				<li><button onClick={_event => self.send(ChangeRoute(Dashboard))}>{ReasonReact.string("Dashboard")}</button></li>
				<li><button onClick={_event => self.send(ChangeRoute(JudgementPage))}>{ReasonReact.string("Judgement Page")}</button></li>
			</ul>
			(
				switch (self.state.route, self.state.loggedIn) {
				| (LogIn, _) => <LogIn />
				| (Dashboard, true) => <Dashboard data=self.state.followData/>
				| (JudgementPage, true) => <JudgementPage />
				| (_, false) => <LogIn />
				}
			)
		</div>;
  }
};