// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    void SubsetSum(int idx ,int sum ,vector<int> & arr ,vector<int> &res){
        if(idx==arr.size()){
            res.push_back(sum);
            return;
        }
        // pick the element
        SubsetSum(idx+1 ,sum+arr[idx] ,arr ,res);
        // don't pick the element
        SubsetSum(idx+1,sum,arr,res);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        // Brute force:  generate all subset using powerset TC: O(N(2^N))
         vector<int>res;
         SubsetSum(0,0,arr,res);
         sort(res.begin(), res.end());
         return res;
         
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends