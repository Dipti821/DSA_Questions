class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int sz=nums.size();
        int j=0;
        for(int i=1;i<sz;i++){
            if(nums[i]==nums[i-1])
                continue;
            else
                nums[j++]=nums[i-1];   
        }
        nums[j++]=nums[sz-1];
        return j;
    }
};