// Generated by BUCKLESCRIPT VERSION 5.0.0, PLEASE EDIT WITH CARE
'use strict';

var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");

var component = ReasonReact.statelessComponent("LogIn");

function make(_children) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (_self) {
              return React.createElement("div", undefined, React.createElement("h1", undefined, "Log in with your Twitch credentials."), React.createElement("form", undefined, React.createElement("label", {
                                  htmlFor: "username"
                                }, "Twitch Username: "), React.createElement("input", {
                                  id: "username"
                                }), React.createElement("br", undefined), React.createElement("label", {
                                  htmlFor: "password"
                                }, "Twitch Password: "), React.createElement("input", {
                                  id: "password",
                                  type: "password"
                                })));
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

exports.component = component;
exports.make = make;
/* component Not a pure module */