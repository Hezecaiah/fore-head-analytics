// Generated by BUCKLESCRIPT VERSION 5.0.0, PLEASE EDIT WITH CARE
'use strict';

var $$Array = require("bs-platform/lib/js/array.js");
var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var BroadcasterItem$ReactTemplate = require("../components/BroadcasterItem.bs.js");

var component = ReasonReact.reducerComponent("dashboard");

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
          /* render */(function (self) {
              var match = data.length !== 0;
              return React.createElement("div", {
                          className: "align-content-center"
                        }, React.createElement("div", {
                              className: "row"
                            }, React.createElement("div", {
                                  className: "col-2 d-flex flex-column",
                                  style: {
                                    background: "#020202",
                                    paddingTop: "30px"
                                  }
                                }, match ? $$Array.map((function (streamer) {
                                          return React.createElement("a", {
                                                      key: streamer[/* id */0],
                                                      className: "mb-2",
                                                      onClick: (function (_event) {
                                                          return Curry._1(self[/* send */3], /* ChangeCurrentBroadcaster */[streamer]);
                                                        })
                                                    }, streamer[/* display_name */2]);
                                        }), data) : React.createElement("div", undefined), React.createElement("p", undefined, "More...")), React.createElement("div", {
                                  className: "col-9"
                                }, React.createElement("div", {
                                      className: "row"
                                    }, ReasonReact.element(undefined, undefined, BroadcasterItem$ReactTemplate.make(self[/* state */1][/* currentBroadcaster */0], /* array */[]))))));
            }),
          /* initialState */(function (param) {
              return /* record */[/* currentBroadcaster : record */[
                        /* id */"12826",
                        /* login */"twitch",
                        /* display_name */"Twitch",
                        /* account_type */"partner",
                        /* broadcaster_type */"",
                        /* description */"Twitch is the world's leading video platform and community for gamers with more than 100 million visitors per month. Our mission is to connect gamers around the world by allowing them to broadcast, watch, and chat from everywhere they play.",
                        /* profile_image_url */"https://static-cdn.jtvnw.net/jtv_user_pictures/twitch-profile_image-8a8c5be2e3b64a9a-300x300.png",
                        /* offline_image_url */"",
                        /* view_count */225659996
                      ]];
            }),
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */(function (action, _state) {
              return /* Update */Block.__(0, [/* record */[/* currentBroadcaster */action[0]]]);
            }),
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

exports.component = component;
exports.make = make;
/* component Not a pure module */
