type broadcasterVerbose = {
	id: string,
	login: string,
	display_name: string,
	account_type: string,
	broadcaster_type: string,
	description: string,
	profile_image_url: string,
	offline_image_url: string,
	view_count: int,
	email: string
};

/* State declaration */
type state = {
	data: broadcasterVerbose
};

/* Action declaration */
type action =
	| AssignData(broadcasterVerbose);

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
			email: json |> field("email", string)
		};

		let decodeData = json =>
			Json.Decode.{
				data: json |> field("data", decodeJSON)
			};
};


let component = ReasonReact.reducerComponent("Broadcaster");

let make = (~broadcasterObject, _children) => {
	...component,

	initialState: () => {
		data: {
			id: "",
			login: "",
			display_name: "",
			account_type: "",
			broadcaster_type: "",
			description: "",
			profile_image_url: "",
			offline_image_url: "",
			view_count: 0,
			email: ""
		}
	},

	/* State transitions */
	reducer: (action, state) =>
		switch (action) {
			|AssignData(data) => ReasonReact.Update({data: data})
		},

	didMount: self => {
		Js.Promise.(
			Fetch.fetchWithInit("https://api.twitch.tv/helix/users?login=" ++ broadcasterObject[0],
			Fetch.RequestInit.make(
        ~headers=Fetch.HeadersInit.make({"Client-ID": "re6wrq92zpvgqndlc8mokgr97j09l9"}),
        ()
      ))
			|> then_(Fetch.Response.json)
			|> then_(json =>
				json 	|> Decode.decodeData
							|> json => self.send(AssignData(json.data))
							|> resolve
			)
			/* |> catch(_err => Js.Promise.resolve(self.send(FailedToFetch("Twitch API")))) */
			|> ignore
		)
		Js.log(self.state.data)
	},

	render: self => {
			<>
			{self.state.data.id !== "" ? 
			<div className="card mb-3" style=(ReactDOMRe.Style.make(~background="#660000",()))>
					<img src={self.state.data.profile_image_url} className="card-img-top" alt="..."></img>
					<div className="card-body">
						<h5 className="card-title">{ReasonReact.string(broadcasterObject[0])}</h5>
						<p className="card-text">{ReasonReact.string("Some quick example text to build on the card title and make up the bulk of the card's content.")}</p>
						<a href="#" className="btn btn-primary">{ReasonReact.string("Open modal")}</a>
					</div>
				</div>
				/* <p></p><button>{ReasonReact.string("Unfollow")}</button> */

			:
			<div/>
			}	
		</>;
	}
};
