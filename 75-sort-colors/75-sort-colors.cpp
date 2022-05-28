class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        // Dutch National Flag Problem
        int sz=nums.size();
        int low_i=0,high_i=sz-1,mid=0;
        //  while(mid<=high_i){
        //     if(nums[mid]==0)
        //     {
        //         swap(nums[mid],nums[low_i]);
        //         low_i++;
        //         mid++;
        //     }
        //     else if(nums[mid]==2)
        //     {
        //         swap(nums[mid],nums[high_i]);
        //         high_i--;
        //     }
        //     else
        //         mid++;
        // }
        
        while(mid<=high_i){
            switch(nums[mid]){
                case 0: swap(nums[mid++],nums[low_i++]);
                        break;
                case 1: mid++;
                        break;
                case 2:  swap(nums[mid],nums[high_i--]);
                        break;
            }
        }
    }
};