class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       int sz=strs.size();
       
       int min_length=strs[0].length();
        for(int i=1;i<sz;i++){
            if(strs[i].length()<min_length)
                min_length=strs[i].length();
        }
        string ans="";
       
        
        for(int i=0;i<min_length;i++){
            char ch=strs[0][i];
            for(int j=1;j<sz;j++){
                if(ch!=strs[j][i])
                    return ans;   
            }
             ans+=ch;
        }
        return ans;
        
    }
};