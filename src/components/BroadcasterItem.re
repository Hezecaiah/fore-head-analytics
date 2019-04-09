open TypesModule

/* State declaration */
/* type state = {
	data: array(broadcasterVerbose)
};

/* Action declaration */
type action =
	| AssignData(array(broadcasterVerbose))
	| FailedToFetch(string); */
/* 
module Decode = {
	let decodeJSON = json =>
		Json.Decode.{
			id: json |> field("id", string),
			login: json |> field("login", string),
			display_name: json |> field("display_name", string),
			account_type: json |> field("type", string),
			broadcaster_type: json |> field("broadcaster_type", string),
			description: json |> field("description", string),
			profile_image_url: json |> field("profile_image_url", string),
			offline_image_url: json |> field("offline_image_url", string),
			view_count: json |> field("view_count", int),
		};

		let decodeData = json =>
			Json.Decode.{
				data: json |> field("data", array(decodeJSON))
			};
}; */


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
/* 
	didMount: self => {
		Js.Promise.(
			Fetch.fetchWithInit("https://api.twitch.tv/helix/users?id=" ++ broadcasterObject[1],
			Fetch.RequestInit.make(
        ~headers=Fetch.HeadersInit.make({"Client-ID": "re6wrq92zpvgqndlc8mokgr97j09l9"}),
        ()
      ))
			|> then_(Fetch.Response.json)
			|> then_(json =>
				json 	|> Decode.decodeData
							|> decodedData => decodedData.data
																|> decodedJSON => self.send(AssignData(decodedJSON))
																|> resolve
			)
			|> catch(_err => Js.Promise.resolve(self.send(FailedToFetch("Twitch API"))))
			|> ignore
		)
	}, */

	render: self => {
			<>
			{broadcasterObject.id !== "" ? 
				<div className="card mb-3" style=(ReactDOMRe.Style.make(~background="#660000",()))>
					<img src={broadcasterObject.profile_image_url} className="card-img-top" alt="..."></img>
					<div className="card-body">
						<h5 className="card-title">{ReasonReact.string(broadcasterObject.display_name)}</h5>
						<p className="card-text">{ReasonReact.string("Some quick example text to build on the card title and make up the bulk of the card's content.")}</p>
						<a href="#" className="btn btn-primary">{ReasonReact.string("Open modal")}</a>
					</div>
				</div>
				/* <button>{ReasonReact.string("Unfollow")}</button> */
			:
				<div/>
			}	
		</>;
	}
};
