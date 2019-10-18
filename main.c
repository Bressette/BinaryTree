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

/*function that prints the postOrder traversal of the binary tree
 *in which first the left side of the tree is printed followed by the right
 *side of the tree and then the root of the tree
 */

 void postOrder(struct binaryTree *node)
 {
     if(node == NULL)
        return;
     else
     {
         postOrder(node->left);
         postOrder(node->right);
         printf("%d ", node->key);
     }
 }

 int treeHeight(struct binaryTree *node)
 {
     if(node == NULL)
        return -1;

     return max(treeHeight(node->left), treeHeight(node->right)) + 1;
 }

 struct binaryTree *removeTree(struct binaryTree *node)
 {
     if(node == NULL)
        return;
     else
     {
         removeTree(node->left);
         removeTree(node->right);
         printf("Deleting node %d\n", node->key);
         free(node);
     }
 }

 int max(int a, int b)
 {
     if(a < b)
        return b;
     else
        return a;
 }

struct binaryTree *newNode(int data)
{
    struct binaryTree *node = malloc(sizeof(struct binaryTree));
    node->key = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}


//function that inserts into a sorted binary tree
struct binaryTree *insertNode(struct binaryTree *node, int newData)
{
    struct binaryTree *tempNode;
    tempNode = newNode(newData);

    if(node == NULL)
    {
        node = tempNode;
        return node;
    }

    else if(newData > node->key)
        node->right = insertNode(node->right, newData);

    else if(newData < node->key)
        node->left = insertNode(node->left, newData);

}

int minTree(struct binaryTree *node, int min)
{
    if(node == NULL)
        return min;

    if(node->key <= min)
        min = node->key;
    minTree(node->left, min);
    minTree(node->right, min);

}

int maxTree(struct binaryTree *node, int max)
{
    if(node == NULL)
        return max;

    if(node->key >= max)
        max = node->key;
    maxTree(node->left, max);
    maxTree(node->right, max);
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

    printf("Printing postOrder traversal\n");
    postOrder(node);
    printf("\n");

    printf("The tree height is %d\n", treeHeight(node));

    int min = minTree(node, 100);

    printf("The value of min is %d\n", min);

    int max = maxTree(node, 0);

    printf("The value of max is %d\n", max);

    struct binaryTree *bst = malloc(sizeof(struct binaryTree));
    bst = NULL;
    bst = insertNode(bst, 1);
    bst = insertNode(bst, 10);
    bst = insertNode(bst, 15);
    bst = insertNode(bst, 20);
    bst = insertNode(bst, 5);
    bst = insertNode(bst, 3);

    inOrder(bst);
    printf("\n");

    bst = removeTree(bst);
    bst = NULL;
    bst = insertNode(bst, 1);



}

/*The current binary tree looks like the following:
                1
            /       \
           2         3
         /   \      /  \
        4     5    6    7
*/

