#include "stdlib.h"
#include "stdio.h"
#include "time.h"

struct binaryTree
{
    struct binaryTree *left;
    struct binaryTree *right;
    int key;
};

/*function that prints the inOrder traversal of the binary tree
 *in which first the left side of the tree is printed followed by the root
 *and then the right side of the tree
 */
void inOrder(struct binaryTree *node)
{
    if(node == NULL)
        return;
    else
    {
        inOrder(node->left);
        printf("%d ", node->key);
        inOrder(node->right);
    }

}

/*function that prints the preOrder traversal of the binary tree
 *in which first the root of the tree is printed followed by the left side
 *and then the right side of the tree
 */
void preOrder(struct binaryTree *node)
{
    if(node == NULL)
        return;
    else
    {
        printf("%d ", node->key);
        preOrder(node->left);
        preOrder(node->right);
    }
}

struct binaryTree *newNode(int data)
{
    struct binaryTree *node = malloc(sizeof(struct binaryTree));
    node->key = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

int main()
{
    srand(time(0));
    struct binaryTree *node = newNode(1);
    node->left = newNode(2);
    node->right = newNode(3);
    node->left->left = newNode(4);
    node->left->right = newNode(5);
    node->right->left = newNode(6);
    node->right->right = newNode(7);
    printf("Printing inOrder traversal\n");
    inOrder(node);
    printf("\n");
    printf("Printing preOrder traversal\n");
    preOrder(node);
    printf("\n");

}

/*The current binary tree looks like the following:
                1
            /       \
           2         3
         /   \      /  \
        4     5    6    7
*/

