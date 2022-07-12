// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        if(s.length()<p.length()) return "-1";
        
        int st=0,i=0,j=0,ans=INT_MAX,count=0;
        int ms[256]={},mp[256]={};
        
        for(auto c: p){
              mp[c]++;
        }
        
        while(j<s.length()){
            ms[s[j]]++;
            if(ms[s[j]]<=mp[s[j]])
            count++;
            
            while(count==p.length()){
               if(ans>j-i+1){
                   ans=j-i+1;
                   st=i;
               }
               ms[s[i]]--;
               if(mp[s[i]]>ms[s[i]])
               count--;
               i++;
            }
            j++;
        }
        return ans==INT_MAX?"-1":s.substr(st,ans);
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends