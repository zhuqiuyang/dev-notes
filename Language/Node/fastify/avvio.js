'use strict';

const app = require('avvio')();

app.use(first, { hello: 'world' }).after((err, cb) => {
  console.log('after first and second');
  cb();
});

app.use(third);

app.ready(function() {
  console.log('application booted!');
});

function first(instance, opts, cb) {
  console.log('first loaded', opts);
  instance.use(second);
  cb();
}

function second(instance, opts, cb) {
  console.log('second loaded');
  process.nextTick(cb);
}

// async/await or Promise support
async function third(instance, opts) {
  console.log('third loaded');
}
