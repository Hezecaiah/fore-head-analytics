/* State declaration */
/* type state = {

}; */

/* Action declaration */
/* type action =
	| ; */

/* Component template declaration.
   Needs to be **after** state and action declarations! */
let component = ReasonReact.statelessComponent("Example");

/* greeting and children are props. `children` isn't used, therefore ignored.
   We ignore it by prepending it with an underscore */
let make = (_children) => {
  /* spread the other default fields of component here and override a few */
  ...component,

  /* initialState: () => {  }, */

  /* State transitions */
  /* reducer: (action, state) =>
    switch (action) {

    }, */

  /* didMount: _self => {
    [%bs.raw {|
      new Twitch.Embed("twitch-embed", {
        width: 854,
        height: 480,
        channel: "monstercat"
      });
    |}]
  }, */

  render: _self => {
    <div>
			<h1>{ReasonReact.string("Here's the dashboard lol")}</h1>
			<p>{ReasonReact.string("Omegalul")}</p>
    </div>;
  },
};
