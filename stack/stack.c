#include "stack.h"

#define INITIAL_CAPACITY 2

void init(Stack* s)
{
	s->size = 0;
	s->capacity = INITIAL_CAPACITY;
	s->data = (int*) malloc (INITIAL_CAPACITY * sizeof(int));
	if(s->data == NULL) exit(1);
}

void destroy(Stack* s)
{
	s->size = 0;
	s->capacity = 0;
	free(s->data);
}

void push(Stack* s, int element)
{
	if(s->capacity == s->size)
	{
		s->capacity *= 2;
		s->data = (int *) realloc(s->data, s->capacity * sizeof(int));
		if(s->data == NULL) exit(1);
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
