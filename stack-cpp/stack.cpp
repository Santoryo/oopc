#include "stack.h"

#define INITIAL_CAPACITY 2

Stack::Stack()
{
    size = 0;
    capacity = INITIAL_CAPACITY;
    int* temp = (int *)malloc(capacity * sizeof(int));
    if (temp == NULL)
    {
        free(data);
        exit(1);
    }
    else
    {
        data = temp;
    }
}

Stack::Stack(const Stack &otherStack)
{
    size = otherStack.size;
    capacity = otherStack.capacity;
    int* temp = (int *)malloc(otherStack.capacity * sizeof(int));

    if (temp == NULL)
    {
        free(data);
        exit(1);
    }
    else
    {
        data = temp;
    }

    for(int i = 0; i < size; i++)
    {
        data[i] = otherStack.data[i];
    }
}

Stack::~Stack()
{
    free(data);
}

void Stack::push(int element)
{
    if (capacity == size)
    {
        capacity *= INITIAL_CAPACITY;
        int* temp = (int *)realloc(data, capacity * sizeof(int));
        if (temp == NULL)
        {
            free(data);
            exit(1);
        }
        else
        {
            data = temp;
        }
    }
    data[size++] = element;
}

bool Stack::isEmpty()
{
    return size == 0;
}

int Stack::pop()
{
    if (isEmpty())
    {
        printf("Error, stack is empty\n");
        exit(1);
    }
    return data[--size];
}
