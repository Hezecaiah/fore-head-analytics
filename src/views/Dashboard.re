module Twitch = {
	[@bs.new] [@bs.scope "Twitch"] external embed: (string, Js.t('a)) => unit = "Embed"; 
}
/* State declaration */
/* type state = {

}; */

/* Action declaration */
/* type action =
	| ; */

let component = ReasonReact.statelessComponent("Dashboard");

let make = (_children) => {
  ...component,

  /* initialState: () => {  }, */

  /* State transitions */
  /* reducer: (action, state) =>
    switch (action) {

    }, */

  /* didMount: _self => {
    {[%bs.raw {|
      new Twitch.Embed("twitch-embed", {
        width: 854,
        height: 480,
        channel: "monstercat"
      })
    |}]}
  }, */

  render: _self => {
    <div>
			<h1>{ReasonReact.string("Here's the dashboard lol")}</h1>
      <p>{ReasonReact.string("Omegalul")}</p>
      <div id="twitch-embed"></div>
      <ol>
        <li>{ReasonReact.string("streamer number 1")}</li>
        <li>{ReasonReact.string("streamer number 2")}</li>
        <li>{ReasonReact.string("streamer number 3")}</li>
      </ol>
      <script src="https://embed.twitch.tv/embed/v1.js"></script>
      <script type_="text/javascript">
        /* {[%bs.raw {| */
          new Twitch.Embed("twitch-embed", {
            width: 854,
            height: 480,
            channel: "monstercat"
          })
        /* |}]} */
      </script>
    </div>;
  },
};
