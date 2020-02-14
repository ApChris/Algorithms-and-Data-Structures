#ifndef __STACK_H__
#define __STACK_H__

typedef struct Node
{
    long data;
    struct Node * next;
}Node;

typedef struct Stack
{
    Node * top;
}Stack;

Stack * CreateStack();
Node * CreateNode(long data);
void PushStack(Stack * stack, long data);
void PopStack(Stack * stack);

#endif
