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

 /*function that returns the height of the binary tree
  *passed into the function. The base case returns -1
  *as the recursive calls will equal the height of the nodes
  *with the height of the edges being (node height)-1
  */
 int treeHeight(struct binaryTree *node)
 {
     if(node == NULL)
        return -1;

     return max(treeHeight(node->left), treeHeight(node->right)) + 1;
 }


 /*function that takes in a binary tree that will
  *be deleted. The function recursively traverses
  *through the tree in post order and frees every
  *node in the binary tree removing the tree from memory
  */
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


 /*function that compares 2 int values and
  *returns the value that is larger
  */
 int max(int a, int b)
 {
     if(a < b)
        return b;
     else
        return a;
 }


 /*function that creates a new node
  *in a normal binary search tree with
  *a value equal to the int passed into the function
  */
struct binaryTree *newNode(int data)
{
    struct binaryTree *node = malloc(sizeof(struct binaryTree));
    node->key = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}


/*function that inserts a new node into
 *a binary search tree with the node
 *sorted into the correct position dependent on
 *the value of newData
 */
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


/*function that returns the minimum
 *value in a binary tree
 */
int minTree(struct binaryTree *node, int min)
{
    if(node == NULL)
        return min;

    if(node->key <= min)
        min = node->key;
    minTree(node->left, min);
    minTree(node->right, min);

}

/*function that returns the minimum value
 *in a binary search tree
 *This function exists because it is more efficient
 *than minTree when using a binary search tree
 */
int minBST(struct binaryTree *node)
{
    struct binaryTree *temp;
    temp = node;

    while(temp->left != NULL)
        temp = temp->left;

    return temp->key;
}

/*function that returns the maximum value
 *in a binary tree
 */
int maxTree(struct binaryTree *node, int max)
{
    if(node == NULL)
        return max;

    if(node->key >= max)
        max = node->key;
    maxTree(node->left, max);
    maxTree(node->right, max);
}

/*function that returns the maximum value
 *in a binary search tree
 *This function exists because it is more efficient
 *than maxTree when using a binary search tree
 */

int maxBST(struct binaryTree *node)
{
    struct binaryTree *temp;
    temp = node;

    while(temp->right != NULL)
        temp = temp->right;

    return temp->key;
}

/*function that recursively traverses a
 *binary search tree and prints if the
 *value passed into the function is
 *present in the tree
 */
void searchTree(struct binaryTree *node, int data)
{
    if(node == NULL)
        return;
    else if(node->key == data)
        printf("%d is in the tree\n", data);
    else if(node->key < data)
        searchTree(node->right, data);
    else if(node->key > data)
        searchTree(node->left, data);

}


struct binaryTree *deleteNode(struct binaryTree *node, int data)
{
    if(node == NULL)
        return;

    if(node->key < data)
        node->right = deleteNode(node->right, data);


}



int main()
{

    //initialization of a balanced unsorted binary tree with value from 1-7
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

    //tree used for testing binary search tree functions
    struct binaryTree *bst = malloc(sizeof(struct binaryTree));
    bst = NULL;
    bst = insertNode(bst, 10);
    bst = insertNode(bst, 5);
    bst = insertNode(bst, 3);
    bst = insertNode(bst, 1);
    bst = insertNode(bst, 15);
    bst = insertNode(bst, 20);
    bst = insertNode(bst, 25);

    printf("The min value of the bst is %d\n", minBST(bst));
    printf("The max value of the bst is %d\n", maxBST(bst));

    searchTree(bst, 25);
    inOrder(bst);
    printf("\n");




}

/*The current binary tree looks like the following:
                1
            /       \
           2         3
         /   \      /  \
        4     5    6    7
*/

