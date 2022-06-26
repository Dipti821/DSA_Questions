class KthLargest {
    priority_queue<int>pq;
    int k1;
public:
    KthLargest(int k, vector<int>& nums) {
        k1=k;
        for(auto it: nums)
        {
            pq.push(-it);
            if(pq.size()>k){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(-val);
        if(pq.size()>k1)
        pq.pop();
        return pq.size()==k1? -pq.top(): NULL;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */