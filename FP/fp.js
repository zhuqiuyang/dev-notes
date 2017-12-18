class Functor {
  constructor(val) { 
    this.val = val; 
  }

  map(f) {
    return new Functor(f(this.val));
  }
  static of(val) {
    return new Functor(val);
  }
}

class Monad {
  constructor(val) { 
    this.val = val; 
  }
  map(f) {
    return new Monad(f(this.val));
  }
  join() {
    return this.val;
  }
  flatMap(f) {
    return this.map(f).join();
  }

  static of(val) {
    return new Monad(val);
  }
}

const a = Monad.of(2)
a.flatMap(x=>x+2)

// Functor.of = function(val) {
//   return new Functor(val);
// };