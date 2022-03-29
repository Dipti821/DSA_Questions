class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int sz=nums.size();
        for(int i=0;i<sz;i++)
          nums[nums[i]%sz]+=sz;
        
        for(int i=0;i<sz;i++){
            if(nums[i]>=2*sz)
                return i;
        }
        return 0;
    }
};