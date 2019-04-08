/* State declaration */
/* type state = {

}; */

/* Action declaration */
/* type action =
	| ; */

let component = ReasonReact.statelessComponent("Example");

let make = (~number, _children) => {
	...component,

	/* initialState: () => {  }, */

	/* State transitions */
	/* reducer: (action, state) =>
		switch (action) {

		}, */

	/* didMount: _self => {

	}, */

	render: self => {
		<>
			<li>{ReasonReact.string("Streamer number: " ++ string_of_int(number))}</li><button>{ReasonReact.string("Unfollow")}</button>
		</>;
	},
};
