class Solution {
public:
    string longestPalindrome(string s) {
        int low=0,high=0,start=0;
        int ans=1;
        //for odd length of palindrome
        for(int i=0;i<s.length()-1;i++){
            low=high=i;
            while(low>=0 && high<s.length()){
                if(s[low]==s[high]){
                    low--;
                    high++;
                }
                else
                    break;
            }
            if(ans<(high-low-1)){
                ans=high-low-1;
                start=low+1;
            }
        }
         //for even length of palindrome
        for(int i=0;i<s.length()-1;i++){
            low=i;
            high=i+1;
            while(low>=0 && high<s.length()){
                if(s[low]==s[high]){
                    low--;
                    high++;
                }
                else
                    break;
            }
            if(ans<(high-low-1)){
                ans=high-low-1;
                start=low+1;
            }
        }
       return s.substr(start,ans); 
    }
};