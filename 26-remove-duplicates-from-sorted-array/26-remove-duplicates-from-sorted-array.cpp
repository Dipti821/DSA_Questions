class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int sz=nums.size();
        if(sz==0)
            return 0;
        int j=0;
        // for(int i=1;i<sz;i++){
        //     if(nums[i]==nums[i-1])
        //         continue;
        //     else
        //         nums[j++]=nums[i-1];   
        // }
        // nums[j++]=nums[sz-1];
        // return j;
        for(int i=1;i<sz;i++){
            if(nums[i]!=nums[j]){
               nums[++j]=nums[i]; 
            }
        }
        return j+1;
    }
};