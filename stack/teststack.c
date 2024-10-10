#include "stack.h"

int main()
{
	Stack s1;
	init(&s1);
	push(&s1, 1);
	push(&s1, 3);
	push(&s1, 4);
	
	while(!isEmpty(&s1))
	{
		printf("%d\n", pop(&s1));
	}
	
	push(&s1, 9);
	pop(&s1);
	
	for(int i = 1; i < 10000; i++)
	{
		printf("Pushing %d\n", i);
		push(&s1, i * 3);
		if(i % 2 == 0 || i % 5 == 0) 
		{
			printf("Pop: %d\n", pop(&s1));
		}
	}
	
	while(!isEmpty(&s1))
	{
		printf("%d\n", pop(&s1));
	}
	
	pop(&s1);
	
	
	destroy(&s1);
}
