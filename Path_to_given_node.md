## Problem Statement:

Problem Description

Given a Binary Tree A containing N nodes.

You need to find the path from Root to a given node B.

NOTE:

- No two nodes in the tree have same data values.
- You can assume that B is present in the tree A and a path always exists.
  
  ## Code:
  
~~~~~
  bool path(TreeNode *A  , vector<int>&ans ,int node){
    if(A==NULL) return false;
    ans.push_back(A->val);
    
    if(A->val==node)
    return true;
    
    if(path(A->left ,ans ,node) ||path(A->right ,ans ,node)  ) return true;
    
    ans.pop_back();
    return false;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int>ans;
    path(A,ans,B);
    return ans;
    
}

~~~~~
  
  ## Reference:
  -[InterviewBit](https://www.interviewbit.com/problems/path-to-given-node/)
  
