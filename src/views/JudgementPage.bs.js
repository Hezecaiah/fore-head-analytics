// Generated by BUCKLESCRIPT VERSION 5.0.0, PLEASE EDIT WITH CARE
'use strict';

var $$Array = require("bs-platform/lib/js/array.js");
var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Caml_array = require("bs-platform/lib/js/caml_array.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var BroadcasterUnfollowItem$ReactTemplate = require("../components/BroadcasterUnfollowItem.bs.js");

var component = ReasonReact.reducerComponent("Judgement");

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
              var match = self[/* state */1][/* list */0].length !== 0;
              return React.createElement("div", {
                          className: "d-flex justify-content-center"
                        }, match ? $$Array.map((function (broadcasterObject) {
                                  return ReasonReact.element(undefined, undefined, BroadcasterUnfollowItem$ReactTemplate.make((function (_event) {
                                                    return Curry._1(self[/* send */3], /* RemoveBroadcaster */[1]);
                                                  }), broadcasterObject, /* array */[]));
                                }), self[/* state */1][/* list */0]) : React.createElement("div", undefined));
            }),
          /* initialState */(function (param) {
              return /* record */[/* list : array */[
                        Caml_array.caml_array_get(data, 1),
                        Caml_array.caml_array_get(data, 14),
                        Caml_array.caml_array_get(data, 17)
                      ]];
            }),
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */(function (action, state) {
              return /* Update */Block.__(0, [/* record */[/* list : array */[
                            Caml_array.caml_array_get(data, 1),
                            Caml_array.caml_array_get(data, 17)
                          ]]]);
            }),
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

exports.component = component;
exports.make = make;
/* component Not a pure module */
