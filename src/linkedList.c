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
    Node * tmp = *head;
    Node * prev;

    if(tmp != NULL && tmp -> data == data)
    {
        // change head
        *head = tmp -> next;
        free(tmp);
        return;
    }

    // Search for the data to be deleted
    while(tmp != NULL && tmp -> data != data)
    {
        prev = tmp;
        tmp = tmp -> next;
    }

    // if data doesn't exist in ll
    if(tmp == NULL)
    {
        return;
    }
    // unlink the node from ll
    prev -> next = tmp -> next;

    free(tmp);
}

void Reverse(Node ** head)
{
    Node * prev = NULL;
    Node * current = *head;
    Node * next = NULL;

    while(current != NULL)
    {
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void PrintList(Node ** head)
{
    Node * tmp = *head;
    while(tmp != NULL)
    {
        printf("%ld ", tmp -> data);
        tmp = tmp -> next;
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    // Holds the last node
    Node * head = NULL;
    PushNode(&head,10);
    PushNode(&head,20);
    SearchInList(head,21)? printf("True\n") : printf("False\n");
    // DeleteNode(&head,10);

    PrintList(&head);
    Reverse(&head);
    PrintList(&head);

    printf("Elements: %ld\n",LenOfList(head));

    free(head);
    return 0;
}
