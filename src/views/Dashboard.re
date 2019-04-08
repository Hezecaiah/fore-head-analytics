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
    <div>
			<h1>{ReasonReact.string("Here's the dashboard lol")}</h1>
      {Array.length(data) > 0 ? ReasonReact.array(Array.map(streamer => {
        (<BroadcasterItem broadcasterObject={streamer}/>)
      }, data))
        :
        <div/>
      }
    </div>;
  },
};

