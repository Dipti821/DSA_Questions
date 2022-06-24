/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
  //        vector < int > inOrder;
  //        stack <TreeNode*> s;
  // while (true) {
  //   if (root != NULL) {
  //     s.push(root);
  //     root = root -> left;
  //     } 
  //    else {
  //     if (s.empty()) break;
  //     root = s.top();
  //     inOrder.push_back(root-> val);
  //     s.pop();
  //     root =root -> right;
  //   }
  // }
  // return inOrder;
        
        // Morris traversal
        //TC: O(N) SC:O(1)
        vector < int > inorder;

  TreeNode * cur = root;
  while (cur != NULL) {
    if (cur -> left == NULL) {
      inorder.push_back(cur -> val);
      cur = cur -> right;
    } else {
      TreeNode* prev = cur -> left;
      while (prev -> right != NULL && prev -> right != cur) {
        prev = prev -> right;
      }

      if (prev -> right == NULL) {
        prev -> right = cur;
        cur = cur -> left;
      } else {
        prev -> right = NULL;
        inorder.push_back(cur -> val);
        cur = cur -> right;
      }
    }
  }
  return inorder;
    }
};