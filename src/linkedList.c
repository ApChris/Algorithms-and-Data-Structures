#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/linkedList.h"

void PushNode(Node ** head, long data)
{
    Node * node = (Node *)malloc(sizeof(Node));

    // Set data
    node -> data = data;

    // The next pointer of new node
    node -> next = (* head);

    // Set head to point to the new node
    (*head) = node;

}

bool SearchInList(Node * head, long data)
{
    // Set current pointer to points at head
    Node * current = head;

    while(current != NULL)
    {
        if(current -> data == data)
        {
            return true;
        }
        current = current -> next;
    }
    return false;
}

long LenOfList(Node * head)
{
    long counter = 0;
    // Set current pointer to points at head
    Node * current = head;

    // for every list node
    while(current != NULL)
    {
        counter++;
        current = current -> next;
    }
    return counter;
}
void DeleteNode(Node ** head, long data)
{
    Node * current = *head , *prev;

    if(current != NULL && current )
}

int main(int argc, char const *argv[])
{
    // Holds the last node
    Node * head = NULL;
    PushNode(&head,10);
    PushNode(&head,20);
    SearchInList(head,21)? printf("True\n") : printf("False\n");
    printf("Elements: %ld\n",LenOfList(head));
    return 0;
}
