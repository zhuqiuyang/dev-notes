### 11.Debug (Move bug from u code)

Debug help you understand how program works?

1.  Break Point:(pause)

* step into: step into the _current function_, that is on this line code.
* step over: step over to the next line of this code in the _current function_.
* step out : step out of _current function_. And take out back whatever call this function.

2.  Looking memory:

* incredible useful.
* VS Debug Mode uninitial variable will set `0xcccc cccc`;
* watch & view memory (Xcode also can)

Remember, a program is actually made up of memory,
even the instruction pointer which is where in our program we autually are excuting code,
and the executing code are all store in the memory.

### 12. Conditions & Branches

* if (true) jump to certain part of source code, or another;
  In the running appliaction, it's meaning machine instructions.

* check condition to jump diff portion of our memory. If u want to write fast code, not use if statement at all.In fact, a lot of optimized code specifically avoid braching, avoid each statement, will slow the program down.

* 后续有优化 Branch 的内容
* show `Assembly` 可以看到 code 对应的汇编.

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

* `nullptr` or `null` is false
* make cleaner

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

* Doing mathematics rather branches & jumps. (Fast)

### 16. POINTERS in C++

> wall pointer ? ,not smart pointer.
>
> Nothing you can do , if without Memory.
>
> Pointer 对于 manerge 和 manipulate memory 十分重要.

**`Pointer` just a Interge, which hold a `memory address`(one byte). 和 type 完全无关. (\*)**

* `void* ptr`: 暂时只需要一个 address, 不关心其将指向的 type.(04:40)
  > 下面三种是相同的.

```cpp
void* ptr = 0;
// #define NULL 0
void* ptr = NULL;
// cpp 独有的
void* ptr = nullptr;
```

* `&`: means give me your memory address:

```cpp
int main () {
  int var = 8;
  void* ptr = &var;
  std::cin.get();
}

int main() {
  int var = 8;
  double* ptr =(double*)&var;
}
```

* `*ptr`: dereference that pointer, which means I now access the data (读或写).

`int* ptr`: 只是 adress 内 data 的所存 type.

#### heap

```cpp
int main () {
  char* buffer = new char[8];
  memset(buffer, 0, 8);

  delete[] buffer;
  std::cin.get();
}
```

* allocate 8 byte `memeory` for us
* point to the `beginning` of the memory

#### pointer to pointer

```cpp
int main () {
  char* buffer = new char[8];
  memset(buffer, 0, 8);

  char** ptr = &buffer;

  delete[] buffer;
  std::cin.get();
}
```
