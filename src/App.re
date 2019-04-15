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

type streamerJSONVerbose = {
	followData: array(broadcasterVerbose)
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
	| LogIn(string, string)
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
		userData: { total: 0, userData:[||] },
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
		);
		Js.Promise.(
			Fetch.fetchWithInit({"https://api.twitch.tv/helix/users?" ++ "id=26560695&id=20650414&id=22580017&id=108994872&id=132230344&id=37356443&id=44084034&id=223307755&id=51496027&id26560695&id=44019612&id=102936080&id=75574155&id=54739364&id=40603161&id=36029255&id=38865133&id=32947748&id=105566327&id=8822&id=12826"},
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
			|> catch(_err => Js.Promise.resolve(self.send(FailedToFetch("Twitch API"))))
			|> ignore
		);
	},

  render: self => {
		<div className="container-fluid" style=(ReactDOMRe.Style.make(~margin="0", ~paddingRight="0", ~paddingLeft="0",()))>
			<nav className="nav nav-tabs navbar navbar-expand-lg" style=(ReactDOMRe.Style.make(~background="#660000",()))>
				<a className="navbar-brand" style=(ReactDOMRe.Style.make(~color="white", ~padding="5px", ~border="2px solid #FF6100", ())) href="#">{ReasonReact.string("4Head")}</a>
				<nav className="nav-item" onClick={_event => self.send(ChangeRoute(Dashboard))}><a style=(ReactDOMRe.Style.make(~color="white", ())) className="nav-link" href="#">{ReasonReact.string("Dashboard")}</a></nav>
				<nav className="nav-item" onClick={_event => self.send(ChangeRoute(JudgementPage))}><a style=(ReactDOMRe.Style.make(~color="white", ())) className="nav-link" href="#">{ReasonReact.string("Judgement")}</a></nav>
				<nav className="nav-item" onClick={_event => self.send(ChangeRoute(LogIn))}><a style=(ReactDOMRe.Style.make(~color="white", ~marginLeft="65vw", ())) className="nav-link" href="#">{ReasonReact.string("Log In")}</a></nav>
			</nav>
			/* <div id="twitch-embed"></div> */
			(
				switch (self.state.route, self.state.loggedIn) {
				| (LogIn, _) => <div className="d-flex justify-content-center">
													<div style=(ReactDOMRe.Style.make(~background="#660000", ~marginTop="50px",~padding="15px", ())) className="card d-flex flex-column justify-content-center">
														<h1>{ReasonReact.string("Log in with your Twitch credentials.")}</h1>
														<form>
															<div className="form-group">
																<label htmlFor="username">{ReasonReact.string("Twitch Username: ")}</label>
																<input className="form-control" placeholder="Username" id="username"></input>
															</div>
															<div className="form-group">
																<label htmlFor="password">{ReasonReact.string("Twitch Password: ")}</label>
																<input className="form-control" type_="password" placeholder="Password" id="password"></input>
															</div>
															<a style=(ReactDOMRe.Style.make(~color="white", ())) onClick={_event =>  self.send(ChangeRoute(Dashboard))} className="nav-link" href="dashboard"><button className="btn btn-primary align-self-center" style=(ReactDOMRe.Style.make(~background="#FF6100", ~borderRadius="0", ~borderColor="#FF7D2E", ())) type_="submit">{ReasonReact.string("Log in")}</button></a>
														</form>
													</div>
												</div>;
				| (Dashboard, true) => <Dashboard data={(self.state.followData)}/>
				| (JudgementPage, true) => <JudgementPage data={(self.state.followData)}/>
				| (_, false) => <LogIn />
				}
			)
		</div>;
  }
};

"&id=40603161&id=36029255&id=38865133&id=32947748&id=105566327&id=8822&id=12826"