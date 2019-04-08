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
      <p>{ReasonReact.string("Omegalul")}</p>
      /* <div id="twitch-embed"></div> */
      /* {ReasonReact.array(Array.map(streamer => {
        (
          <BroadcasterItem number=2/>
        )
      }, data)} */
      /* <ol>
        <BroadcasterItem number=1/>
        <BroadcasterItem number=2/>
        <BroadcasterItem number=3/>
        <BroadcasterItem number=4/>
        <BroadcasterItem number=5/>
      </ol> */
    </div>;
  },
};

