#include "stack.h"
#include <stdlib.h>
#include <iostream>


void fillStack(Stack& s, int n)
{
  for(int i = 0; i < n; i++)
  {
    s.push(i);
  }

  printf("Filled stack with %d elements\n", n);
  s.print();
}

int main()
{
  Stack s;
  fillStack(s, 10);

  printf("\nTesting copy operator\n\n");
  Stack s2 = s;
  printf("s: ");
  s.print();
  printf("s2: ");
  s2.print();

  printf("\nTesting assignment operator while other Stack is smaller \n\n");
  Stack s3;
  fillStack(s3, 5);
  s3 = s;
  printf("s: ");
  s.print();
  printf("s3: ");
  s3.print();

  printf("\nTesting assignment operator while other Stack is bigger \n\n");
  fillStack(s3, 15);
  s3 = s;
  printf("s3: ");
  s3.print();
  printf("s: ");
  s.print();

  return 0;
}
