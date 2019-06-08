type express;
type response;
type handler = (string, response) => unit;
[@bs.send] external get: (express, string, handler) => unit = "";
[@bs.send] external send: (response, string) => unit = "";
[@bs.send] external listen: (express, int) => unit = "";
[@bs.module] external express: unit => express = "express";

let app = express();
get(app, "/", (_, res) => send(res, "hi"));

get(app, "/hello", (_, res) => send(res, "hello"));

get(app, "/world", (_, res) => send(res, "world"));

listen(app, 9000);
Js.log("listen on port 9000");
