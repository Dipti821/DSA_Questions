class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size(), low=0, high=n-2;
        
            while (low <= high) {
                int mid = (low + high) / 2;
                
//                 if (mid % 2 == 0) {
//                     if (nums[mid] != nums[mid + 1]) 
//                     //Checking whether we are in right half

//                         high = mid - 1; //Shrinking the right half
//                     else
//                         low = mid + 1; //Shrinking the left half
//                 } else {

//                     //Checking whether we are in right half
//                     if (nums[mid] == nums[mid + 1]) 
//                         high = mid - 1; //Shrinking the right half
//                     else
//                         low = mid + 1; //Shrinking the left half
//                 }
                  if (nums[mid] != nums[mid^1]) 
                      high = mid - 1; 
                  else
                      low = mid + 1;
            }

            return nums[low];
        
    }
};