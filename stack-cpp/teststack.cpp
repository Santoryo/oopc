#include "stack.h"
#include <stdlib.h>
#include <iostream>

int main()
{
  Stack s;
  
  for(int i = 0; i < 10000; i++)
  {
    s.push(i);
    std::cout << "Pushed " << i << std::endl;

    if(i % 2 == 0)
    {
      s.pop();
      std::cout << "Popped " << i << std::endl;
    }
  }

  while(!s.isEmpty())
  {
    std::cout << "Popped " << s.pop() << std::endl;
  }

  std::cout << "Peek top element: " << s.peek() << std::endl;

  return 0;
}