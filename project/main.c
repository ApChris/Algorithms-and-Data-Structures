#include <stdio.h>
#include <stdlib.h>
#include <time.h>



typedef struct tuple
{
    long key;
    long payload;

}tuple;

typedef struct relation
{
    tuple * tuples;
    long num_tuples;
}relation;


void swap(tuple * a, tuple * b)
{
    tuple temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

long Partition(relation * rel, long start, long end)
{
    long pivot = rel -> tuples[end].key;
    long i = start - 1;

    for (size_t j = start; j <= end - 1; j++)
    {
        if(rel -> tuples[j].key < pivot)
        {
            i++;
            swap(&(rel -> tuples[i]), &(rel -> tuples[j]));
        }
    }
    swap(&(rel -> tuples[i + 1]), &(rel -> tuples[end]));
    return (i + 1);
}

void Quicksort(relation * rel, long start, long end)
{
    if(rel == NULL)
    {
        perror("Quicksort Error!");
        exit(-1);
    }

    if(start < end)
    {
        long partition_index = Partition(rel, start, end);
        Quicksort(rel, start, partition_index - 1);
        Quicksort(rel, partition_index + 1, end);
    }
}

relation * CreateRelation()
{
    relation * rel = (relation *)malloc(sizeof(relation));
    rel -> tuples = NULL;
    rel -> num_tuples = 0;
}

typedef struct Node
{
    long key;
    long payload_A;
    long payload_B;
    struct Node * next;
}Node;


typedef struct Queue
{
    Node * front;
    Node * rear;
}Queue;


Queue * CreateQueue()
{
    Queue * queue = (Queue *)malloc(sizeof(Queue));
    queue -> front = queue -> rear = NULL;
    return queue;
}

Node * CreateNode(long key, long payload_A, long payload_B)
{
    Node * node = (Node *)malloc(sizeof(Node));
    node -> key = key;
    node -> payload_A = payload_A;
    node -> payload_B = payload_B;
    return node;
}

void PushQueue(Queue * queue, long key, long payload_A, long payload_B)
{
    Node * newNode = CreateNode(key,payload_A, payload_B);

    if(queue -> rear == NULL)
    {
        queue -> front = queue -> rear = newNode;
        return;
    }
    queue -> rear -> next = newNode;
    queue -> rear = newNode;
}

Queue * SortMergeJoin(relation * relA, relation * relB)
{
    Queue * queue = CreateQueue();
    for (size_t i = 0; i < relA -> num_tuples; i++)
    {
        for (size_t j = 0; j < relB -> num_tuples; j++)
        {
            if(relA -> tuples[i].key == relB -> tuples[j].key)
            {
                PushQueue(queue, relA -> tuples[i].key, relA -> tuples[i].payload, relB -> tuples[j].payload);
            }
        }
    }

    for (size_t i = 0; i < 3; i++)
    {
        printf("%ld) %ld\n",relA -> tuples[i].payload, relA -> tuples[i].key);
    }
    printf("\n");
    for (size_t i = 0; i < 3; i++)
    {
        printf("%ld) %ld\n",relB -> tuples[i].payload, relB -> tuples[i].key);
    }
    printf("G\n");
    return queue;
}

void PrintQueue(Queue * queue)
{
    Node * temp = queue -> front;
    while(temp != NULL)
    {
        printf("key=%ld\tpayload_A = %ld\tpayload_B = %ld\n", temp -> key, temp -> payload_A , temp -> payload_B);
        temp = temp -> next;
    }
    printf("\n");
}



relation * ReadFILE(const char * filename)
{
    FILE *file;
    long rows = 0;
    char ch;
    relation * rel = CreateRelation();
    if((file = fopen(filename,"r")) == NULL)
    {
        perror("ReadFile:");
        exit(-1);
    }

    ch = getc(file);
    for(ch = getc(file); ch != EOF; ch = getc(file))
    {
        if(ch == '\n')
        {
            rows++;
        }
    }
    rewind(file);

    // We'll create space for rows number of tuples
    if((rel -> tuples = (tuple *)malloc(rows * sizeof(tuple))) == NULL)
    {
        perror("GetColumn_FromFILE.c , first malloc\n");
        exit(-1);
    }

    long key = 0;
    long payload = 0;
    long i = 0;

    for(; i < rows; i++)
    {
        fscanf(file, "%lu,%lu",&key,&payload);
        rel -> tuples[i].key = key; // key is the value
        // rel -> tuples[i].payload = payload; // payload
    }
    // The number of tuples is the number of rows
    rel -> num_tuples = rows;

    if(fclose(file) != 0)
    {
        perror("File");
        exit(-1);
    }
}
int main(int argc, char ** argv)
{
    srand(time(NULL));

    relation * rel_A;
    rel_A = CreateRelation();
    rel_A -> tuples = (tuple *)malloc(sizeof(tuple) * 3);
    rel_A -> num_tuples = 3;
    for (size_t i = 0; i < 3; i++)
    {
        rel_A -> tuples[i].key = i + 1;
        rel_A -> tuples[i].payload = i;
        printf("%ld) %ld\n",i, rel_A -> tuples[i].key);
    }

    relation * rel_B;
    rel_B = CreateRelation();
    rel_B -> tuples = (tuple *)malloc(sizeof(tuple) * 3);
    rel_B -> num_tuples = 3;
    for (size_t i = 0; i < 3; i++)
    {
        rel_B -> tuples[i].key = i ;
        rel_B -> tuples[i].payload = i;
        printf("%ld) %ld\n",i, rel_B -> tuples[i].key);
    }


    printf("\n");
    Quicksort(rel_A,0,2);
    Quicksort(rel_B,0,2);

    for (size_t i = 0; i < 3; i++)
    {
        printf("%ld) %ld\n",rel_A -> tuples[i].payload, rel_A -> tuples[i].key);
    }
    printf("\n");
    for (size_t i = 0; i < 3; i++)
    {
        printf("%ld) %ld\n",rel_B -> tuples[i].payload, rel_B -> tuples[i].key);
    }

    printf("Sort Merge Join\n");
    Queue * queue = SortMergeJoin(rel_A, rel_B);
    printf("edw\n");
    PrintQueue(queue);
    return 0;
}
