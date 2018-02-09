const fs = require("fs");
const Task = require("data.task");
const R = require("rambda");

const head = xs => xs[0];
// readFile :: String -> Task Error String
const readFile = filename =>
  new Task((reject, result) => {
    fs.readFile(
      filename,
      "utf8",
      (err, data) => (err ? reject(err) : result(data))
    );
  });

readFile("package.json")
  .map(R.split("\n"))
  .map(head)

