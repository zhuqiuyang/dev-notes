### 1. Welcome to Cpp
- basic of yourself
- why?: directly control hardware, fast and performance
- java pCode run in vm vs. cpp to machine code for that platform (Linux, Mac, Windows)

### 2. SetUp on Mac
- Xcode
- MacOS-> CommandLineTool-> Cpp

### 3. How cpp Works?
- series of source file to excutable binaries(programs or Library).
- preprocess statement `#`
- `#include` find a file, take all the content of that file and paste.
- those file are used for `#include` typically called `header file`. 
- `main()`: entry point. If u don't return , will return `0` fault (only for main func) ?
- `<<` operator are just functions.
> push "hello" string to cout

```cpp  
std::out << "hello" << std::endl;
// equal
std::out.print("hell").print(std::endl);
```
- in VS two dropDown btn: `Solution configuration` & `Solution platforms` (target)
> win32 is the same as `x86` (different name)
- `header file` just include, just compile cpp file.
- Linker take all `.obj` file and stick them together.
- multipule file:
  - declaration just statement: this symbol/func exist
  > `void Log (const char* message)`
  - definition is what this func is.
- compiler just believe us `declaration`, but `Linker` to find the definition file.
  - cannot find will report link error.
  - Linker's job is to `resolve symbol`.
- compiler compile each `cpp` file to `.obj` file.

### 4. How Cpp compiler works?

#### stage1: pre-processor (get all cpp code)
1. `#include` just copy
2. `#define` CONSTANT replace
3. `#if #endif` eval

#### stage2: compile cpp code to machine code

The gist of how a compiler work:
it will take our `source files` and output and `.obj file` which contains machine code and other constant data that's we defined.
And we got these obj file, and we can `link` them into one excutable which contain all of the machine code that we actually need to run.

### 5. Linker
- entry point!
  - `.exe` has to have some kind of entry point.
- know err happen in which stage: `C` compile, `LNK` link.

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
- `err LNK2019: unresolved external symbol`: Link阶段未找到声明的symbol.
  - if not call that function, eg: `Log`, Linker will not have Link this function call to real function.

```cpp

static int Multiply(int a, int b) {
  Log("Multiply");
  return a * b;
}
```
- Err: `dublicate symbols`: include `.h` maybe causes.
> Functions or variables which have the same name and same signature.
> The reason: 
> Because Linker not know which one to link to, it's ambigulous.(歧义)
  - solution: 
    - `static`: means it's **internal**, every `.obj` file have its own version.
    - `inline`: take our actual function body and replace the code with it.
    - move the definition of this into one translation unit:
      -  `.h` just have the declaration, the actual function to link to is included inside `Log.cpp` once in one translation unit in our project.
- dynamic Linking 