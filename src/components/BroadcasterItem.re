/* State declaration */
/* type state = {

}; */

/* Action declaration */
/* type action =
	| ; */

	/* type streamerJSON = {
		to_name: string,
		to_id: string,
		followed_at: string
	} */

let component = ReasonReact.statelessComponent("Example");

let make = (~broadcasterObject, _children) => {
	...component,

	/* initialState: () => {  }, */

	/* State transitions */
	/* reducer: (action, state) =>
		switch (action) {

		}, */

	didMount: _self => {
		Js.log(broadcasterObject)
	},

	render: _self => {
		<>
			<p>{ReasonReact.string("Streamer title: ")}</p><button>{ReasonReact.string("Unfollow")}</button>
		</>;
	},
};
