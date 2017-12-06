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