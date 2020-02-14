#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/stack.h"



Node * CreateNode(long data)
{
    Node * node = (Node *)malloc(sizeof(Node));
    node -> data = data;
    node -> next = NULL;
    return node;
}

Stack * CreateStack()
{
    Stack * stack = (Stack *)malloc(sizeof(Stack));
    stack -> top = NULL;
}

bool EmptyStack(Stack * stack)
{
    if(stack -> top == NULL)
    {
        return true;
    }
    return false;
}

void PushStack(Stack * stack, long data)
{
    Node * newNode = CreateNode(data);
    newNode -> next = stack -> top;
    stack -> top = newNode;
}

void PopStack(Stack * stack)
{
    if(EmptyStack(stack))
    {
        return;
    }

    Node * temp = stack -> top;
    stack -> top = stack -> top -> next;
    free(temp);
}

long TopStack(Stack * stack)
{
    if(EmptyStack(stack))
    {
        return -1;
    }
    return stack -> top -> data;
}


int main(int argc, char ** argv)
{
    Stack * stack = CreateStack();

    PushStack(stack,10);
    PushStack(stack,20);
    PushStack(stack,70);
    PushStack(stack,40);

    PopStack(stack);
    PopStack(stack);
    PopStack(stack);
    // PopStack(stack);

    if(EmptyStack(stack))
    {
        printf("Stack is Empty!\n");
    }
    else
    {
        printf("Stack Top: %ld\n", TopStack(stack));
    }


    free(stack);
    return 0;
}
