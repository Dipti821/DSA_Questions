## Problem Statement:

You have been given ‘K’ different arrays/lists, which are sorted individually (in ascending order). You need to merge all the given arrays/list such 
that the output array/list should be sorted in ascending order.

## Code:

~~~~~~
/*
    Time Complexity: O((N * K) * log(K)) 
    Space Complexity: O(N * K)
    
    Where N is the total number of elements in all the arrays, and K is the number of arrays.
*/

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    vector<int> result; 
    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > minHeap; 
  
    for (int i = 0; i < kArrays.size(); i++)
        minHeap.push({ kArrays[i][0], { i, 0 } }); 
    
  
    while (minHeap.empty() == false) 
    { 
    
        pair<int, pair<int, int> > curr = minHeap.top(); 
        minHeap.pop(); 
  
        // i is the array number and j is the index of the removed element in the ith array.
        int i = curr.second.first; 
        int j = curr.second.second; 
    
        result.push_back(curr.first); 
  
        // If the next element of the extracted element exists, add it to the heap.
        if (j + 1 < kArrays[i].size())
        {
            minHeap.push({ kArrays[i][j + 1], { i, j + 1 } }); 
        }
    } 
  
    // Return the output array.
    return result; 
}
~~~~~~

