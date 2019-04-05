let component = ReasonReact.statelessComponent("LogIn");

let make = (_children) => {
  ...component,

  render: _self => {
    <div>
			<h1>{ReasonReact.string("Log in with your Twitch credentials.")}</h1>
			<form>
				<label htmlFor="username">{ReasonReact.string("Twitch Username: ")}</label>
				<input id="username"></input>
				<br></br>
				<label htmlFor="password">{ReasonReact.string("Twitch Password: ")}</label>
				<input type_="password" id="password"></input>
			</form>
    </div>;
  },
};
