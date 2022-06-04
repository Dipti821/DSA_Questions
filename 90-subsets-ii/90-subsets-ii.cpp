class Solution {
public:
    void generateSubset(int ind ,vector<int>&subset,vector<int>&nums,vector<vector<int>>&res){
        //TC: O(N(2^N)) 2^n for recursion n for copying it in ds i.e subset
        // auxiliary SC: O(N)
        // SC: O(2^N)*O(K) where k is avg. length of subset
         res.push_back(subset);
         for (int i = ind; i < nums.size(); i++) {
            if (i != ind && nums[i] == nums[i - 1]) continue;
            subset.push_back(nums[i]);
            generateSubset(i + 1,subset, nums,res);
            subset.pop_back();
         }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // Brute force : Method 1: use pick and not pick technique to generate all subsets 
        // store it in set to ignore duplicates
        
        // Method 2:
        vector<vector<int>>res;
        vector<int>subset;
        sort(nums.begin(),nums.end());
        generateSubset(0,subset,nums,res);
        return res;
    }
};