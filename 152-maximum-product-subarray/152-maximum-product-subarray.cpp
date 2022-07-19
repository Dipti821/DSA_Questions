class Solution {
public:
    int maxProduct(vector<int>& nums) {
         int imax,imin,ans;
         imax=imin=ans=nums[0];

     for (int i=1; i<nums.size(); i++) {
  
        if (nums[i] < 0)
            swap(imax, imin);

       
        imax = max(nums[i], imax * nums[i]);
        imin = min(nums[i], imin * nums[i]);

     
       ans=max(ans, imax);
    }
    return ans;
    }
};