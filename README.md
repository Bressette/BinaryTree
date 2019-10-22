# binaryTree

Implementation of a binary tree with traversal algorithms in C

The binaryTree is defined as a struct that stores an int key and 2 pointers
to the left and right nodes from the current node

The following functions are implemented:

  - newNode(int data) creates a new node with the value that is passed into the function
  - preOrder(struct binaryTree) prints the preOrder traversal of the binary tree
  - inOrder(struct binaryTree) prints the inOrder traversal of the binary tree
  - postOrder(struct binaryTree) prints the postOrder traversal of the binary tree
  -  treeHeight(struct binaryTree) returns the height of the binary tree
  - removeTree(struct binaryTree) deletes a binary tree
  - max(int a, int b) returns the max of 2 integer numbers
  - insertNode(struct binaryTree, int newData) inserts a node to make a binary search tree
  - minTree(struct binaryTree, int min) returns the min value in a tree
  - minBST(struct binaryTree) returns the min value in a binary search tree
  - maxTree(struct binaryTree, int max) returns the max value in a tree
  - maxBST(struct binaryTree) returns the max value in a binary search tree
  - searchTree(struct binaryTree, int data) prints if the element is in the binary search tree
