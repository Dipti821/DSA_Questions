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
    vector<int> postorderTraversal(TreeNode* root) {
        
        
        
        // TC: O(2*N) SC: O(N)  using one stack
//         vector < int > postOrder;
//         if(root == NULL) return postOrder;

//         stack <TreeNode*> st;
//         TreeNode* cur=root;
//         while (cur != NULL || !st.empty()) {

//         if (cur != NULL) {
//             st.push(cur);
//             cur= cur->left;
//         } 
//         else {
//         TreeNode* temp = st.top()->right;
//          if (temp == NULL) {
//             temp = st.top();
//             st.pop();
//             postOrder.push_back(temp->val);
//             while (!st.empty() && temp==st.top()->right) {
//               temp = st.top();
//               st.pop();
//               postOrder.push_back(temp -> val);
//             }
//          } 
//         else cur = temp;
//     }
//   }
        
        
        // TC: O(N)  SC: O(2*N)  using two stack
    TreeNode* curr=root;   
    vector <int> postOrder;
    if (curr == NULL) return postOrder;

    stack <TreeNode*> s1;
    stack <TreeNode*> s2;
    s1.push(curr);
  while (!s1.empty()) {
    curr = s1.top();
    s1.pop();
    s2.push(curr);
    if (curr->left != NULL)
      s1.push(curr->left);
    if (curr->right!= NULL)
      s1.push(curr -> right);
  }
  while (!s2.empty()) {
    postOrder.push_back(s2.top()->val);
    s2.pop();
  }
  return postOrder;

        
    }
};