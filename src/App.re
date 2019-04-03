type route =
	| Home
	| Thing
	| Thing2;

type state = {
	route: route
};

type action = 
	| ChangeRoute(route);

let component = ReasonReact.reducerComponent("App")

/* let mapUrlToRoute = (url: ReasonReact.Router.url) =>
  switch url.path {
  | ["home"] => Home
  | ["thing"] => Thing
  | ["thing2"] => Thing2
  | _ => Home
  }; */

let make = (_children) => {
  ...component,

  initialState: () => {route: Home},
	
	reducer: (action, _state) =>
		switch (action) {
		| ChangeRoute(route) => ReasonReact.Update({route:route})
		},
		
	/* didMount: self => {
		let watcherID = ReasonReact.Router.watchUrl(url => {
			switch (url.path) {
			| (["home"]) => Home
			}
		});
	}, */

  render: self => {
		<div>
			<ul>
				<li><button onClick={_event => self.send(ChangeRoute(Home))}>{ReasonReact.string("Home")}</button></li>
				<li><button onClick={_event => self.send(ChangeRoute(Thing))}>{ReasonReact.string("Thing")}</button></li>
				<li><button onClick={_event => self.send(ChangeRoute(Thing2))}>{ReasonReact.string("Thing 2")}</button></li>
			</ul>
			( 
				switch self.state.route {
				| Home => <h1>{ReasonReact.string("Home")}</h1>
				| Thing => <h1>{ReasonReact.string("Thing 1")}</h1>
				| Thing2 => <h1>{ReasonReact.string("Thing 2")}</h1>
				| _ => <h1>{ReasonReact.string("Home")}</h1>
				}
			)
		</div>;
  }
};