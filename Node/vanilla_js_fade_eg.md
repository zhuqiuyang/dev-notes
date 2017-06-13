```javascript
var s = document.getElementById('thing').style;
s.opacity = 1;
(function fade(){(s.opacity-=.1)<0?s.display="none":setTimeout(fade,40)})();
```
