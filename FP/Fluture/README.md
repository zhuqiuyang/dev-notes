#### Future

`Future`需要`fork`后才会执行.

```js
var eventualThing = Future.of('world');
eventualThing.fork(
  console.error,
  thing => console.log(`Hello ${thing}!`)
);
//> "Hello world!"
```
