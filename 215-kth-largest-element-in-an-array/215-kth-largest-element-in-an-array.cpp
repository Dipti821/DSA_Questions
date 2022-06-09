class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        // using heap
        
        // priority_queue<int>pq;
        // for(int i=0;i<nums.size();i++){
        //      pq.push(nums[i]); 
        //      if(pq.size()>(nums.size()-k+1))
        //         pq.pop();
        // }   
        // return pq.top();
        
        // using nth element STL
        // nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
        // return nums[k - 1];
        
        // using partial sort
         partial_sort(nums.begin(), nums.begin() + k, nums.end(), greater<int>());
        return nums[k - 1];
    }
};