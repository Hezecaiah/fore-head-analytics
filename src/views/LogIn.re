let component = ReasonReact.statelessComponent("LogIn");

let make = (_children) => {
  ...component,

  render: _self => {
		<div className="d-flex justify-content-center">
			<div style=(ReactDOMRe.Style.make(~background="#660000", ~marginTop="50px",~padding="15px", ())) className="card d-flex flex-column justify-content-center">
				<h1>{ReasonReact.string("Log In")}</h1>
				<form>
					<div className="form-group">
						<label htmlFor="username">{ReasonReact.string("Twitch Username: ")}</label>
						<input className="form-control" placeholder="Username" id="username"></input>
					</div>
					<div className="form-group">
						<label htmlFor="password">{ReasonReact.string("Twitch Password: ")}</label>
						<input className="form-control" type_="password" placeholder="Password" id="password"></input>
					</div>
					<a style=(ReactDOMRe.Style.make(~color="white", ())) className="nav-link" href="dashboard"><button className="btn btn-primary align-self-center" style=(ReactDOMRe.Style.make(~background="#FF6100", ~borderRadius="0", ~borderColor="#FF7D2E", ())) type_="submit">{ReasonReact.string("Log in")}</button></a>
				</form>
			</div>
    </div>;
  },
};
