/* State declaration */
/* type state = {

}; */

/* Action declaration */
/* type action =
	| ; */

let component = ReasonReact.statelessComponent("Dashboard");

let make = (~data, _children) => {
  
  ...component,

  /* initialState: () => {  }, */

  /* State transitions */
  /* reducer: (action, state) =>
    switch (action) {

    }, */

  didMount: _self => {
    Js.log(data)
  },

  render: _self => {
    <div className="align-content-center">
      <h1>{ReasonReact.string("Here's the dashboard lol")}</h1>
      <div className="row">
        {Array.length(data) > 0 ? 
          ReasonReact.array(Array.map(streamer => {
            (
              <div className="col-sm-3">
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

