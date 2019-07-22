open TypesModule

type state = {
	list: array(TypesModule.broadcasterVerbose)
};

type action =
	| RemoveBroadcaster(int);

let component = ReasonReact.reducerComponent("Judgement");

let make = (~data, _children) => {
	...component,

	initialState: () => {list: [|data[1], data[14], data[17]|]},

	reducer: (action, state) =>
		switch (action) {
		| RemoveBroadcaster(index) => ReasonReact.Update({list: [|data[1], data[17]|]})

		},

	/* didMount: _self => {

	}, */

	render: self => {
		<div className="d-flex justify-content-center">
		{Array.length(self.state.list) > 0 ? 
			ReasonReact.array(Array.map(broadcasterObject => {
				(	
					<BroadcasterUnfollowItem onClick={_event => self.send(RemoveBroadcaster(1))} broadcasterObject=broadcasterObject/>
				)
			}, self.state.list))
			:
			<div/>
		}
		</div>;
	},
};
