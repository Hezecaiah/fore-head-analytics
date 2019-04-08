type route =
	| LogIn
	| Dashboard
	| JudgementPage;

type streamerJSON = {
	to_name: string,
	to_id: string,
	followed_at: string
}

type userJSON = {
	total: int,
	data: array(streamerJSON)
};

module Decode = {
	let decodeStreamer = json =>
		Json.Decode.{
			to_name: json |> field("to_name", string),
			to_id: json |> field("to_id", string),
			followed_at: json |> field("followed_at", string)
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
	followData: userJSON
};

type action = 
	| ChangeRoute(route)
	| SetData(userJSON)
	| FailedToFetch(string);

let component = ReasonReact.reducerComponent("App");

let make = (_children) => {
  ...component,

	initialState: () => {
		route: ReasonReact.Router.dangerouslyGetInitialUrl() 
			|> Mapper.toPage,
		loggedIn: true,
		credentials: ("", ""),
		followData: {total: 0, data:[||]}
	},
	
	reducer: (action, state) => {
		switch (action) {
			| ChangeRoute(route) => 
					ReasonReact.Router.replace(Mapper.toUrl(route))
					ReasonReact.Update({...state, route:route})
			| SetData(data) => ReasonReact.Update({...state, followData: data})
			| FailedToFetch(fetchLocation) => ReasonReact.SideEffects(_self => Js.log("Error, failed to fetch data from " ++ fetchLocation ++ "."))
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
			|> catch(_err => Js.Promise.resolve(self.send(FailedToFetch("Twitch API"))))
			|> ignore
		)
	},

  render: self => {
		<div className="container-fluid">

			<nav className="nav nav-tabs navbar navbar-expand-lg" style=(
				ReactDOMRe.Style.make(~background="#660000",())
			)>
				<a className="navbar-brand" style=(ReactDOMRe.Style.make(~color="white", ())) href="#">{ReasonReact.string("Navbar")}</a>
				<nav className="nav-item" onClick={_event => self.send(ChangeRoute(LogIn))}><a style=(ReactDOMRe.Style.make(~color="white", ())) className="nav-link" href="#">{ReasonReact.string("Log In")}</a></nav>
				<nav className="nav-item" onClick={_event => self.send(ChangeRoute(Dashboard))}><a style=(ReactDOMRe.Style.make(~color="white", ())) className="nav-link" href="#">{ReasonReact.string("Dashboard")}</a></nav>
				<nav className="nav-item" onClick={_event => self.send(ChangeRoute(JudgementPage))}><a style=(ReactDOMRe.Style.make(~color="white", ())) className="nav-link" href="#">{ReasonReact.string("Judgement")}</a></nav>
			</nav>
			/* <div id="twitch-embed"></div> */
			(
				switch (self.state.route, self.state.loggedIn) {
				| (LogIn, _) => <LogIn />
				| (Dashboard, true) => <Dashboard data={self.state.followData.data}/>
				| (JudgementPage, true) => <JudgementPage />
				| (_, false) => <LogIn />
				}
			)
		</div>;
  }
};