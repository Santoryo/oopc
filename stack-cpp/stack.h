#pragma once
#include <stdio.h>
#include <stdlib.h>

class Stack {
  private:
    int size;
    int capacity;
    int* data;
  public:
    void push(int element);
    int pop();
    bool isEmpty();
    int peek();
    Stack();
    ~Stack();
};