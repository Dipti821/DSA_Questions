## Problem Statement:

You are given an array of ‘N’ integers, you need to find the maximum of minimum for every window size. The size of the window should vary from 1 to ‘N’ only.
  
#### For example:

ARR = [1,2,3,4]

Minimums of window size 1 = min(1), min(2), min(3), min(4) = 1,2,3,4
  
Maximum among (1,2,3,4)  is 4

Minimums of window size 2 = min(1,2), min(2,3),   min(3,4) = 1,2,3
  
Maximum among (1,2,3) is 3

Minimums of window size 3 = min(1,2,3), min(2,3,4) = 1,2
  
Maximum among (1,2) is 2

Minimums of window size 4 = min(1,2,3,4) = 1
  
Maximum among them is 1
  
The output array should be [4,3,2,1].
  
  
## Code:
 ~~~~~
 
 /*
    Time Complexity: O(N)
    Space complexity: O(N)

    Where 'N' is the number elements present in the given array.
 */

#include <stack>

// This function will return an array.
// Each ith position contains the index of previous smaller elements in the original array.
vector<int> previousSmaller(vector<int> &arr, int n) 
{
    vector<int> prev(n);
    stack<int> s;

    for (int i = 0; i < n; i++) 
    {
        while (!s.empty() && arr[s.top()] >= arr[i]) 
        {
            s.pop();
        }
        
        if (s.empty()) 
        {
            prev[i] = -1;
        } 
        else 
        {
            prev[i] = s.top();
        }

        s.push(i);
    }
    
    return prev;
}

// This function will return an array.
// Each ith position contains the index of next smaller elements in the original array.
vector<int> nextSmaller(vector<int> &arr, int n) 
{
    stack<int> s;
    vector<int> next(n);

    for (int i = n - 1; i >= 0; i--) 
    {
        while (!s.empty() && arr[s.top()] >= arr[i]) 
        {
            s.pop();
        }
        
        if (s.empty()) 
        {
            next[i] = n;
        } 
        else 
        {
            next[i] = s.top();
        }
    
        s.push(i);
    }
    
    return next;
}

vector<int> maxMinWindow(vector<int> &arr, int n) 
{
    // Definition: answer[i] will store the maximum of minimum of every window of size 'i'.
    vector<int> answer(n, INT_MIN);

    // Definition: next[i] will store the index of next smaller element which lie on the right hand side of 'i'.
    vector<int> next = nextSmaller(arr, n);

    // Definition: prev[i] will store the index of previous smaller element which lie on the left hand side of 'i'.
    vector<int> prev = previousSmaller(arr, n);

    for (int i = 0; i < n; i++) 
    {
        // Length of the window in which a[i] is minimum
        int length = next[i] - prev[i] - 1;

        // Update the answer[length-1] ( 0 based indexing )  with a[i]
        answer[length - 1] = max(answer[length - 1], arr[i]);
    }

    // Some entries in answer[] may not be filled yet.
    // We fill them by taking maximum element from suffix starting from 'i'.
    for (int i = n - 2; i >= 0; i--) 
    {
        answer[i] = max(answer[i], answer[i + 1]);
    }

    return answer;
}

~~~~~

## Reference:
- [codestudio](https://www.codingninjas.com/codestudio/problems/max-of-min_982935?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0)
