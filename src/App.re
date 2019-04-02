type route =
	| Home
	| Thing
	| Thing2;

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

let make = (~greeting, _children) => {
  ...component,

  initialState: () => {route: Home},
	
	reducer: (action, state) =>
		switch (action) {
		/* router actions */
		| ShowAll => ReasonReact.Update({...state, nowShowing: AllTodos})
		| ShowActive => ReasonReact.NoUpdate
		| ChangeTodo(text) => ReasonReact.NoUpdate
		| ShowShared => ReasonReact.NoUpdate
		},
		
	didMount: self => {
		let watcherID = ReasonReact.Router.watchUrl(url => {
			switch (url.hash, MyAppStatus.isUserLoggedIn) {
			| ("active", _) => self.send(ShowActive)
			| ("completed", _) => self.send(ShowCompleted)
			| ("shared", true) => self.send(ShowShared)
			| ("shared", false) when isSpecialUser => /* handle this state please */
			| ("shared", false) => self.send(ShowActive)/* handle this state please */
			| _ => self.send(ShowAll)
			}
		});
	}
	
	self.onUnmount(() => ReasonReact.Router.unwatchUrl(watcherID));

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