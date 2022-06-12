class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // TC: O(N)+O(N)+O(N)  SC:O(N)+O(N)+O(N)
//         stack<int>s;
//         vector<int>nsl,nsr;
        
//         for(int i=0;i<heights.size();i++){
//            while(!s.empty() && heights[s.top()]>=heights[i])
//                s.pop();
//            if(s.empty()) nsl.push_back(-1);
//            else nsl.push_back(s.top());
//            s.push(i);
//         }
//         while(!s.empty())
//         s.pop();
        
//         for(int i=heights.size()-1;i>=0;i--){
//            while(!s.empty() && heights[s.top()]>=heights[i])
//                s.pop();
//            if(s.empty()) nsr.push_back(heights.size());
//            else nsr.push_back(s.top());
//            s.push(i);
//         }
//         reverse(nsr.begin(),nsr.end());
        
//         int ans=0;
//         for(int i=0;i<heights.size();i++){
//            ans=max(ans,(nsr[i]-nsl[i]-1)*heights[i]); 
//         }
//         return ans;
        
        //TC:O(N)+O(N) SC: O(N)
      stack < int > st;
      int maxA = 0;
      int n = heights.size();
      for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
          int height = heights[st.top()];
          st.pop();
          int width;
          if (st.empty())
            width = i;
          else
            width = i - st.top() - 1;
          maxA = max(maxA, width * height);
        }
        st.push(i);
      }
      return maxA;
    }
};