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
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        cal(root, ans);
        return ans;
    }
    int cal(TreeNode* root ,int &ans){
        if(root==NULL)
            return 0;
       
        int l_val=max(0,cal(root->left , ans));
        int r_val=max(0,cal(root->right ,ans));
        
        ans=max(ans,l_val+r_val+root->val);
        
        
        return max(l_val,r_val)+root->val;
    }
};