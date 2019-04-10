open TypesModule

/* State declaration */
/* type state = {
	data: array(broadcasterVerbose)
};

/* Action declaration */
type action =
	| AssignData(array(broadcasterVerbose))
	| FailedToFetch(string); */

let component = ReasonReact.statelessComponent("Broadcaster");

let make = (~broadcasterObject, _children) => {
	...component,

	/* initialState: () => {
		data: [|{
			id: "",
			login: "",
			display_name: "",
			account_type: "",
			broadcaster_type: "",
			description: "",
			profile_image_url: "",
			offline_image_url: "",
			view_count: 0,
		}|]
	}, */

	/* State transitions */
	/* reducer: (action, state) =>
		switch (action) {
			| AssignData(dataSent) => ReasonReact.Update({data: dataSent})
			| FailedToFetch(fetchLocation) => ReasonReact.SideEffects(_self => Js.log("Error, failed to fetch data from " ++ fetchLocation ++ "."))
		}, */


	render: self => {
			<>
			/* {broadcasterObject.id !== "" ?  */
				<div className="card mb-3" style=(ReactDOMRe.Style.make(~background="#660000",()))>
					<img src={broadcasterObject.profile_image_url} style=(ReactDOMRe.Style.make(~width="150px", ~height="150px",())) className="card-img-top" alt="..."></img>
					<div className="card-body">
						<h5 className="card-title">{ReasonReact.string(broadcasterObject.display_name)}</h5>
						<p className="card-text">{ReasonReact.string("Some quick example text to build on the card title and make up the bulk of the card's content.")}</p>
						<a href="#" className="btn btn-primary">{ReasonReact.string("Open modal")}</a>
					</div>
				</div>
				/* <button>{ReasonReact.string("Unfollow")}</button> */
				/* :
					<div/>
				}	 */
		</>;
	}
};
