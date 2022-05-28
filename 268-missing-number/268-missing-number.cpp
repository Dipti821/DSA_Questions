class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sz=nums.size();
        long long sum=0;
        long long total=sz*(sz+1)/2;
        
        for(int i=0;i<sz;i++)
            sum+=nums[i];
        
        return total-sum;
    }
};