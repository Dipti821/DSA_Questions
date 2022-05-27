class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        // if(!(next_permutation(nums.begin(),nums.end())))
        //    sort(nums.begin(),nums.end());
        
        int sz=nums.size();
        int i=sz-2;
        while(i>=0 && nums[i+1]<=nums[i])
            i--;
        
        if(i>=0){
            int j=sz-1;
            while(nums[j]<=nums[i])
                j--;
            swap(nums[i],nums[j]);
        }
        reverse(nums.begin()+i+1,nums.end());
        
    }
};