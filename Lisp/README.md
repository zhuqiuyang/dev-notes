### What made Lisp different?

http://www.paulgraham.com/diff.html

1.  Conditional
2.  function type
3.  Recursion
4.  A new concept of variables
5.  GC
6.  Programs composed of expressions
7.  a symbol type
8.  A notation for code: using tree of symbols
9.  The whole language always available:

* Running code at read-time lets users reprogram Lisp's syntax;
* running code at `compile-time` is the basis of `macros`;
  > http://wiki.c2.com/?LispMacro
  >
  > During a macroexpansion phase, transform lisp code,
  >
  > This Lisp code then is what the interpreter or compiler sees and executes or compiles.
* compiling at runtime is the basis of Lisp's use as an extension language in programs like Emacs;
* and reading at runtime enables programs to communicate using s-expressions, an idea recently reinvented as XML.

### http://wiki.c2.com/?CompileTime

> e.g. semantic LispMacros -- arbitrary Lisp code run at CompileTime (or better, ReadTime) rather than at RunTime, and in Html templates. (read-time 调用 runtime, 展开 macro 成普通 code.)

### http://wiki.c2.com/?EssExpressions

### http://www.paulgraham.com/lispfaq1.html

### http://wiki.c2.com/?VirtualMachine

### compiler

assembler language: 汇编语言
vm: A VirtualMachine is a program that translates a standard series of instruction codes into hardware specific MachineLanguage.

### http://www.tldp.org/HOWTO/Unix-and-Internet-Fundamentals-HOWTO/languages.html

11.1. Compiled languages: C
11.2. Interpreted languages: Lisp
11.3. P-code languages: python, perl, java
