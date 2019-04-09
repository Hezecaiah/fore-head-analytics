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
	userData: array(streamerJSON)
};

open TypesModule

/* type broadcasterVerbose = {
	id: string,
	login: string,
	display_name: string,
	account_type: string,
	broadcaster_type: string,
	description: string,
	profile_image_url: string,
	offline_image_url: string,
	view_count: int,
}; */

type streamerJSONVerbose = {
	followData: array(TypesModule.broadcasterVerbose)
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
			userData: json |> field("data", array(decodeStreamer))
		};

	let decodeJSON = json =>
		Json.Decode.{
			id: json |> field("id", string),
			login: json |> field("login", string),
			display_name: json |> field("display_name", string),
			account_type: json |> field("type", string),
			broadcaster_type: json |> field("broadcaster_type", string),
			description: json |> field("description", string),
			profile_image_url: json |> field("profile_image_url", string),
			offline_image_url: json |> field("offline_image_url", string),
			view_count: json |> field("view_count", int)
		};

	let decodeData = json =>
		Json.Decode.{
			followData: json |> field("data", array(decodeJSON))
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
	userData: userJSON,
	followData: array(TypesModule.broadcasterVerbose),
	mutable tempStr: string
};

type action = 
	| ChangeRoute(route)
	| SetData(userJSON)
	| SetVerboseData(array(TypesModule.broadcasterVerbose))
	| FailedToFetch(string);

let component = ReasonReact.reducerComponent("App");

let make = (_children) => {
  ...component,

	initialState: () => {
		route: ReasonReact.Router.dangerouslyGetInitialUrl() 
			|> Mapper.toPage,
		loggedIn: true,
		credentials: ("", ""),
		userData: {total: 0, userData:[||]},
		followData: [||], 
		tempStr: ""
	},
	
	reducer: (action, state) => {
		switch (action) {
			| ChangeRoute(route) => 
					ReasonReact.Router.replace(Mapper.toUrl(route))
					ReasonReact.Update({...state, route:route})
			| SetData(data) => ReasonReact.Update({...state, userData: data})
			| SetVerboseData(data) => ReasonReact.Update({...state, followData: data})
			| FailedToFetch(fetchLocation) => ReasonReact.SideEffects(_self => Js.log("Error, failed to fetch data from " ++ fetchLocation ++ "."))
		}
	},

	didMount: self => {
		let watcherID = () =>
			ReasonReact.Router.watchUrl(url => self.send(ChangeRoute(Mapper.toPage(url))))
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
		)|> Js.Promise.then_(value => {
			Array.iter((data) => Js.log("jeff"), self.state.userData.userData)
			Js.Promise.resolve();
		})
		/* |> Js.Promise.then_(self => Array.iter((data) => Js.log("jeff"), self.state.userData.userData)); */
		
			/* self.state.tempStr = self.state.tempStr ++ "id=" ++ data.to_id,  */
		/* self.state.userData.userData); */
		/* Js.log("tempStr: " ++ self.state.tempStr) */
		Js.Promise.(
			Fetch.fetchWithInit({"https://api.twitch.tv/helix/users?" ++ self.state.tempStr},
			Fetch.RequestInit.make(
				~headers=Fetch.HeadersInit.make({"Client-ID": "re6wrq92zpvgqndlc8mokgr97j09l9"}),
				()
			))
			|> then_(Fetch.Response.json)
			|> then_(json =>
				json 	|> Decode.decodeData
							|> decodedData => decodedData.followData
																|> decodedJSON => self.send(SetVerboseData(decodedJSON))
																|> resolve
			)
			/* |> catch(_err => Js.Promise.resolve(self.send(FailedToFetch("Twitch API")))) */
			|> ignore
		)
	},

  render: self => {
		<div className="container-fluid">
			<nav className="nav nav-tabs navbar navbar-expand-lg" style=(ReactDOMRe.Style.make(~background="#660000",()))>
				<a className="navbar-brand" style=(ReactDOMRe.Style.make(~color="white", ())) href="#">{ReasonReact.string("Navbar")}</a>
				<nav className="nav-item" onClick={_event => self.send(ChangeRoute(LogIn))}><a style=(ReactDOMRe.Style.make(~color="white", ())) className="nav-link" href="#">{ReasonReact.string("Log In")}</a></nav>
				<nav className="nav-item" onClick={_event => self.send(ChangeRoute(Dashboard))}><a style=(ReactDOMRe.Style.make(~color="white", ())) className="nav-link" href="#">{ReasonReact.string("Dashboard")}</a></nav>
				<nav className="nav-item" onClick={_event => self.send(ChangeRoute(JudgementPage))}><a style=(ReactDOMRe.Style.make(~color="white", ())) className="nav-link" href="#">{ReasonReact.string("Judgement")}</a></nav>
			</nav>
			/* <div id="twitch-embed"></div> */
			(
				switch (self.state.route, self.state.loggedIn) {
				| (LogIn, _) => <LogIn />
				| (Dashboard, true) => <Dashboard data={self.state.followData}/>
				| (JudgementPage, true) => <JudgementPage />
				| (_, false) => <LogIn />
				}
			)
		</div>;
  }
};