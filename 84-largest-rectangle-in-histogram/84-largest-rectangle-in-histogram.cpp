class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>s;
        vector<int>nsl,nsr;
        
        for(int i=0;i<heights.size();i++){
           while(!s.empty() && heights[s.top()]>=heights[i])
               s.pop();
           if(s.empty()) nsl.push_back(-1);
           else nsl.push_back(s.top());
           s.push(i);
        }
        while(!s.empty())
        s.pop();
        
        for(int i=heights.size()-1;i>=0;i--){
           while(!s.empty() && heights[s.top()]>=heights[i])
               s.pop();
           if(s.empty()) nsr.push_back(heights.size());
           else nsr.push_back(s.top());
           s.push(i);
        }
        reverse(nsr.begin(),nsr.end());
        
        int ans=0;
        for(int i=0;i<heights.size();i++){
           ans=max(ans,(nsr[i]-nsl[i]-1)*heights[i]); 
        }
        return ans;
    }
};