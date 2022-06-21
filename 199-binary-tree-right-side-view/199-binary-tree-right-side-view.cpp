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
    void recursion(TreeNode *root, int level, vector<int> &res)
    {
        if(root==NULL) return ;
        if(res.size()==level) res.push_back(root->val);
        recursion(root->right, level+1, res);
        recursion(root->left, level+1, res);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        // vector<int>ans;
        // if(root == NULL) return ans;
        
        // TC: O(N) ,SC: O(N) ITERATIVE SOLN
//         queue<pair<TreeNode* ,int>>q;
//         q.push({root ,0});
//         map<int,int>m;
        
//         while(!q.empty()){
//             auto it=q.front();
//             q.pop();
            
//             m[it.second]=it.first->val;
//             if(it.first->left)
//                 q.push({it.first->left ,it.second+1});
//             if(it.first->right)
//                 q.push({it.first->right ,it.second+1});
            
//         }
//         for(auto i:m)
//             ans.push_back(i.second);
        
//         return ans;
        
        // Recursive solution TC: O(N) ,SC: O(H)
        
        vector<int> res;
        recursion(root, 0, res);
        return res;
    }
};