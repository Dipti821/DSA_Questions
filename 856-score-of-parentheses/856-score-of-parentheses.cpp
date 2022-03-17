class Solution {
public:
    stack<char>st;
    int scoreOfParentheses(string s) {
        int len=s.length();
        int ans=0,m=1;
        stack<string>st;
        for(int i=0;i<len;i++){
           if (s[i] ==  '(')
            st.push( "(");
          else {
            if (st.top() == "(") {
                st.pop();
                st.push("1");
            }
            else {
                int count = 0;
                while (st.top() !=  "(") {
                    count += stoi(st.top());
                    st.pop();
                }
                st.pop();
                st.push( to_string(2 * count));
            }
        }
        }
        while (!st.empty()) {
        ans += stoi(st.top());
        st.pop();
        }
        return ans;
    }
};