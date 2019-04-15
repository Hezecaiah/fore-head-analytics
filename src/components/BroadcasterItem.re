open TypesModule

type state = {
	data: string,
	advancedStatsShown: bool
};

type action =
	| ShowAnalytics
	|	FetchUserStatistics(string)
	| FailedToFetch(string);

let component = ReasonReact.reducerComponent("Broadcaster");

let make = (~broadcasterObject, ~engagement, ~coldOpen, _children) => {
	...component,

	initialState: () => {
		data: "Lol 4Head",
		advancedStatsShown: false
	},

	reducer: (action, state) =>
		switch (action) {
			| ShowAnalytics	 => ReasonReact.Update({...state, advancedStatsShown: !state.advancedStatsShown})
			| FetchUserStatistics(data) => ReasonReact.Update({...state, data: data})
			| FailedToFetch(fetchLocation) => ReasonReact.SideEffects(_self => Js.log("Error, failed to fetch data from " ++ fetchLocation ++ "."))
		},

	/* didMount: self => {
		Fetch analytics here when the backend is built
	}, */

	render: self => {
		<>
			<div className="card m-3" style=(ReactDOMRe.Style.make(~background="#660000",()))>
				<img src={broadcasterObject.profile_image_url} style=(ReactDOMRe.Style.make(~width="300px", ~height="300px", ~margin="15px", ())) className="card-img-top" alt="..."></img>
				<div className="card-body">
					<h5 className="card-title">{ReasonReact.string(broadcasterObject.display_name)}</h5>
					<p className="card-text">{ReasonReact.string(broadcasterObject.description)}</p>
					<p className="card-text">{ReasonReact.string("Engagement: " ++ engagement)}</p>
					<p className="card-text">{ReasonReact.string("Percentage of cold opens: " ++ coldOpen)}</p>
					<a href="#" className="btn btn-primary m-3" style=(ReactDOMRe.Style.make(~background="#FF6100", ~borderRadius="0", ~borderColor="#FF7D2E", ()))>{ReasonReact.string("Stats for nerds")}</a>
					<a href="#" className="btn btn-primary m-3" style=(ReactDOMRe.Style.make(~background="#FF6100", ~borderRadius="0", ~borderColor="#FF7D2E", ()))>{ReasonReact.string("Unfollow")}</a>
				</div>
			</div>
			/* <div className="modal fade" id="exampleModal" tabIndex={-1} role="dialog" ariaLabel="exampleModalLabel" ariaHidden=true>
				<div className="modal-dialog" role="document">
					<div className="modal-content">
						<div className="modal-header">
							<h5 className="modal-title" id="exampleModalLabel">{ReasonReact.string("Modal title")}</h5>
							<button type_="button" className="close" dataDismiss="modal" ariaLabel="Close">
								<span ariaHidden=true>{ReasonReact.string("haha")}</span>
							</button>
						</div>
						<div className="modal-body">
							{ReasonReact.string("lol")}
						</div>
						<div className="modal-footer">
							<button type_="button" className="btn btn-secondary" dataDismiss="modal">{ReasonReact.string("Close")}</button>
							<button type_="button" className="btn btn-primary">{ReasonReact.string("Save changes")}</button>
						</div>
					</div>
				</div>
			</div> */
		</>;
	}
};
