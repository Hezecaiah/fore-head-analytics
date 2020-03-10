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
		data: "Just get the data 4Head",
		advancedStatsShown: false
	},

	reducer: (action, state) =>
		switch (action) {
			| ShowAnalytics	 => ReasonReact.Update({...state, advancedStatsShown: !state.advancedStatsShown})
			| FetchUserStatistics(data) => ReasonReact.Update({...state, data: data})
			| FailedToFetch(fetchLocation) => ReasonReact.SideEffects(_self => Js.log("Error, failed to fetch data from " ++ fetchLocation ++ "."))
		},

	/* didMount: self => {
		TODO: Fetch analytics here when the backend is built
	}, */

	render: self => {
		<>
			<div className="card m-3" style=(ReactDOMRe.Style.make(~background="#660000", ~width="100%", ()))>
				<img src={broadcasterObject.profile_image_url} style=(ReactDOMRe.Style.make(~width="300px", ~height="300px", ~margin="15px", ())) className="card-img-top" alt="..."></img>
				<div className="card-body">
					<h5 className="card-title">{ReasonReact.string(broadcasterObject.display_name)}</h5>
					<p className="card-text">{ReasonReact.string(broadcasterObject.description)}</p>
					<table className="table table-dark table-striped">
						<thead>
							<tr>
								<th scope="col">{ReasonReact.string("Engagement ")}</th>
								<th scope="col">{ReasonReact.string("Total time watching")}</th>
								<th scope="col">{ReasonReact.string("Time in focus")}</th>
								<th scope="col">{ReasonReact.string("Cold open percentage")}</th>
							</tr>
						</thead>
						<tbody>
							<tr>
								<th scope="row">{ReasonReact.string(engagement)}</th>
								<td>{ReasonReact.string("4 hours, 32 minutes")}</td>
								<td>{ReasonReact.string("2 hours, 23 minute (50%)")}</td>
								<td>{ReasonReact.string("24.23%")}</td>
							</tr>
						</tbody>
					</table>
					<a href="#" className="btn btn-primary m-3" style=(ReactDOMRe.Style.make(~background="#FF6100", ~borderRadius="0", ~borderColor="#FF7D2E", ()))>{ReasonReact.string("Stats for nerds")}</a>
					<a href="#" className="btn btn-primary m-3" style=(ReactDOMRe.Style.make(~background="#FF6100", ~borderRadius="0", ~borderColor="#FF7D2E", ()))>{ReasonReact.string("Unfollow")}</a>
				</div>
			</div>
		</>;
	}
};
