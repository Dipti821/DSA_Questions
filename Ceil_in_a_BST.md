## Problem Statement:

Ninja is given a binary search tree and an integer. Now he is given a particular key in the tree and returns its ceil value. Can you help Ninja solve the problem?


## Code:

~~~~
 int findCeil(BinaryTreeNode<int> *root, int key){

	int ceil = -1; 
    while (root) {

        if (root->data == key) {
            ceil = root->data;
            return ceil;
        }
 
        if (key > root->data) {
            root = root->right;
        }
        else {
            ceil = root->data; 
            root = root->left;
        }
    }
    return ceil; 
}
~~~~

