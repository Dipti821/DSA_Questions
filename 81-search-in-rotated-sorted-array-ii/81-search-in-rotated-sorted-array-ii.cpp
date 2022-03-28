class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int sz=nums.size();
        int lb=0,ub=sz-1;
        while(lb<=ub){
            int mid=lb+(ub-lb)/2;
            if(nums[mid]==target)
                return true;
            else if(nums[mid]>nums[lb]){
                if(nums[lb]<=target  && nums[mid]>target)
                   ub=mid-1;
                else
                   lb=mid+1;
            }
            else if(nums[mid]<nums[lb]){
                if(nums[ub]>=target  && nums[mid]<target)
                    lb=mid+1;
                else
                    ub=mid-1;
            }
            else
                lb++;
        }
        return false;
    }
};