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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;
        if(root == NULL) {
        return result;
        }

        queue <TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
          int sz = q.size();
          vector<int> row(sz);
          for (int i = 0; i < sz; i++){
          TreeNode * node = q.front();
          q.pop();

      // find position to fill node's value
          int index = (leftToRight) ? i : (sz - 1 - i);

          row[index] = node -> val;
          if(node -> left)
          q.push(node -> left);
          
          if(node -> right)
          q.push(node -> right);
      
    }
    // after this level
    leftToRight = !leftToRight;
    result.push_back(row);
  }
  return result;
    }
};