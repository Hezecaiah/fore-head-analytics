open TypesModule

type state = {
  currentBroadcaster: broadcasterVerbose
};

type action =
  | ChangeCurrentBroadcaster(broadcasterVerbose);

let component = ReasonReact.reducerComponent("dashboard")

let make = (~data, _children) => {
  
  ...component,

  initialState: () => {
    currentBroadcaster: 
      {
        id: "12826",
        login: "twitch",
        display_name: "Twitch",
        account_type: "partner",
        broadcaster_type: "",
        description: "Twitch is the world's leading video platform and community for gamers with more than 100 million visitors per month. Our mission is to connect gamers around the world by allowing them to broadcast, watch, and chat from everywhere they play.",
        profile_image_url: "https://static-cdn.jtvnw.net/jtv_user_pictures/twitch-profile_image-8a8c5be2e3b64a9a-300x300.png",
        offline_image_url: "",
        view_count: 225659996,
      }
  },

  reducer: (action, _state) =>
    switch (action) {
      | ChangeCurrentBroadcaster(newBroadcaster) => ReasonReact.Update({currentBroadcaster: newBroadcaster});
    },

  render: self => {
    <div className="align-content-center">
      <div className="row">
        <div className="col-2 d-flex flex-column" style=(ReactDOMRe.Style.make(~background="#020202", ~paddingTop="30px", ~marginLeft="15px", ~border="5px solid #660000", ()))>
          <h3 style=(ReactDOMRe.Style.make(~marginTop="-15px", ()))><u>{ReasonReact.string("Streamers")}</u></h3>
          {Array.length(data) > 0 ? 
            ReasonReact.array(Array.map(streamer => {
              (
                <a className="mb-2" key={streamer.id} onClick=((_event) => self.send(ChangeCurrentBroadcaster(streamer)))>{ReasonReact.string(streamer.display_name)}</a>
                
                /* <div key={streamer.id} className="col-sm-"> */
                  /* <BroadcasterItem key={streamer.id} broadcasterObject={streamer}/> */
                /* </div> */
              )
            }, data))
            :
            <div/>
          }
          <p>{ReasonReact.string("More...")}</p>
        </div>
        <div className="col-9">
          <div className="row">
              <BroadcasterItem broadcasterObject={self.state.currentBroadcaster} />

            /* {Array.length(data) > 0 ? 
              ReasonReact.array(Array.map(streamer => {
                (
                  /* <p key={streamer.id}>{ReasonReact.string(streamer.display_name)}</p> */
                  <div key={streamer.id} className="col-sm-4">
                    <BroadcasterItem key={streamer.id} broadcasterObject={streamer}/>
                  </div>
                )
              }, data))
              :
              <div/>
            } */

          </div>
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

