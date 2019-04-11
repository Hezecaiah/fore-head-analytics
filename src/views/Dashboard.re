open TypesModule

/* State declaration */
type state = {
  currentBroadcaster: broadcasterVerbose
};

/* Action declaration */
type action =
  | ChangeCurrentBroadcaster(broadcasterVerbose); 



let component = ReasonReact.reducerComponent("dashboard")

let make = (~data, _children) => {
  
  ...component,

  initialState: () => {
    currentBroadcaster: 
      {
        id: "",
        login: "",
        display_name: "",
        account_type: "",
        broadcaster_type: "",
        description: "",
        profile_image_url: "",
        offline_image_url: "",
        view_count: 0,
      }
  },

  reducer: (action, state) =>
    switch (action) {
      | ChangeCurrentBroadcaster(newBroadcaster) => ReasonReact.Update({currentBroadcaster: newBroadcaster});
    },

  didMount: self => {
    if(Array.length(data) > 0){
      self.send(ChangeCurrentBroadcaster(data[0]))
    }
  },

  render: self => {
    <div className="align-content-center">
      <div className="row">
        <div className="col-2" style=(ReactDOMRe.Style.make(~background="#020202", ~paddingTop="30px",()))>
          {Array.length(data) > 0 ? 
            ReasonReact.array(Array.map(streamer => {
              (
                <p key={streamer.id} onClick=((event) => self.send(ChangeCurrentBroadcaster(streamer)))>{ReasonReact.string(streamer.display_name)}</p>
                
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
            <div className="col-6">
              <BroadcasterItem broadcasterObject={self.state.currentBroadcaster} />
            </div>


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

