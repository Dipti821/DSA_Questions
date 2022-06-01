class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sz=nums.size();
        vector<int>ans;
        int sum=0;
        for(int i=0;i<sz;i++){
            sum+=nums[i];
            ans.push_back(sum);
        }
        return ans;
    }
};