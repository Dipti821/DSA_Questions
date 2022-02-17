class Solution {
public:
    bool isPalindrome(int x) {
        bool ans=true;
        string s=to_string(x);
        int l=s.length();
        int low=0,high=l-1;
        while(low<high){
            if(s[low]!=s[high]){
                ans=false;
                break;
            }
            else{
                low++,high--;
            }
                
        }
        return ans;
    }
};