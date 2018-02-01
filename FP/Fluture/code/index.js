const fs = require("fs");
const Future = require("fluture");

const getPackageName = function(file) {
  return Future.node(done => {
    fs.readFile(file, "utf8", done);
  })
    .chain(Future.encase(JSON.parse))
    .map(function(x) {
      return x.name;
    });
};

getPackageName("package.json").fork(console.error, console.log);
//> "fluture"

const eventualThing = Future.of("world");
eventualThing.fork(console.error, thing => console.log(`Hello ${thing}!`));
