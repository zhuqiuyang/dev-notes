### preset-env
Presets are sharable *.babelrc* configs or simply an array of babel plugins.
>Each yearly preset only compiles what was ratified in that year. babel-preset-env replaces es2015, es2016, es2017, latest

### transform-runtime
Externalise references to helpers and builtins, automatically polyfilling your code without polluting globals
- [why?](http://babeljs.io/docs/plugins/transform-runtime/)

### polyfill
Since Babel only transforms syntax (like arrow functions), you can use babel-polyfill in order to support new globals such as Promise or new native methods
