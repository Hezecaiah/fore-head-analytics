/* %bs.raw {|require("https://embed.twitch.tv/embed/v1.js")|} */

/* module Twitch = {
	[@bs.new] [@bs.scope "Twitch"] external embed: (string, Js.t('a)) => unit = "Embed"; 
} */

type route =
	| LogIn
	| Dashboard
	| JudgementPage;

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
	credentials: (string, string)
};

type action = 
	| ChangeRoute(route);

let component = ReasonReact.reducerComponent("App");

let make = (_children) => {
  ...component,

	initialState: () => {
		route: ReasonReact.Router.dangerouslyGetInitialUrl() 
			|> Mapper.toPage,
		loggedIn: true,
		credentials: ("", "")
	},
	
	reducer: (action, state) => {
		switch (action) {
			| ChangeRoute(route) => 
					ReasonReact.Router.replace(Mapper.toUrl(route))
					ReasonReact.Update({...state, route:route})
		}
	},

	didMount: self => {
		let watcherID = () =>
			ReasonReact.Router.watchUrl(url =>
				self.send(ChangeRoute(Mapper.toPage(url)))
			)
		self.onUnmount(() => ReasonReact.Router.unwatchUrl(watcherID()));
		/* {[%bs.raw {|
			new window.Twitch.Embed("twitch-embed", {
				width: 854,
				height: 480,
				channel: "monstercat"
			})
		|}]} */
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
				| (Dashboard, true) => <Dashboard />
				| (JudgementPage, true) => <JudgementPage />
				| (_, false) => <LogIn />
				}
			)
			/* <div id="twitch-embed"></div> */
			/* <script>
				new Twitch.Embed("twitch-embed", {
					width: 854,
					height: 480,
					channel: "monstercat"
				});
			</script> */
      /* <script src="https://embed.twitch.tv/embed/v1.js"></script> */
		</div>;
  }
};