class Solution {
public:
    // void cal(vector<int>&nums,vector<int>&permu,vector<vector<int>>&ans,int freq[])    {
    //    if(permu.size()==nums.size()){
    //        ans.push_back(permu);
    //        return;
    //    }
    //     for(int i=0;i<nums.size();i++){
    //         if(freq[i]==0){
    //         permu.push_back(nums[i]);
    //         freq[i]=1;
    //         cal(nums,permu,ans,freq);
    //         permu.pop_back();
    //         freq[i]=0;
    //         }
    //     }
    // }
    // vector<vector<int>> permute(vector<int>& nums) {
    //     //TC: N!*N SC: O(N)+O(N)
    //     vector<vector<int>>ans;
    //     vector<int>permu;
    //     int n=nums.size();
    //     int freq[nums.size()]; 
    //     for(int i = 0;i<nums.size();i++) freq[i] = 0; 
    //     cal(nums,permu,ans,freq);
    //     return ans;
    // }
    
    // Method 2: SC: O(N) TC: O(N*N!)
      void cal(int ind, vector<int>&nums,vector<vector<int>>&ans) {
       if(ind==nums.size()){
           vector<int>permu;
           for(int i=0;i<nums.size();i++)
               permu.push_back(nums[i]);
           ans.push_back(permu);
           return;
       }
        for(int i=ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            cal(ind+1,nums,ans);
            swap(nums[ind],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        cal(0,nums,ans);
        return ans;
    }
};