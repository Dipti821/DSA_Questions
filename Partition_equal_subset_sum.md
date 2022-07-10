## Problem Statement:

You are given an array 'ARR' of 'N' positive integers. Your task is to find if we can partition the given array into two subsets such that the sum of elements in both subsets is equal.
For example, let’s say the given array is [2, 3, 3, 3, 4, 5], then the array can be partitioned as [2, 3, 5], and [3, 3, 4] with equal sum 10.

## Code:

~~~~~~
bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
    
    int sum=0;
    for(auto it: arr)
        sum+=it;
    
    if(sum&1) return false;
    vector<bool>prev((sum/2)+1 ,0) ,curr((sum/2)+1,0);
    prev[0]=1 ,curr[0]=1;
    
    for(int ind=0;ind<n;ind++){
        for(int target=1;target<=sum/2;target++){
            bool not_take=prev[target];
            bool take=false;
            if(arr[ind]<=target)
                take=prev[target-arr[ind]];
            curr[target]=take | not_take;
        }
        prev=curr;
    }
   return prev[sum/2];
}

~~~~~~
