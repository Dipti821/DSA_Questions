## Problem Statement:

Given an array of integers A and an integer B.

Find the total number of subarrays having bitwise XOR of all elements equals to B.

### Problem Constraints
1 <= length of the array <= 105

1 <= A[i], B <= 109
  
  
## Solution:
  
  ~~~
  int Solution::solve(vector<int> &A, int B) {
    int sz=A.size();
    
    int x=0,c=0;

    // unordered_map takes O(N) TC for worst case so its safer to use map and TC: O(NlogN)
    map<int,int>m;
    for(int i=0;i<sz;i++){
        x^=A[i];
        if(x==B)
        c++;
        if(m.find(x^B)!=m.end())
        c+=m[x^ B];
        m[x]++;

    }
    return c;
}
~~~

## Time complexity:
O(NLOGN) 
  
## Space Complexity:
O(N)
  
  
