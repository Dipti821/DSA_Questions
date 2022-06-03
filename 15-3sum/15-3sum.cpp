class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int sz=nums.size();
        // method 1: using 3 for loop # brute force
        // method 2: hashing
        // Method 3: sorting and using two pointers
        vector<vector<int>>ans;
        sort(nums.begin() ,nums.end());
        for(int i=0;i<sz-2;i++){
            int j=i+1,k=sz-1;
            while(j<k){
               if(nums[j]+nums[k]==-nums[i])
               {
                   vector<int>temp(3);
                   temp[0]=nums[i],temp[1]=nums[j],temp[2]=nums[k];
                   ans.push_back(temp);
                   
                   while(j<k && nums[j]==nums[j+1])
                       j++;
                   while(j<k && nums[k]==nums[k-1])
                       k--;
                   
                   j++,k--;
                       
               }
                else if(nums[j]+nums[k]>-nums[i])
                    k--;
                else
                    j++;
            }
             while(i<sz-2 && nums[i]==nums[i+1])
                       i++;
        }
        return ans;
    }
};