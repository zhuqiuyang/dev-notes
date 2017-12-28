// Maybe
var Maybe = function(x) {
  this.__value = x;
};

Maybe.of = function(x) {
  return new Maybe(x);
};

Maybe.prototype.isNothing = function() {
  return this.__value === null || this.__value === undefined;
};

Maybe.prototype.map = function(f) {
  return this.isNothing() ? Maybe.of(null) : Maybe.of(f(this.__value));
};
Maybe.prototype.join = function() {
  return this.isNothing() ? Maybe.of(null) : this.__value;
}
Maybe.prototype.chain = function(f) { return this.map(f).join(); }
// IO
var IO = function(f) {
  this.__value = f;
};

IO.of = function(x) {
  return new IO(function() {
    return x;
  });
};

IO.prototype.map = function(f) {
  return new IO(R.compose(f, this.__value));
};

var io_window = new IO(function() {
  return window;
});

io_window.map(function(win) {
  return win.innerWidth;
});

console.log(
  io_window.map(function(win) {
    return win.innerWidth;
  })
);

var map = R.curry(function(f, functor) {
  return functor.map(f);
});

// //  url :: IO String
var url = new IO(function() {
  return window.location.href;
});

//  toPairs =  String -> [[String]]
const { compose, split, filter, last, head, equals } = R;
var toPairs = compose(R.map(split("=")), split("&"));

//  params :: String -> [[String]]
var params = compose(toPairs, last, split("?"));

console.log(map(params)(url).__value());
// 数组以`a`开头
console.log(filter(compose(equals("a"), head))(["a", "b"]));
//  findParam :: String -> IO Maybe [String]
var findParam = function(key) {
  return map(
    compose(Maybe.of, filter(compose(equals(key), head)), params),
    url
  );
};

console.log(findParam("a").__value());
