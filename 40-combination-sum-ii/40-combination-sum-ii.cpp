class Solution {
public:
    void combination(int ind ,int target, vector<int>& candidates,vector<int>& ds,vector<vector<int>>&ans){
        
        if(target==0){
           ans.push_back(ds);
            return; 
        }
        
       for(int i=ind;i<candidates.size();i++){
           if(i!=ind && candidates[i-1]==candidates[i]) continue;
           if(candidates[i]>target)break;
           
               ds.push_back(candidates[i]);
               combination(i+1,target-candidates[i],candidates,ds,ans);
               ds.pop_back();
         
       }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        sort(candidates.begin(),candidates.end());
        combination(0,target,candidates,ds,ans);
        return ans;
    }
};