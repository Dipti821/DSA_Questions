class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string>st;
        
        for(int i=k;i<=s.length();i++){
           st.insert(s.substr(i-k,k));
        }
        
            return st.size()== 1<<k;
    }
};