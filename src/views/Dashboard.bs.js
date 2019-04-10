// Generated by BUCKLESCRIPT VERSION 5.0.0, PLEASE EDIT WITH CARE
'use strict';

var $$Array = require("bs-platform/lib/js/array.js");
var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var BroadcasterItem$ReactTemplate = require("../components/BroadcasterItem.bs.js");

var component = ReasonReact.statelessComponent("dashboard");

function make(data, _children) {
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
              var match = data.length !== 0;
              return React.createElement("div", {
                          className: "align-content-center"
                        }, React.createElement("h1", undefined, "Here's the dashboard lol"), React.createElement("div", {
                              className: "row"
                            }, match ? $$Array.map((function (streamer) {
                                      return React.createElement("div", {
                                                  key: streamer[/* id */0],
                                                  className: "col-sm-3"
                                                }, ReasonReact.element(undefined, undefined, BroadcasterItem$ReactTemplate.make(streamer, /* array */[])));
                                    }), data) : React.createElement("div", undefined)));
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
