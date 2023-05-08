//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        
        int modulo(string s,int m)
        {
            //code here
            int ans=0;
            int p=1;
            for(int i=s.length()-1;i>=0;i--){
                ans=ans+(s[i]-'0')*p;
                p=(p*2)%m;
                ans=(ans%m);
            }
            return ans%m;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int m;
        cin>>s>>m;
        Solution a;
        cout<<a.modulo(s,m)<<endl;
    }
    return 0;
}
// } Driver Code Ends