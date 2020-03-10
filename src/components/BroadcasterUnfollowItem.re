open TypesModule

type state = {
	data: string,
	advancedStatsShown: bool
};

type action =
	| ShowAnalytics
	|	FetchUserStatistics(string)
	| FailedToFetch(string);

let component = ReasonReact.reducerComponent("BroadcasterJudgement");

let make = (~onClick, ~broadcasterObject, _children) => {
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
		Fetch analytics here when the backend is built
	}, */

	render: self => {
		<div className="card m-3" style=(ReactDOMRe.Style.make(~background="#660000", ~width="25vw",()))>
			<div className="d-flex flex-row">
				<img src={broadcasterObject.profile_image_url} style=(ReactDOMRe.Style.make(~width="100px", ~height="100px", ~margin="15px", ~border="3px solid #020202", ())) className="card-img-top" alt="..."></img>
				<h5 className="card-title" style=(ReactDOMRe.Style.make(~margin="40px", ()))>{ReasonReact.string(broadcasterObject.display_name)}</h5>
			</div>
			<div className="card-body d-flex flex-column justify-content-center">
				<table className="table table-dark table-striped">
					<thead>
						<tr>
							<th scope="col">{ReasonReact.string("Engagement ")}</th>
							<th scope="col">{ReasonReact.string("Total time watching")}</th>
						</tr>
					</thead>
					<tbody>
						<tr>
							<th scope="row">{ReasonReact.string("23.53/100 points")}</th>
							<td>{ReasonReact.string("4 hours, 32 minutes")}</td>
						</tr>
					</tbody>
					<thead>
						<tr>
							<th scope="col">{ReasonReact.string("Time in focus")}</th>
							<th scope="col">{ReasonReact.string("Cold open percentage")}</th>
						</tr>
					</thead>
					<tbody>
						<tr>
							<td>{ReasonReact.string("2 hours, 23 minute (50%)")}</td>
							<td>{ReasonReact.string("24.23%")}</td>
						</tr>
					</tbody>
				</table>
				<a href="#" className="btn btn-primary m-3 align-self-end" style=(ReactDOMRe.Style.make(~background="#FF6100", ~borderRadius="0", ~borderColor="#FF7D2E", ()))>{ReasonReact.string("Stats for nerds")}</a>
				<a href="#" onClick={onClick} className="btn btn-primary m-3 align-self-end" style=(ReactDOMRe.Style.make(~background="#FF6100", ~borderRadius="0", ~borderColor="#FF7D2E", ()))>{ReasonReact.string("Unfollow")}</a>
			</div>
		</div>
	}
};
