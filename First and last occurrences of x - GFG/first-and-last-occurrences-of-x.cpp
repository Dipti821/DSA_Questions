//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        vector<int>ans(2,-1);
        int lo=0 ,hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(arr[mid]==x && ( mid==0 || x>arr[mid-1])){
                ans[0]=mid;
                break;
            }
            else if(arr[mid]<x)
            lo=mid+1;
            else
            hi=mid-1;
        }
        
        lo=0 ,hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(arr[mid]==x && (mid==(n-1) || x<arr[mid+1])){
                ans[1]=mid;
                break;
            }
            else if(arr[mid]<=x)
            lo=mid+1;
            else
            hi=mid-1;
        }
       return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends