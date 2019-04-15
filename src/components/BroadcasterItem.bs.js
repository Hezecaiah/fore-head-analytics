// Generated by BUCKLESCRIPT VERSION 5.0.0, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");
var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");

var component = ReasonReact.reducerComponent("Broadcaster");

function make(broadcasterObject, engagement, coldOpen, _children) {
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
              return React.createElement(React.Fragment, undefined, React.createElement("div", {
                              className: "card m-3",
                              style: {
                                background: "#660000",
                                width: "100%"
                              }
                            }, React.createElement("img", {
                                  className: "card-img-top",
                                  style: {
                                    height: "300px",
                                    margin: "15px",
                                    width: "300px"
                                  },
                                  alt: "...",
                                  src: broadcasterObject[/* profile_image_url */6]
                                }), React.createElement("div", {
                                  className: "card-body"
                                }, React.createElement("h5", {
                                      className: "card-title"
                                    }, broadcasterObject[/* display_name */2]), React.createElement("p", {
                                      className: "card-text"
                                    }, broadcasterObject[/* description */5]), React.createElement("table", {
                                      className: "table table-dark table-striped"
                                    }, React.createElement("thead", undefined, React.createElement("tr", undefined, React.createElement("th", {
                                                  scope: "col"
                                                }, "Engagement "), React.createElement("th", {
                                                  scope: "col"
                                                }, "Total time watching"), React.createElement("th", {
                                                  scope: "col"
                                                }, "Time in focus"), React.createElement("th", {
                                                  scope: "col"
                                                }, "Cold open percentage"))), React.createElement("tbody", undefined, React.createElement("tr", undefined, React.createElement("th", {
                                                  scope: "row"
                                                }, engagement), React.createElement("td", undefined, "4 hours, 32 minutes"), React.createElement("td", undefined, "2 hours, 23 minute (50%)"), React.createElement("td", undefined, "24.23%")))), React.createElement("a", {
                                      className: "btn btn-primary m-3",
                                      style: {
                                        background: "#FF6100",
                                        borderColor: "#FF7D2E",
                                        borderRadius: "0"
                                      },
                                      href: "#"
                                    }, "Stats for nerds"), React.createElement("a", {
                                      className: "btn btn-primary m-3",
                                      style: {
                                        background: "#FF6100",
                                        borderColor: "#FF7D2E",
                                        borderRadius: "0"
                                      },
                                      href: "#"
                                    }, "Unfollow"))));
            }),
          /* initialState */(function (param) {
              return /* record */[
                      /* data */"Lol 4Head",
                      /* advancedStatsShown */false
                    ];
            }),
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */(function (action, state) {
              if (typeof action === "number") {
                return /* Update */Block.__(0, [/* record */[
                            /* data */state[/* data */0],
                            /* advancedStatsShown */!state[/* advancedStatsShown */1]
                          ]]);
              } else if (action.tag) {
                var fetchLocation = action[0];
                return /* SideEffects */Block.__(1, [(function (_self) {
                              console.log("Error, failed to fetch data from " + (fetchLocation + "."));
                              return /* () */0;
                            })]);
              } else {
                return /* Update */Block.__(0, [/* record */[
                            /* data */action[0],
                            /* advancedStatsShown */state[/* advancedStatsShown */1]
                          ]]);
              }
            }),
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

exports.component = component;
exports.make = make;
/* component Not a pure module */