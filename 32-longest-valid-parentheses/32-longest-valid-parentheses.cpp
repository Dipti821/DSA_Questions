class Solution {
public:
    int longestValidParentheses(string s) {
      int sz=s.size();
        
        //METHOD 1 USING STACK
//         stack<int>st;
//         int ans=0,c=0;
//         st.push(-1);
        
//         for(int i=0;i<sz;i++){
//            if(s[i]=='('){
//                st.push(i);
//            }
//             else{
//                 st.pop();
//                 if(st.empty())
//                     st.push(i);
//                 else
//                     ans=max(ans,i-st.top());
//             }
//         }
        
        // METHOD 2 WITHOUT USING SPACE
        int l=0,r=0,ans=0;
        for(int i=0;i<sz;i++){
            if(s[i]=='(')
                l++;
            else
                r++;
            if(l==r)
                ans=max(ans,2*r);
            else if(r>l)
                l=r=0;
        }
        l=r=0;
        for(int i=sz-1;i>=0;i--){
            if(s[i]=='(')
                l++;
            else
                r++;
            if(l==r)
                ans=max(ans,2*l);
            else if(r<l)
                l=r=0;
        }
        
        return ans;
    }
};