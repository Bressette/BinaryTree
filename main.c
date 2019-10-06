#include "stdlib.h"
#include "stdio.h"
#include "time.h"

struct binaryTree
{
    struct binaryTree *left;
    struct binaryTree *right;
    int key;
};

//function that fills a binary tree with the amount of nodes specified in the function call



struct binaryTree *fillTree(struct binaryTree *node, int numNodes)

{
    if(numNodes <= 0)
    {
        return;
    }
    else
    {
        node = malloc(sizeof(struct binaryTree));
        node->key = rand() % 100;
        fillTree(node->left, numNodes-1);
        fillTree(node->right, numNodes-1);
    }

}

void inOrder(struct binaryTree *node)
{
    if(node->key == NULL)
        return;
    else
    {
        inOrder(node->left);
        printf("The value of key is %d", node->key);
        inOrder(node->right);
    }

}

int main()
{
    srand(time(0));
    struct binaryTree *node;
    node = fillTree(node, 5);
    fillTree(node, 5);
}
