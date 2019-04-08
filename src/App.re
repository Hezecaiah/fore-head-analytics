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

			<nav className="navbar navbar-expand-lg navbar-light bg-light">
				<a className="navbar-brand" href="#">{ReasonReact.string("Navbar")}</a>
				/* <button className="navbar-toggler" type_="button" data-toggle="collapse" data-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
					<span className="navbar-toggler-icon"></span>
				</button> */
			
				<div className="collapse navbar-collapse" id="navbarSupportedContent">
					<ul className="navbar-nav mr-auto">
						<li className="nav-item active">
							<a className="nav-link" href="#">{ReasonReact.string("Home")}<span className="sr-only">{ReasonReact.string("(current)")}</span></a>
						</li>
						<li className="nav-item">
							<a className="nav-link" href="#">{ReasonReact.string("Link")}</a>
						</li>
						<li className="nav-item dropdown">
							/* <a className="nav-link dropdown-toggle" href="#" id="navbarDropdown" role="button" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
								{ReasonReact.string("Dropdown")}
							</a> */
							<div className="dropdown-menu">
								<a className="dropdown-item" href="#">{ReasonReact.string("action")}</a>
								<a className="dropdown-item" href="#">{ReasonReact.string("Another action")}</a>
								<div className="dropdown-divider"></div>
								<a className="dropdown-item" href="#">{ReasonReact.string("Yet another action")}</a>
							</div>
						</li>
					</ul>
				</div>
			</nav>

			<ul>
				<li><button onClick={_event => self.send(ChangeRoute(LogIn))}>{ReasonReact.string("Log In")}</button></li>
				<li><button onClick={_event => self.send(ChangeRoute(Dashboard))}>{ReasonReact.string("Dashboard")}</button></li>
				<li><button onClick={_event => self.send(ChangeRoute(JudgementPage))}>{ReasonReact.string("Judgement Page")}</button></li>
			</ul>
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