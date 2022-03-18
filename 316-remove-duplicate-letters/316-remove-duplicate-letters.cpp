class Solution {
public:
    string removeDuplicateLetters(string s) {
        int sz=s.length();
        vector<int> count(26,0),vis(26,0);
        string ans="";
        
        for(int j=0;j<sz;j++)
            count[s[j]-'a']++;
        
        
         for(int i=0;i<sz;i++){
              count[s[i]-'a']--;
             
             if (!vis[s[i] - 'a']) {
            while (ans.size() > 0
                   && ans.back() > s[i]
                   && count[ans.back() - 'a'] > 0) {
                vis[ans.back() - 'a'] = 0;
                ans.pop_back();
            }
                 
            ans += s[i];
            vis[s[i] - 'a'] = 1;
              }
                  
             }
        
      return ans;
       
    }
};