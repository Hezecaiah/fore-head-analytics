open TypesModule

/* State declaration */
type state = {
	list: array(TypesModule.broadcasterVerbose)
};

/* Action declaration */
type action =
	| RemoveBroadcaster;

	/* Component template declaration.
  	Needs to be **after** state and action declarations! */
let component = ReasonReact.reducerComponent("Judgement");

let make = (~data, _children) => {
	...component,

	initialState: () => {list: [|data[1], data[14], data[17]|]},

	/* State transitions */
	reducer: (action, state) =>
		switch (action) {
		| RemoveBroadcaster => ReasonReact.Update({list: [|data[1], data[17]|]})
		},

	/* didMount: _self => {

	}, */

	render: self => {
		<div className="d-flex justify-content-center">
		{Array.length(self.state.list) > 0 ? 
			ReasonReact.array(Array.map(broadcasterObject => {
				(	
					<div onClick={_event => self.send(RemoveBroadcaster)}>
					<BroadcasterUnfollowItem broadcasterObject=broadcasterObject/>
					</div>
					/* <div className="card m-3" style=(ReactDOMRe.Style.make(~background="#660000", ~width="25vw",()))>
						<div className="d-flex flex-row">
							<img src={broadcasterObject.profile_image_url} style=(ReactDOMRe.Style.make(~width="100px", ~height="100px", ~margin="15px", ~border="3px solid #020202", ())) className="card-img-top" alt="..."></img>
							<h5 className="card-title" style=(ReactDOMRe.Style.make(~margin="40px", ()))>{ReasonReact.string(broadcasterObject.display_name)}</h5>
						</div>
						<div className="card-body d-flex flex-column justify-content-center">
							<p className="card-text">{ReasonReact.string("Engagement: ")}</p>
							<p className="card-text">{ReasonReact.string("Percentage of cold opens: ")}</p>
							<a href="#" className="btn btn-primary m-3 align-self-end" style=(ReactDOMRe.Style.make(~background="#FF6100", ~borderRadius="0", ~borderColor="#FF7D2E", ()))>{ReasonReact.string("Stats for nerds")}</a>
							<a href="#" onClick={_event => self.send(RemoveBroadcaster)} className="btn btn-primary m-3 align-self-end" style=(ReactDOMRe.Style.make(~background="#FF6100", ~borderRadius="0", ~borderColor="#FF7D2E", ()))>{ReasonReact.string("Unfollow")}</a>
						</div>
					</div> */
				)
			}, self.state.list))
			:
			<div/>
		}
		</div>;
	},
};
