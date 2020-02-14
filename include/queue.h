#ifndef __QUEUE_H__
#define __QUEUE_H__

typedef struct Node
{
    long data;
    struct Node * next;
}Node;


typedef struct Queue
{
    Node * front;
    Node * rear;
}Queue;

Node * CreateNode(long data);
Queue * CreateQueue();
void PushQueue(Queue * queue, long data);
void PopQueue(Queue * queue);
bool EmptyQueue(Queue * queue);
#endif
