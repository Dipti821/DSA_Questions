class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // priority_queue<int ,vector<int> ,greater<int>>pq;
        // int i=1;
        // for( ;i<heights.size();i++){
        //     if(heights[i]<=heights[i-1])
        //         continue;
        //     if(pq.size()>=ladders){
        //         pq.push(heights[i]-heights[i-1]);
        //         if(pq.top()<=bricks)
        //             bricks-=pq.top(),pq.pop();
        //         else
        //             break;
        //     }
        //     else
        //         pq.push(heights[i]-heights[i-1]);
        // }
        // return i-1;
        priority_queue<int> pq;
        for (int i = 0; i < heights.size() - 1; i++) {
            int d = heights[i + 1] - heights[i];
            if (d > 0)
                pq.push(-d);
            if (pq.size() > ladders) {
                bricks += pq.top();
                pq.pop();
            }
            if (bricks < 0)
                return i;
        }
        return heights.size() - 1;
    }
};