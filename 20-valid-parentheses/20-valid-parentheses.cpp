class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(st.empty()){
                st.push(s[i]);
                continue;
            }
            if(st.top()=='(' && s[i]==')'){
                st.pop();
                continue;
            }
            if(st.top()=='{' && s[i]=='}'){
                st.pop();
                continue;
            }
            if(st.top()=='[' && s[i]==']'){
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
        if(st.empty())
            return true;
        else
            return false;
        
    }
};