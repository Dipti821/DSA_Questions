class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // priority_queue<int>pq;
        // for(int i=0;i<nums.size();i++){
        //      pq.push(nums[i]); 
        //      if(pq.size()>(nums.size()-k+1))
        //         pq.pop();
        // }   
        // return pq.top();
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
        return nums[k - 1];
    }
};