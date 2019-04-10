/* State declaration */
/* type state = {

};

/* Action declaration */
type action =
  | ; 
*/

open TypesModule

let component = ReasonReact.statelessComponent("dashboard")

let make = (~data, _children) => {
  
  ...component,

  /* initialState: () => {

  }, */

  /* State transitions */
  /* reducer: (action, state) =>
    switch (action) {
      | ;
    }, */

  /* didMount: self => {

  }, */

  render: _self => {
    <div className="align-content-center">
      <div className="row">
        <div className="col-2" style=(ReactDOMRe.Style.make(~background="#020202",()))>
          {Array.length(data) > 0 ? 
            ReasonReact.array(Array.map(streamer => {
              (
                <p key={streamer.id}>{ReasonReact.string(streamer.display_name)}</p>
                /* <div key={streamer.id} className="col-sm-"> */
                  /* <BroadcasterItem key={streamer.id} broadcasterObject={streamer}/> */
                /* </div> */
              )
            }, data))
            :
            <div/>
          }
        </div>
        <div className="col-9">
          <div id="twitch-embed"/>
          <h1>{ReasonReact.string("Stuff goes here")}</h1>
        </div>
        /* <script src="https://embed.twitch.tv/embed/v1.js"></script>
        <script type_="text/javascript">
          new Twitch.Embed("twitch-embed", {
            width: 854,
            height: 480,
            channel: "monstercat"
          });
        </script> */
      </div>
    </div>;
  }
};

