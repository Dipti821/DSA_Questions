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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        
        if(root == NULL) return ans;
        
        queue<pair<TreeNode* ,int>>q;
        q.push({root ,0});
        map<int,int>m;
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            
            m[it.second]=it.first->val;
            if(it.first->left)
                q.push({it.first->left ,it.second+1});
            if(it.first->right)
                q.push({it.first->right ,it.second+1});
            
        }
        for(auto i:m)
            ans.push_back(i.second);
        
        return ans;
            
    }
};