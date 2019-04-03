type route =
	| Home
	| Thing
	| Thing2;

type state = {
	route: route
}

type action = 
	| ChangeRoute(route);

let component = ReasonReact.reducerComponent("App")

let mapUrlToRoute = (url: ReasonReact.Router.url) =>
  switch url.path {
  | ["home"] => Home
  | ["thing_1"] => Thing
  | ["thing_2"] => Thing2
  | _ => Home
  };

let make = (_children) => {
  ...component,

  initialState: () => {route: Home},
	
	reducer: (action, state) =>
		switch (action) {
		| ChangeRoute(route) => ReasonReact.NoUpdate
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
			(
				switch self.state.route {
				| Home => <h1>{ReasonReact.string("Home")}</h1>
				| Thing => <h1>{ReasonReact.string("Thing 1")}</h1>
				| Thing2 => <h1>{ReasonReact.string("Thing 2")}</h1>
				}
			)
		</div>;
  },
};