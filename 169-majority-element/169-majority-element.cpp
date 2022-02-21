class Solution {
public:
    int majorityElement(vector<int>& nums) {
  
      int sz=nums.size();
//  1st Approach     TC: O(N) SC: O(N)
        
//       unordered_map<int , int>m;
//       for(int i=0;i<sz;i++){
//           m[nums[i]]++;
//           if(m[nums[i]]>sz/2)
//               return nums[i];
//       }
       
// 2nd Approach     TC: O(N) , SC:O(1)
        int maj_index = 0, count = 1;
        for (int i = 1; i < sz; i++) {
        if (nums[maj_index] == nums[i])
            count++;
        else
            count--;
        if (count == 0) {
            maj_index = i;
            count = 1;
        }
    }
    return nums[maj_index];
            
    }
};