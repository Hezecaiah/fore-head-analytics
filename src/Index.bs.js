// Generated by BUCKLESCRIPT VERSION 5.0.0, PLEASE EDIT WITH CARE
'use strict';

var ReactDOMRe = require("reason-react/src/ReactDOMRe.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var App$ReactTemplate = require("./App.bs.js");
var Component1$ReactTemplate = require("./components/Component1.bs.js");
var Component2$ReactTemplate = require("./components/Component2.bs.js");
var MyComponent$ReactTemplate = require("./components/MyComponent.bs.js");

ReactDOMRe.renderToElementWithId(ReasonReact.element(undefined, undefined, App$ReactTemplate.make(/* array */[])), "app");

ReactDOMRe.renderToElementWithId(ReasonReact.element(undefined, undefined, Component1$ReactTemplate.make("Hello! Click this text.", /* array */[])), "index1");

ReactDOMRe.renderToElementWithId(ReasonReact.element(undefined, undefined, Component2$ReactTemplate.make("Hello", /* array */[])), "index2");

ReactDOMRe.renderToElementWithId(ReasonReact.element(undefined, undefined, MyComponent$ReactTemplate.make(/* array */[])), "index3");

/*  Not a pure module */
