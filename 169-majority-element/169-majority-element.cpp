class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int sz=nums.size();
      unordered_map<int , int>m;
      for(int i=0;i<sz;i++){
          m[nums[i]]++;
          if(m[nums[i]]>sz/2)
              return nums[i];
      }
        return 0;
    }
};