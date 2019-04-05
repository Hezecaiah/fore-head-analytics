/* State declaration */
/* type state = {

}; */

/* Action declaration */
/* type action =
	| ; */

let component = ReasonReact.statelessComponent("Example");

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
		<>
			<li>{ReasonReact.string("streamer number 1")}</li><button>{ReasonReact.string("Unfollow")}</button>
		</>;
	},
};
