class Solution {
public:
    void combination(int ind ,int target, vector<int>& candidates,vector<int>& ds,vector<vector<int>>&ans){
        if(ind==candidates.size())
        {
            if(target==0) ans.push_back(ds);
            return;
        }
        // picked up
        if(candidates[ind]<=target){
        ds.push_back(candidates[ind]);
        combination(ind,target-candidates[ind],candidates,ds,ans);
        ds.pop_back();
        }
        // not picked
        combination(ind+1,target,candidates,ds,ans);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        combination(0,target,candidates,ds,ans);
        return ans;
    }
};
