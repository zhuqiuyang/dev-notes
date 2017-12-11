### 8.Variables
data
- create variable, store in the memoery: stack or heap.(later how memory actually works)
- variables do occupy the memory, where we store the data in memory.
size:
- the compiler tell how big the type is.

#### Primitive data type:

`integer` is 4 byte (32 bit)
- range: -2b ~ 2b (billion), -2^31 ~ 2^31.
- 1 bit represent positive or negative.

`unsigned` means it's always positive

`char` 1 byte data
- character `A` is number `65`
```cpp
char a = 65;
cout << a
// A
short b = 65;
cout << b
// 65
```
`short` 2 byte data
`long` 4 byte data (depend on the compiler)
`long long` 8 byte

> The usage of data types is just up to the programmer really there are conventions that we have in place but there's nothing concrete that you have to actually follow there
> 
> Ther only diff between these data types is **how much memory will allocated** when you create a variable with that type.

Decimal type:

`float` 4 byte, `double` 8 byte:
```cpp
float var1 = 5.5;
// actually var1 is a double
// how to discern:
float var2 = 5.5f;
```

`bool` 1 byte: true or false
- why not 1 bit? Because we can use address.
- `0` is false, anything but `0` is true

`sizeof` can check the size(byte)

The ability turn them into pointers or references.
- pointer: write a `*`(asterisk) after your type
- reference: by a `&` (ampersand) next your type

Pointer and ref are huge and complicated and vital topics.(Later video)

### 9.Funcions
input -> output
return value
- `void` no return

```cpp
int Multiply() {
  return 5 * 8;
}

void MultiplyAndLog(int a, int b) {
  cout << Mulply(a, b); 
}
```

You should be aimed to split up your code to many many functions.
But go overboard you don't need a function for **absolute every line** of code.
That's not good for anyone.It's hard for maintain your code.

And It's make your program slower:
> Every time we call a funciton, ask compiler generates a call instruction what is basically means is that in running a program in order for us to run a fuction we need to create entire stack frame for the function meaning we have to push things like the parameters onto the stack, we have to also push something called returned address onto the stack, and then what we do is we jump to a different part of binary in in order to start executing the instructions from our funcion and that return value that we need push we need get back to where we originally were before we call the functions.So this is called like jumping around memory in order to execute function instructions and all of that takes time, so it slow down the program.

> Now the reason i said asterisk earily was because this is all assuming that the compiler decides to keep our functions as an actual function and doesn't inline it.
>
> We are going to talk about in depth inlining in a future.(*)

####  The primary point of function is to Prevent code dublication.

The main funciont and only the main function is except from `must return a value`, if it doesn't specify a return, it'll add 
```cpp
return 0;
```

Function is useful. Every program is build from a collection of functions.

####
Break up function into declarations and definitions
- declarations we usually store in header files
- definitions we write in translation unit or cpp files

### 10.header
header file are usually get included into cpp files.
`#include`
`#pragma once` means only included this file **once**. (new)
- follow `#` means it's going to be evaluated by c++ pre-processor before this file get compiled.
- prevent include a single `.h` file multiple times into a **single translation unit**(a single `cpp` file).
- do for chained `#include`.(*)

Another way: (past)
```cpp
#ifndef Log

#define Log

#endif`
```
- `#include ""` can use anywhere, add path.
- stardard library use `<>` (angular bracket)
- `#include <iostream>`
  - `iostream` is a file, just have no extension.

### 11.Debug (Move bug from u code)
Debug help you understand how program works?
1. Break Point:(pause)
- step into: step into the *current function*, that is on this line code.
- step over: step over to the next line of this code in the *current function*.
- step out : step out of *current function*. And take out back whatever call this function.

2. Looking memory:
- incredible useful.
- VS Debug Mode uninitial variable will set `0xcccc cccc`;
- watch & view memory (Xcode also can)

Remember, a program is actually made up of memory, 
even the instruction pointer which is where in our program we autually are excuting code, 
and the executing code are all store in the memory.

### 12. Conditions & Branches
- if (true) jump to certain part of source code, or another;
In the running appliaction, it's meaning machine instructions.

- check condition to jump diff portion of our memory. If u want to write fast code, not use if statement at all.In fact, a lot of optimized code specifically avoid braching, avoid each statement, will slow the program down.

- 后续有优化Branch的内容
- show `Assembly` 可以看到code对应的汇编.
```asm
; int x = 6
mov   dword ptr[x],6
; bool comparisonResult = x == 5;
cmp   dword ptr[x],5      ; load 5 to the same register
jne   main+37h (01B59B7h) ; jump if cmp equal failed
;...
;01B59B7h 

; if (comparisonResult)
movzx eax,byte ptr [comparisonResult]
test  eax, eax
je    main+5Fh            ; jump equal

; Log("HelloWorld")       ; 12:49
```
- `nullptr` or `null` is false
- make cleaner
```cpp
if (ptr)
  Log(ptr);
else if (ptr == "Hello")
  Log("Hello")
else
  Log("Ptr is null");
```

```cpp
else if () {

}
// equal
else {
  if () {

  }
}
```

Math program & Logic program
- Doing mathematics rather branches & jumps. (Fast)