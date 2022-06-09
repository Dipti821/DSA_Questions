class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
// Time:  O(nlogk)
// Space: O(n)
// Heap solution.
        unordered_map<int, int> counts;
        for (int i = 0; i < nums.size(); ++i) {
            ++counts[nums[i]];
        }
        priority_queue<pair<int, int>> heap;
        for (auto it:counts) {
            heap.emplace(-(it.second), it.first);
            if (heap.size() == k + 1) 
                heap.pop();
        }
        vector<int> result;
        while (!heap.empty()) {
            result.emplace_back(heap.top().second);
            heap.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};