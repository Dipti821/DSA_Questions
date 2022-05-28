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
//         int sz=nums.size();
//         for(int i=0;i<sz;i++)
//           nums[nums[i]%sz]+=sz;
        
//         for(int i=0;i<sz;i++){
//             if(nums[i]>=2*sz)
//                 return i;
//         }
//         return 0;
    }
};