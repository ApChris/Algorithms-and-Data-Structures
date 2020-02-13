#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

typedef struct Node
{
    long data;
    struct Node * next;
}Node;


void PushNode(Node ** head, long new_data);
void PrintList(Node * node);
void DeleteNode(Node ** head, long data);
bool SearchInList(Node * head, long data);
long LenOfList(Node * head);

#endif
