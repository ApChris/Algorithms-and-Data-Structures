#ifndef __BST_H_
#define __BST_H_

typedef struct Node
{
    long data;
    struct Node * left;
    struct Node * right;
}Node;

typedef struct BST
{
    Node * root;
}BST;

Node * CreateNode(long data);
BST * CreateBST();
Node * PushBST(Node * node, long data);
void inorder(Node * node);

#endif
