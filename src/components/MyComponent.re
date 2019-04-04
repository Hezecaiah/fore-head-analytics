/* State declaration */
type state = {
	dummy: bool
};

/* Action declaration */
type action =
	| State
  | Something
	| Nothing;

/* Component template declaration.
   Needs to be **after** state and action declarations! */
let component = ReasonReact.reducerComponent("Test");

/* Props. `children` isn't used, therefore ignored.
   We ignore it by prepending it with an underscore */
let make = (_children) => {
  /* spread the other default fields of component here and override a few */
	...component,

	initialState: () => { dummy:true },

  /* State transitions */
  reducer: (action, state) =>
    switch (action) {
		| State => ReasonReact.Update({dummy: !state.dummy})
    | Something => ReasonReact.SideEffects(_self => Js.log(ReasonReact.string("Lol")))
    | Nothing => ReasonReact.NoUpdate
		},
		
  render: self => {
    <div>
			<h1>{ReasonReact.string("Name Jeeef.")}</h1>
			<button onClick={_event => self.send(Something)}>
				{ReasonReact.string("Modify stuff")}
			</button>
    </div>;
  },
};
