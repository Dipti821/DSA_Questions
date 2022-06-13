class Solution {
public:
    int myAtoi(string s) {
        int len=s.length();
        int ans=0,sign=1;
        int i=0;
        while(i<len && s[i]==' ')
            i++;
        if( i<len &&  s[i]=='+'){
                i++;
                sign=1;
            }
        else if( i<len && s[i]=='-'){
                i++;
                sign=-1;
            }
        
        while(i<len && isdigit(s[i]) ){
                int digit=s[i]-'0';
                
                if(ans> INT_MAX/10 || (ans== INT_MAX/10 && digit> INT_MAX%10)){
                    return sign==1?INT_MAX:INT_MIN;
                }
                ans=ans*10+digit;
                 i++;
           
        }
        return sign*ans;
    }
};