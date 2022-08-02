class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        // TC: O(N^2) SC: O(N)
//         int n = nums.size();
//         vector<int> dp(n, 1);
//         for (int i = 0; i < n; ++i)
//             for (int j = 0; j < i; ++j)
//                 if (nums[i] > nums[j] && dp[i] < dp[j] + 1)
//                     dp[i] = dp[j] + 1;
//         return *max_element(dp.begin(), dp.end());
        
        
        // Binary Search
        // TC: O(N log N) SC: O(N)
        
    int n=nums.size();    
    vector<int> temp;
    temp.push_back(nums[0]);
    
    int len = 1;
    
    for(int i=1; i<n; i++){
        if(nums[i]>temp.back()){
           // arr[i] > the last element of temp array 
           
           temp.push_back(nums[i]);
           len++;
           
        } 
        else{
           // replacement step
            int ind = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();
            temp[ind] = nums[i];
        }
        
    }
    
    return len;
    }
};