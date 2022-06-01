class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        
        // TC: O(N) SC: O(N)
        int ans=0,st=0;
        unordered_map<char,int>m;
        for(int i=0;i<s.length();i++){
            if(m.find(s[i])!=m.end()){
             st=max(st,m[s[i]]+1);
            }
            ans=max(ans,i-st+1);
            m[s[i]]=i;
        }
       return ans;
    }
};