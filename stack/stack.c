#include "stack.h"

#define INITIAL_CAPACITY 2

void init(Stack* s)
{
	s->size = 0;
	s->capacity = INITIAL_CAPACITY;
	int* temp = (int*) malloc (INITIAL_CAPACITY * sizeof(int));
	if(temp == NULL) exit(1);
	s->data = temp;
}

void destroy(Stack* s)
{
	free(s->data);
}

void push(Stack* s, int element)
{
	if(s->capacity == s->size)
	{
		s->capacity *= 2;
		int* temp = (int*) realloc(s->data, s->capacity * sizeof(int));
		if(temp == NULL) exit(1);
		s->data = temp;
	}
	s->data[s->size++] = element;
}

int pop(Stack* s)
{
	if(isEmpty(s))
	{
		destroy(s);
		printf("Error, stack is empty\n");
		exit(1);
	}
	return s->data[--s->size];
}

bool isEmpty(const Stack* s)
{
	return s->size == 0;
}
