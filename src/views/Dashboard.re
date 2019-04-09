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

open TypesModule

let component = ReasonReact.statelessComponent("Dashboard");

let make = (~data, _children) => {
  
  ...component,

  /* initialState: () => {  }, */

  /* State transitions */
  /* reducer: (action, state) =>
    switch (action) {

    }, */

  render: _self => {
    <div className="align-content-center">
      <h1>{ReasonReact.string("Here's the dashboard lol")}</h1>
      <div className="row">
        {Array.length(data) > 0 ? 
          /* <div className="col-sm-3">
                <BroadcasterItem broadcasterObject={data[0]}/>
              </div> */
          ReasonReact.array(Array.map(streamer => {
            (
              <div className="col-sm-3">
                <BroadcasterItem key={streamer.id} broadcasterObject={streamer}/>
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

