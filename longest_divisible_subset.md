~~~~~~
#include<bits/stdc++.h>
using namespace std;
vector<int> divisibleSet(vector<int> &arr){
    sort(arr.begin() ,arr.end());
    int n=arr.size();
    int lastIndex=0 ,maxi=1;
    vector<int>dp(n,1) ,hash(n);
    for(int i=0;i<n;i++)
        hash[i]=i;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]%arr[j]==0 && dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
                hash[i]=j;
            }
        }
        if(dp[i]>maxi){
            maxi=dp[i];
            lastIndex=i;
        }
    }
    vector<int>ans;
    ans.push_back(arr[lastIndex]);
    while(hash[lastIndex]!=lastIndex){
        ans.push_back(arr[lastIndex]);
        lastIndex=hash[lastIndex];
    }
    return ans;
}

~~~~~~
