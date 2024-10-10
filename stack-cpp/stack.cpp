#include "stack.h"

#define INITIAL_CAPACITY 2

Stack::Stack()
{
  size = 0;
  capacity = INITIAL_CAPACITY;
  data = (int*) malloc (capacity * sizeof(int));
  if(data == NULL) exit(1);
}

Stack::Stack(const Stack& otherStack)
{
  size = otherStack.size;
  capacity = otherStack.capacity;
  data = (int *) malloc(otherStack.capacity * sizeof(int));
}

Stack::~Stack()
{
  size = 0;
  capacity = 0;
  free(data);
}

void Stack::push(int element)
{
  if(capacity == size)
  {
    capacity *= 2;
    data = (int *) realloc(data, capacity * sizeof(int));
    if(data == NULL) exit(1);
  }
  data[size++] = element;
}

bool Stack::isEmpty()
{
  return size == 0;
}

int Stack::pop()
{
  if(isEmpty())
  {
    printf("Error, stack is empty\n");
    exit(1);
  }
  return data[--size];
}

int Stack::peek()
{
  if(isEmpty()) return -1;
  return data[size];
}
