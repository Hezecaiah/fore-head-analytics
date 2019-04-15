// Generated by BUCKLESCRIPT VERSION 5.0.0, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var Fetch = require("bs-fetch/src/Fetch.js");
var React = require("react");
var Json_decode = require("@glennsl/bs-json/src/Json_decode.bs.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var LogIn$ReactTemplate = require("./views/LogIn.bs.js");
var Caml_builtin_exceptions = require("bs-platform/lib/js/caml_builtin_exceptions.js");
var Dashboard$ReactTemplate = require("./views/Dashboard.bs.js");
var JudgementPage$ReactTemplate = require("./views/JudgementPage.bs.js");

function decodeStreamer(json) {
  return /* record */[
          /* to_name */Json_decode.field("to_name", Json_decode.string, json),
          /* to_id */Json_decode.field("to_id", Json_decode.string, json),
          /* followed_at */Json_decode.field("followed_at", Json_decode.string, json)
        ];
}

function decodeUser(json) {
  return /* record */[
          /* total */Json_decode.field("total", Json_decode.$$int, json),
          /* userData */Json_decode.field("data", (function (param) {
                  return Json_decode.array(decodeStreamer, param);
                }), json)
        ];
}

function decodeJSON(json) {
  return /* record */[
          /* id */Json_decode.field("id", Json_decode.string, json),
          /* login */Json_decode.field("login", Json_decode.string, json),
          /* display_name */Json_decode.field("display_name", Json_decode.string, json),
          /* account_type */Json_decode.field("type", Json_decode.string, json),
          /* broadcaster_type */Json_decode.field("broadcaster_type", Json_decode.string, json),
          /* description */Json_decode.field("description", Json_decode.string, json),
          /* profile_image_url */Json_decode.field("profile_image_url", Json_decode.string, json),
          /* offline_image_url */Json_decode.field("offline_image_url", Json_decode.string, json),
          /* view_count */Json_decode.field("view_count", Json_decode.$$int, json)
        ];
}

function decodeData(json) {
  return /* record */[/* followData */Json_decode.field("data", (function (param) {
                  return Json_decode.array(decodeJSON, param);
                }), json)];
}

var Decode = /* module */[
  /* decodeStreamer */decodeStreamer,
  /* decodeUser */decodeUser,
  /* decodeJSON */decodeJSON,
  /* decodeData */decodeData
];

function toPage(url) {
  var match = url[/* path */0];
  if (match) {
    switch (match[0]) {
      case "dashboard" : 
          return /* Dashboard */1;
      case "judgement" : 
          if (match[1]) {
            return /* Dashboard */1;
          } else {
            return /* JudgementPage */2;
          }
      case "login" : 
          if (match[1]) {
            return /* Dashboard */1;
          } else {
            return /* LogIn */0;
          }
      default:
        return /* Dashboard */1;
    }
  } else {
    return /* Dashboard */1;
  }
}

function toUrl(page) {
  switch (page) {
    case 0 : 
        return "login";
    case 1 : 
        return "dashboard";
    case 2 : 
        return "judgement";
    
  }
}

var Mapper = /* module */[
  /* toPage */toPage,
  /* toUrl */toUrl
];

var component = ReasonReact.reducerComponent("App");

function make(_children) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */(function (self) {
              var watcherID = function (param) {
                return ReasonReact.Router[/* watchUrl */2]((function (url) {
                              return Curry._1(self[/* send */3], /* ChangeRoute */Block.__(0, [toPage(url)]));
                            }));
              };
              Curry._1(self[/* onUnmount */4], (function (param) {
                      return ReasonReact.Router[/* unwatchUrl */3](watcherID(/* () */0));
                    }));
              fetch("https://api.twitch.tv/helix/users/follows?from_id=114494398", Fetch.RequestInit[/* make */0](undefined, {
                                "Client-ID": "re6wrq92zpvgqndlc8mokgr97j09l9"
                              }, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined)(/* () */0)).then((function (prim) {
                          return prim.json();
                        })).then((function (json) {
                        var decodedJSON = decodeUser(json);
                        return Promise.resolve(Curry._1(self[/* send */3], /* SetData */Block.__(2, [decodedJSON])));
                      })).catch((function (_err) {
                      return Promise.resolve(Curry._1(self[/* send */3], /* FailedToFetch */Block.__(4, ["Twitch API"])));
                    }));
              fetch("https://api.twitch.tv/helix/users?id=26560695&id=20650414&id=22580017&id=108994872&id=132230344&id=37356443&id=44084034&id=223307755&id=51496027&id26560695&id=44019612&id=102936080&id=75574155&id=54739364&id=40603161&id=36029255&id=38865133&id=32947748&id=105566327&id=8822&id=12826", Fetch.RequestInit[/* make */0](undefined, {
                                "Client-ID": "re6wrq92zpvgqndlc8mokgr97j09l9"
                              }, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined)(/* () */0)).then((function (prim) {
                          return prim.json();
                        })).then((function (json) {
                        var decodedData = decodeData(json);
                        var decodedJSON = decodedData[/* followData */0];
                        return Promise.resolve(Curry._1(self[/* send */3], /* SetVerboseData */Block.__(3, [decodedJSON])));
                      })).catch((function (_err) {
                      return Promise.resolve(Curry._1(self[/* send */3], /* FailedToFetch */Block.__(4, ["Twitch API"])));
                    }));
              return /* () */0;
            }),
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (self) {
              var match = self[/* state */1][/* route */0];
              var match$1 = self[/* state */1][/* loggedIn */1];
              var tmp;
              switch (match) {
                case 0 : 
                    tmp = React.createElement("div", {
                          className: "d-flex justify-content-center"
                        }, React.createElement("div", {
                              className: "card d-flex flex-column justify-content-center",
                              style: {
                                background: "#660000",
                                marginTop: "50px",
                                padding: "15px"
                              }
                            }, React.createElement("h1", undefined, "Log in with your Twitch credentials."), React.createElement("form", undefined, React.createElement("div", {
                                      className: "form-group"
                                    }, React.createElement("label", {
                                          htmlFor: "username"
                                        }, "Twitch Username: "), React.createElement("input", {
                                          className: "form-control",
                                          id: "username",
                                          placeholder: "Username"
                                        })), React.createElement("div", {
                                      className: "form-group"
                                    }, React.createElement("label", {
                                          htmlFor: "password"
                                        }, "Twitch Password: "), React.createElement("input", {
                                          className: "form-control",
                                          id: "password",
                                          placeholder: "Password",
                                          type: "password"
                                        })), React.createElement("a", {
                                      className: "nav-link",
                                      style: {
                                        color: "white"
                                      },
                                      href: "dashboard",
                                      onClick: (function (_event) {
                                          return Curry._1(self[/* send */3], /* ChangeRoute */Block.__(0, [/* Dashboard */1]));
                                        })
                                    }, React.createElement("button", {
                                          className: "btn btn-primary align-self-center",
                                          style: {
                                            background: "#FF6100",
                                            borderColor: "#FF7D2E",
                                            borderRadius: "0"
                                          },
                                          type: "submit"
                                        }, "Log in")))));
                    break;
                case 1 : 
                    tmp = match$1 ? ReasonReact.element(undefined, undefined, Dashboard$ReactTemplate.make(self[/* state */1][/* followData */4], /* array */[])) : ReasonReact.element(undefined, undefined, LogIn$ReactTemplate.make(/* array */[]));
                    break;
                case 2 : 
                    tmp = match$1 ? ReasonReact.element(undefined, undefined, JudgementPage$ReactTemplate.make(self[/* state */1][/* followData */4], /* array */[])) : ReasonReact.element(undefined, undefined, LogIn$ReactTemplate.make(/* array */[]));
                    break;
                
              }
              return React.createElement("div", {
                          className: "container-fluid",
                          style: {
                            margin: "0",
                            paddingRight: "0",
                            paddingLeft: "0"
                          }
                        }, React.createElement("nav", {
                              className: "nav nav-tabs navbar navbar-expand-lg",
                              style: {
                                background: "#660000"
                              }
                            }, React.createElement("a", {
                                  className: "navbar-brand",
                                  style: {
                                    border: "2px solid #FF6100",
                                    color: "white",
                                    padding: "5px"
                                  },
                                  href: "#"
                                }, "4Head"), React.createElement("nav", {
                                  className: "nav-item",
                                  onClick: (function (_event) {
                                      return Curry._1(self[/* send */3], /* ChangeRoute */Block.__(0, [/* Dashboard */1]));
                                    })
                                }, React.createElement("a", {
                                      className: "nav-link",
                                      style: {
                                        color: "white"
                                      },
                                      href: "#"
                                    }, "Dashboard")), React.createElement("nav", {
                                  className: "nav-item",
                                  onClick: (function (_event) {
                                      return Curry._1(self[/* send */3], /* ChangeRoute */Block.__(0, [/* JudgementPage */2]));
                                    })
                                }, React.createElement("a", {
                                      className: "nav-link",
                                      style: {
                                        color: "white"
                                      },
                                      href: "#"
                                    }, "Judgement")), React.createElement("nav", {
                                  className: "nav-item",
                                  onClick: (function (_event) {
                                      return Curry._1(self[/* send */3], /* ChangeRoute */Block.__(0, [/* LogIn */0]));
                                    })
                                }, React.createElement("a", {
                                      className: "nav-link",
                                      style: {
                                        color: "white",
                                        marginLeft: "65vw"
                                      },
                                      href: "#"
                                    }, "Log In"))), tmp);
            }),
          /* initialState */(function (param) {
              return /* record */[
                      /* route */toPage(ReasonReact.Router[/* dangerouslyGetInitialUrl */4](/* () */0)),
                      /* loggedIn */true,
                      /* credentials : tuple */[
                        "",
                        ""
                      ],
                      /* userData : record */[
                        /* total */0,
                        /* userData : array */[]
                      ],
                      /* followData : array */[],
                      /* tempStr */""
                    ];
            }),
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */(function (action, state) {
              switch (action.tag | 0) {
                case 0 : 
                    var route = action[0];
                    ReasonReact.Router[/* replace */1](toUrl(route));
                    return /* Update */Block.__(0, [/* record */[
                                /* route */route,
                                /* loggedIn */state[/* loggedIn */1],
                                /* credentials */state[/* credentials */2],
                                /* userData */state[/* userData */3],
                                /* followData */state[/* followData */4],
                                /* tempStr */state[/* tempStr */5]
                              ]]);
                case 1 : 
                    throw [
                          Caml_builtin_exceptions.match_failure,
                          /* tuple */[
                            "App.re",
                            108,
                            29
                          ]
                        ];
                case 2 : 
                    return /* Update */Block.__(0, [/* record */[
                                /* route */state[/* route */0],
                                /* loggedIn */state[/* loggedIn */1],
                                /* credentials */state[/* credentials */2],
                                /* userData */action[0],
                                /* followData */state[/* followData */4],
                                /* tempStr */state[/* tempStr */5]
                              ]]);
                case 3 : 
                    return /* Update */Block.__(0, [/* record */[
                                /* route */state[/* route */0],
                                /* loggedIn */state[/* loggedIn */1],
                                /* credentials */state[/* credentials */2],
                                /* userData */state[/* userData */3],
                                /* followData */action[0],
                                /* tempStr */state[/* tempStr */5]
                              ]]);
                case 4 : 
                    var fetchLocation = action[0];
                    return /* SideEffects */Block.__(1, [(function (_self) {
                                  console.log("Error, failed to fetch data from " + (fetchLocation + "."));
                                  return /* () */0;
                                })]);
                
              }
            }),
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

exports.Decode = Decode;
exports.Mapper = Mapper;
exports.component = component;
exports.make = make;
/* component Not a pure module */
