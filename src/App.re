type route =
	| LogIn
	| Dashboard
	| Page;

module type Mapper = {
  let toPage: ReasonReact.Router.url => route;
  let toUrl: route => string;
};

module Mapper: Mapper = {
  let toPage = (url: ReasonReact.Router.url) =>
		switch (url.path) {
			| ["login"] => LogIn
			| ["dashboard"] => Dashboard
			| ["page"] => Page
			| _ => Dashboard
    };
  let toUrl = page =>
    switch (page) {
			| LogIn => "login"
			| Dashboard => "dashboard"
			| Page => "page"
			| _ => "dashboard"
	};
};

type state = {
	route: route
};

type action = 
	| ChangeRoute(route, string);

let component = ReasonReact.reducerComponent("App")

let make = (_children) => {
  ...component,

	initialState: () => {
		route: ReasonReact.Router.dangerouslyGetInitialUrl() 
			|> Mapper.toPage,
	},	

	/* subscriptions: self => [
  	Sub(() => ReasonReact.Router.watchUrl(url =>
			switch (url.hash) {
				| "Dashboard" => self.send(Dummy)
				| _ => self.send(Dummy)
			}
			),
    	ReasonReact.Router.unwatchUrl,
  	),
	], */
	
	reducer: (action, _state) =>
		switch (action) {
			| ChangeRoute(route, routeName) => {
					ReasonReact.Router.replace(routeName)
					ReasonReact.Update({route:route})
				}
		},
		
	/* didMount: self => {
		let watcherID = ReasonReact.Router.watchUrl(url => {
			switch (url.path) {
			| (["dashboard"]) => ()
			| _ => ()
			}
		});
	}, */

  render: self => {
		<div>
			<ul>
				<li><button onClick={_event => self.send(ChangeRoute(LogIn, "login"))}>{ReasonReact.string("Log In")}</button></li>
				<li><button onClick={_event => self.send(ChangeRoute(Dashboard, "dashboard"))}>{ReasonReact.string("Dashboard")}</button></li>
				<li><button onClick={_event => self.send(ChangeRoute(Page, "page"))}>{ReasonReact.string("Thing 1")}</button></li>
			</ul>
			(
				switch self.state.route {
				| LogIn => <h1>{ReasonReact.string("Log In")}</h1>
				| Dashboard => <h1>{ReasonReact.string("Dashboard")}</h1>
				| Page => <h1>{ReasonReact.string("Lol it's a page")}</h1>
				}
			)
		</div>;
  }
};