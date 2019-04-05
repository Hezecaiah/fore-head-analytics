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
	route: route
};

type action = 
	| ChangeRoute(route);

let component = ReasonReact.reducerComponent("App");

let make = (_children) => {
  ...component,

	initialState: () => {
		route: ReasonReact.Router.dangerouslyGetInitialUrl() 
			|> Mapper.toPage,
	},
	
	reducer: (action, _state) => {
		switch (action) {
			| ChangeRoute(route) => 
					ReasonReact.Router.replace(Mapper.toUrl(route))
					ReasonReact.Update({route:route})
		}
	},

	didMount: self => {
		let watcherID = () =>
			ReasonReact.Router.watchUrl(url =>
				self.send(ChangeRoute(Mapper.toPage(url)))
			)
		/* Omegalul */
		self.onUnmount(() => ReasonReact.Router.unwatchUrl(watcherID()));
	},

  render: self => {
		<div>
			<ul>
				<li><button onClick={_event => self.send(ChangeRoute(LogIn))}>{ReasonReact.string("Log In")}</button></li>
				<li><button onClick={_event => self.send(ChangeRoute(Dashboard))}>{ReasonReact.string("Dashboard")}</button></li>
				<li><button onClick={_event => self.send(ChangeRoute(JudgementPage))}>{ReasonReact.string("Judgement Page")}</button></li>
			</ul>
			(
				switch self.state.route {
				| LogIn => <LogIn />
				| Dashboard => <Dashboard />
				| JudgementPage => <JudgementPage />
				}
			)
		</div>;
  }
};