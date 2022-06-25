## Problem Statement

Find the inorder successor in BST.

## Code:

~~~~~~
// TC: O(H) SC:O(1)
 TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* successor = NULL;
        
        while (root != NULL) {
            
            if (p->val >= root->val) {
                root = root->right;
            } else {
                successor = root;
                root = root->left;
            }
        }
        
        return successor;
    }
~~~~~~

## Reference:
- [utube](https://www.youtube.com/watch?v=SXKAD2svfmI&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=51)
