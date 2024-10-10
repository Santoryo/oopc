#pragma once
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int size;
	int capacity;
	int* data;
} Stack;

void init(Stack* s);
void destroy(Stack* s);
void push(Stack* s, int element);
int pop(Stack* s);
bool isEmpty(const Stack* s);
