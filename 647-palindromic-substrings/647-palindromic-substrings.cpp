class Solution {
public:
    int countSubstrings(string s) {
        int len=s.length();
        int ans=len;
        for(int i=0;i<len;i++){
            
            int st=i-1,en=i+1;
            while(st>=0 && en<len){
                if(s[st]==s[en])
                    ans++;
                else
                    break;
                st--,en++;
            }
            
            st=i,en=i+1;
            while(st>=0 && en<len){
                if(s[st]==s[en])
                    ans++;
                else
                    break;
                st--,en++;
            }
        }
        return ans;
    }
};