# Stack in C

Implement in C language stack of integers. Provide the following functionality:

```c
void init(Stack* s)
void destroy(Stack* s)
void push(Stack* s, int element)
int pop(Stack* s)
bool isEmpty(const Stack* s)
```

Allocate the memory dynamically. When stack capacity is not sufficient any more due to the push function calls increment the stack size. Propose reasonable strategy for how the stack size grows. Growing by one cell is not allowed (it causes memory reallocation with every push operation).
In case of an error (e.g. calling the pop function when the stack is empty) display appropriate message and quit the program.
Carefully test the implemented functionality.
Use valgrind to verify there are no memory leaks.
Split the program into Stack.h, Stack.c and TestStack.c files.
Tip: in C language it is necessary to include the stdbool.h header file to use a bool type.
Tip: in C and C++ language, to prevent a header file from being included more than once, you can use the following preprocessor directive (it is not standard, but it is recognized by many compilers, including g++ and Microsoft Visual C++):

```c
#pragma once
// ...
```

It is a convenient replacement for the following code:

```c
// MyFile.h
#ifndef _MYFILE_H_
#define _MYFILE_H_
// ...
#endif
```

*Tip: in C language it is more convenient to define structures using the typedef keyword:*

```c
typedef struct {
    // Put member variables here.
} Stack;
```

Then you do not need to specify the struct keyword later in the program. Structure types defined without the typedef keyword must be later used in the program with the struct keyword. For example declarations of the functions become longer as follows:

```c
void init(struct Stack* s)
void destroy(struct Stack* s)
void push(struct Stack* s, int element)
int pop(struct Stack* s)
bool isEmpty(const struct Stack* s)
```
