class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        int sz=stones.size();
        for(int i=0;i<sz;i++)
            pq.push(stones[i]);
        
        while(!pq.empty()){
            
            
            int first=pq.top();
            pq.pop();
            
            if(pq.empty())
                return first;
            int second=pq.top();
            pq.pop();
            
            if(first!=second)
                pq.push(first-second);
        }
        return 0;
    }
};