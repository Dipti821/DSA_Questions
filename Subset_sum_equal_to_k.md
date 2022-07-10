## Problem Statement:

You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’. Your task is to check if there exists a subset in ‘ARR’ with a sum equal to ‘K’.
Note: Return true if there exists a subset with sum equal to ‘K’. Otherwise, return false.


## Code:

~~~~~~
// bool f(int ind ,int target , vector<int> & arr){
//     if(target==0) return true;
//     if(ind==0) return arr[0]==target;
    
//      // not pick
//     bool not_take=f(ind-1 , target , arr);
//     // pick
//     bool take=false;
//     if(target>=arr[ind])
//     take = f(ind-1 ,target-arr[ind] ,arr);
   
    
    
//     return take || not_take;
// }


// bool subsetSumToK(int n, int k, vector<int> &arr) {
//     // Write your code here.
//     return f(n-1 ,k , arr);
// }


// bool f(int ind ,int target , vector<int> & arr ,vector<vector<int>> &dp){
//     if(target==0) return true;
//     if(ind==0) return arr[0]==target;
    
//     if(dp[ind][target]!=-1) return dp[ind][target];
//      // not pick
//     bool not_take=f(ind-1 , target , arr ,dp);
//     // pick
//     bool take=false;
//     if(target>=arr[ind])
//     take = f(ind-1 ,target-arr[ind] ,arr ,dp);
   
    
    
//     return dp[ind][target] =take || not_take;
// }


// bool subsetSumToK(int n, int k, vector<int> &arr) {
//     // Write your code here.
//     vector<vector<int>> dp(n+1 ,vector<int>(k+1,-1));
    
//     return f(n-1 ,k , arr ,dp);
// }



bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<bool>> dp(n+1 ,vector<bool>(k+1,0));
    for(int i=0;i<n;i++) dp[i][0]=1;
    dp[0][arr[0]]=1;
    
    for(int ind=1; ind<n;ind++){
        for(int target=1;target<=k; target++){
             
            bool not_take=dp[ind-1][target];
            bool take=false;
            if(target>=arr[ind])
            take =dp[ind-1][target-arr[ind] ];
            dp[ind][target] =take | not_take;
        }
    }
    return dp[n-1][k];
}
~~~~~~

## Note:
We can further space optimise using prev and curr.
