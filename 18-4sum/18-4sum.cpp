class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // Brute force
        // sort the array then use 3ptr +bs approach TC:O(N^3logN)+ O(NlogN)  SC: O(1)
        
        // Method 2: TC:O(N^3)
        
        int sz=nums.size();
        
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<sz;i++){
            for(int j=i+1;j<sz;j++){
                int rem=target-(nums[i]+nums[j]);
                int left=j+1,right=sz-1;
                while(left<right){
                    int two_sum=nums[left]+nums[right];
                    if(two_sum>rem)right--;
                    else if(two_sum<rem) left++;
                    else{
                        vector<int>temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[left]);
                        temp.push_back(nums[right]);
                        ans.push_back(temp);
                        
                        while(left<right && nums[left]==temp[2]) left++;
                        while(left<right && nums[right]==temp[3])right--;
                    }
                }
                while(j+1<sz && nums[j+1]==nums[j])j++;
                
            }
             while(i+1<sz && nums[i+1]==nums[i])i++;
        }
        return ans;
    }
};