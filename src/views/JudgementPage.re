/* State declaration */
/* type state = {

}; */

/* Action declaration */
/* type action =
	| ; */

	/* Component template declaration.
  	Needs to be **after** state and action declarations! */
let component = ReasonReact.statelessComponent("Judgement");

let make = (_children) => {
	...component,

	/* initialState: () => {  }, */

	/* State transitions */
	/* reducer: (action, state) =>
		switch (action) {

		}, */

	/* didMount: _self => {

	}, */

	render: _self => {
		<div>
			<p>{ReasonReact.string("Do the thing")}</p>
			<h1>{ReasonReact.string("Haha lol")}</h1>
		</div>;
	},
};
