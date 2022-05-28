class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int sz=nums.size();
       while(true){
           
            // Efficient approach arrays as hash maps
            if(nums[nums[0]]!=nums[0])
                swap(nums[0],nums[nums[0]]);
            else
               return nums[0];
        }
    }
};