class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int median=0;
        sort(nums.begin(),nums.end());
        
        if(nums.size()&1)
            median=nums[nums.size()/2];
        else
            median=(nums[nums.size()/2]+nums[(nums.size()/2)-1])/2;
        
        int ans=0;
        for(int i=0;i<nums.size();i++)
            ans+=abs(median-nums[i]);
        
        return ans;
    }
};