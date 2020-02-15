#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/bst.h"


Node * CreateNode(long data)
{
    Node * node = (Node *)malloc(sizeof(struct Node));
    node -> data = data;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

BST * CreateBST()
{
    BST * bst = (BST *)malloc(sizeof(struct BST));
    bst -> root = NULL;
    return bst;
}

void inorder(Node * node)
{
    if(node != NULL)
    {
        inorder(node -> left);
        printf("%ld \n", node -> data);
        inorder(node -> right);
    }
}

Node * PushBST(Node * node, long data)
{
    Node * newNode = CreateNode(data);
    if(node == NULL)
    {
        node = newNode;
        return node;
    }


    if(data < node -> data)
    {
        node -> left = PushBST(node -> left, data);
    }
    else
    {
        node -> right = PushBST(node -> right, data);
    }
    return node;
}


int main(int argc, char ** argv)
{
    BST * bst = CreateBST();
    bst -> root = PushBST(bst -> root, 10);
    PushBST(bst -> root, 20);
    PushBST(bst -> root, 40);
    PushBST(bst -> root, 5);
    PushBST(bst -> root, 12);
    PushBST(bst -> root, 14);

    inorder(bst -> root);

    free(bst);
    return 0;
}
