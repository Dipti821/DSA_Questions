class Solution {
public:
    string convert(string s, int numRows) {
        int len=s.length();
        int pos=numRows-1, c=0,col;
        string ans="";
        if(numRows==1 || len==1)
            return s;
        
        char a[numRows][len];
        for(int j=0;j<len;j++){
            if(c>=len){
                col=j;
                break;
            }
            if(pos==0)
                pos=numRows-1;
            if(pos==numRows-1){
                
                for(int i=0;i<numRows;i++){
                    if(c<len)
                        a[i][j]=s[c],c++;
                    else
                        a[i][j]='$';
                }
            }
            else{
                for(int i=0;i<numRows;i++){
                    if(i==pos && c<len)
                        a[i][j]=s[c],c++;
                    else
                        a[i][j]='$';
                }
            }
            pos--;
        }
        for(int i=0;i<numRows;i++){
            for(int j=0;j<col;j++){
                if(a[i][j]!='$')
                  ans+=a[i][j];                 
             }
        }
        return ans;
    }
};