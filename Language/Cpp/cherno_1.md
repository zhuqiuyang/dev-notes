### 1. Welcome to Cpp

* basic of yourself
* why?: directly control hardware, fast and performance
* java pCode run in vm vs. cpp to machine code for that platform (Linux, Mac, Windows)

### 3. SetUp on Mac

* Xcode
* MacOS-> CommandLineTool-> Cpp

### 5. How cpp Works?

* series of source file to excutable binaries(programs or Library).
* preprocess statement `#`
* `#include` find a file, take all the content of that file and paste.
* those file are used for `#include` typically called `header file`.
* `main()`: entry point. If u don't return , will return `0` fault (only for main func) ?
* `<<` operator are just functions.
  > push "hello" string to cout

```cpp
std::out << "hello" << std::endl;
// equal
std::out.print("hell").print(std::endl);
```

* in VS two dropDown btn: `Solution configuration` & `Solution platforms` (target)
  > win32 is the same as `x86` (different name)
* `header file` just include, just compile cpp file.
* Linker take all `.obj` file and stick them together.
* multipule file:
  * declaration just statement: this symbol/func exist
    > `void Log (const char* message)`
  * definition is what this func is.
* compiler just believe us `declaration`, but `Linker` to find the definition file.
  * cannot find will report link error.
  * Linker's job is to `resolve symbol`.
* compiler compile each `cpp` file to `.obj` file.

### 6. How Cpp compiler works?

> text file -> application computer can run. 两块操作: compiling & linking.
>
> compiler only to do: 把 text file, convert 成 intermediate format, call `obj` file, 然后 pass to linker.

#### stage1: pre-processor (get all cpp code)

> 所有的 preprocess statement 在此被 evaluate
>
> English lang -> AST (Abstract Syntax Tree) being created
>
> AST 再 generate machine code; 再单独存储 CONSTANT data. (2min ago)

1.  `#include` just copy
2.  `#define` CONSTANT replace
3.  `#if #endif` eval

#### stage2: compile cpp code to machine code

The gist of how a compiler work:
it will take our `source files` and output and `.obj file` which contains machine code and other constant data that's we defined.
And we got these obj file, and we can `link` them into one excutable which contain all of the machine code that we actually need to run.

### 7. Linker

* entry point!
  * `.exe` has to have some kind of entry point.
* know err happen in which stage: `C` compile, `LNK` link.

```cpp
#include <iostream>

// Log signature
// default is external
void Log (const char* message)
// static Log (const char* message)
// inline Log (const char* message)

int Multiply(int a, int b) {
  Log("Multiply");
  return a * b;
}

int main () {
  std::cout << Multiply(5, 8) << std::endl;
  std::cin.get();
}
```

* `err LNK2019: unresolved external symbol`: Link 阶段未找到声明的 symbol.
  * if not call that function, eg: `Log`, Linker will not have Link this function call to real function.

```cpp
static int Multiply(int a, int b) {
  Log("Multiply");
  return a * b;
}
```

* Err: `dublicate symbols`: include `.h` maybe causes.
  > Functions or variables which have the same name and same signature.
  > The reason:
  > Because Linker not know which one to link to, it's ambigulous.(歧义)
  * solution:
    * `static`: means it's **internal**, every `.obj` file have its own version.
    * `inline`: take our actual function body and replace the code with it.
    * move the definition of this into one translation unit:
      * `.h` just have the declaration, the actual function to link to is included inside `Log.cpp` once in one translation unit in our project.
* dynamic Linking

### 8.Variables

data

* create variable, store in the memoery: stack or heap.(later how memory actually works)
* variables do occupy the memory, where we store the data in memory.
  size:
* the compiler tell how big the type is.

#### Primitive data type:

`integer` is 4 byte (32 bit)

* range: -2b ~ 2b (billion), -2^31 ~ 2^31.
* 1 bit represent positive or negative.

`unsigned` means it's always positive

`char` 1 byte data

* character `A` is number `65`

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

* why not 1 bit? Because we can use address.
* `0` is false, anything but `0` is true

`sizeof` can check the size(byte)

The ability turn them into pointers or references.

* pointer: write a `*`(asterisk) after your type
* reference: by a `&` (ampersand) next your type

Pointer and ref are huge and complicated and vital topics.(Later video)

### 9.Funcions

input -> output
return value

* `void` no return

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
> We are going to talk about in depth inlining in a future.(\*)

#### The primary point of function is to Prevent code dublication.

The main funciont and only the main function is except from `must return a value`, if it doesn't specify a return, it'll add

```cpp
return 0;
```

Function is useful. Every program is build from a collection of functions.

####

Break up function into declarations and definitions

* declarations we usually store in header files
* definitions we write in translation unit or cpp files

### 10.header

header file are usually get included into cpp files.
`#include`
`#pragma once` means only included this file **once**. (new)

* follow `#` means it's going to be evaluated by c++ pre-processor before this file get compiled.
* prevent include a single `.h` file multiple times into a **single translation unit**(a single `cpp` file).
* do for chained `#include`.(\*)

Another way: (past)

```cpp
#ifndef Log

#define Log

#endif`
```

* `#include ""` can use anywhere, add path.
* stardard library use `<>` (angular bracket)
* `#include <iostream>`
  * `iostream` is a file, just have no extension.
