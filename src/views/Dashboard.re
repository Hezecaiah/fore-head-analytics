/* State declaration */
/* type state = {
  followData: array(TypesModule.broadcasterVerbose),
  dataString: array(string)
};

/* Action declaration */
type action =
  | SetVerboseData(array(TypesModule.broadcasterVerbose)); */

open TypesModule

let component = ReasonReact.statelessComponent("dashboard")

let make = (~data, _children) => {
  
  ...component,

  /* initialState: () => {
    followData: [||],
    dataString: [||]
  }, */

  /* State transitions */
  /* reducer: (action, state) =>
    switch (action) {
			| SetVerboseData(data) => ReasonReact.Update({...state, followData: data});
    }, */

  /* didMount: self => {
    Js.log("state here")
    Js.log(self.state.followData)
    /* Js.log(Array.map((item) => item.id, self.state.followData)) */
    /* Js.Promise.(
			Fetch.fetchWithInit({"https://api.twitch.tv/helix/users?" ++ "login=ikehs" ++ "&login=SexyBamboe"},
			Fetch.RequestInit.make(
				~headers=Fetch.HeadersInit.make({"Client-ID": "re6wrq92zpvgqndlc8mokgr97j09l9"}),
				()
			))
			|> then_(Fetch.Response.json)
			|> then_(json =>
				json 	|> Decode.decodeData
							|> decodedData => decodedData.followData
																|> decodedJSON => self.send(SetVerboseData(decodedJSON))
																|> resolve
			)
			/* |> catch(_err => Js.Promise.resolve(self.send(FailedToFetch("Twitch API")))) */
			|> ignore
		); */
  }, */

  render: _self => {
    <div className="align-content-center">
      <h1>{ReasonReact.string("Here's the dashboard lol")}</h1>
      <div className="row">
        {Array.length(data) > 0 ? 
          ReasonReact.array(Array.map(streamer => {
            (
              <div key={streamer.id} className="col-sm-3">
                <BroadcasterItem broadcasterObject={streamer}/>
              </div>
            )
          }, data))
          :
          <div/>
        }
      </div>
    </div>;
  }
};

