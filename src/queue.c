#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/queue.h"


Node * CreateNode(long data)
{
    Node * node = (Node *)malloc(sizeof(struct Node));
    node -> data = data;
    node -> next = NULL;
    return node;
}

Queue * CreateQueue()
{
    Queue * queue = (Queue *)malloc(sizeof(Queue));
    queue -> front = queue -> rear = NULL;
    return queue;
}

void PushQueue(Queue * queue, long data)
{
    Node * newNode = CreateNode(data);

    // If queue is empty, new node is rear and front both
    if(queue -> rear == NULL)
    {
        queue -> front = queue -> rear = newNode;
        return;
    }

    // Add new node at the end of queue and update rear pointer
    queue -> rear -> next = newNode;
    queue -> rear = newNode;

}

void PopQueue(Queue * queue)
{
    // if empty
    if(queue -> front == NULL)
    {
        return;
    }

    // stores previous front and move front one node ahead
    Node * temp = queue -> front;
    queue -> front = queue -> front -> next;

    // if front becomes null, then change rear also as null
    if(queue -> front == NULL)
    {
        queue -> rear = NULL;
    }

    free(temp);
}

bool EmptyQueue(Queue * queue)
{
    if(queue -> rear == NULL)
    {
        return true;
    }
    return false;
}

int main(int argc, char ** argv)
{
    Queue * queue = CreateQueue();

    PushQueue(queue,10);
    PushQueue(queue,20);
    PushQueue(queue,70);
    PushQueue(queue,40);

    PopQueue(queue);
    PopQueue(queue);
    PopQueue(queue);
    // PopQueue(queue);

    if(EmptyQueue(queue))
    {
        printf("Queue is Empty!\n");
    }
    else
    {
        printf("Queue Front: %ld\n", queue -> front -> data);
        printf("Queue Rear: %ld\n", queue -> rear -> data);
    }

    free(queue);

    return 0;
}
