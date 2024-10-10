# Stack in C++
Implement functionality from the previous exercise in C++ language writing the Stack class. Replace init and destroy functions by constructor and destructor, respectively.
In C++ language you can use malloc and free functions for memory allocation as you do it in C language (new and delete operators will be explained later during the semester).
Carefully test the implemented functionality.
Use valgrind to verify there are no memory leaks.
Split the program into Stack.h, Stack.cpp and TestStack.cpp files.

## Additional task - Extended Stack

 Extend the previous task by implementing the following functionality:

- copy constructor
- assignment operator

Optimize the assignment operator, so it does not unnecessarily free nor allocate memory.
Carefully test the implemented functionality. Consider different test cases. For example, when testing the assignment operator consider assigning larger stack to smaller stack, assigning smaller stack to larger one, calling the assignment operator when both stacks have equal size, calling the assignment operator when one of the stacks is empty, assigning the stack to itself etc.
Use valgrind to verify there are no memory leaks.

Perform all the steps of the GDB tutorial to learn how to use the debugger.
Using the debugger check when the copy constructor and the assignment operator are called in your program. Consider the following cases:

```cpp
Stack s1;
s1.push(1);
s1.push(2);
s1.push(3);

Stack s2(s1);

Stack s3 = s1;

Stack s4;
s4.push(10);
s4 = s1;

runFunction1(s1);    // Stack object is passed by value.
runFunction2(s1);    // Stack object is passed by reference.
```
