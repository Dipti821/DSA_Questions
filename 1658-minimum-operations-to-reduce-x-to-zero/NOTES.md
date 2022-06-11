1. If it exists an answer, then it means we have a subarray in the middle of original array whose sum is == totalSum - x
2. If we want to minimize our operations, then we should maximize the length of the middle subarray.
3. Then the qeustion becomes: Find the Longest Subarray with Sum Equals to TotalSum - X
4. We could simply use Map + Prefix Sum to get it!
​