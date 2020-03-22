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
    
    if(node == NULL)
    {
        Node * newNode = CreateNode(data);
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

Node * minvNode(Node * node)
{
    Node * current = node;
    while(current && current -> left != NULL)
    {
        current = current -> left;
    }

    return current;
}



Node * DeleteNode(Node * node, long data)
{
    if(node == NULL)
    {
        return node;
    }

    if(data < node -> data)
    {
        node -> left = DeleteNode(node -> left, data);
    }
    else if(data > node -> data)
    {
        node -> right = DeleteNode(node -> right, data);
    }
    else
    {
        if(node -> left == NULL)
        {
            Node * tmp = node -> right;
            free(node);
            return tmp;
        }
        else if(node -> right == NULL)
        {
            Node * tmp = node -> left;
            free(node);
            return tmp;
        }

        Node * tmp = minvNode(node -> right);
        node -> data = tmp -> data;

        node -> right = DeleteNode(node -> right, node -> data);

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

    DeleteNode(bst -> root, 12);
    DeleteNode(bst -> root, 14);
    DeleteNode(bst -> root, 20);
    DeleteNode(bst -> root, 5);
    DeleteNode(bst -> root, 40);


    inorder(bst -> root);

    free(bst);
    return 0;
}
