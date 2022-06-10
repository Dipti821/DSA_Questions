## Problem Statement:

Given two equally sized 1-D arrays A, B containing N integers each.

A sum combination is made by adding one element from array A and another element of array B.

Return the maximum C valid sum combinations from all the possible sum combinations.



### Problem Constraints
 1 <= N <= 105

 1 <= A[i] <= 103

 1 <= C <= N



### Input Format
First argument is an one-dimensional integer array A of size N.

Second argument is an one-dimensional integer array B of size N.

Third argument is an integer C.

### Example Input
- Input 1:

 A = [3, 2]
 B = [1, 4]
 C = 2
- Input 2:

 A = [1, 4, 2, 3]
 B = [2, 5, 1, 6]
 C = 4


### Example Output
- Output 1:

 [7, 6]
- Output 1:

 [10, 9, 9, 8]


### Example Explanation
- Explanation 1:

 7     (A : 3) + (B : 4)
 
 6     (A : 2) + (B : 4)
 
- Explanation 2:

 10   (A : 4) + (B : 6)
 
 9   (A : 4) + (B : 5)
 
 9   (A : 3) + (B : 6)
 
 8   (A : 3) + (B : 5)
 
 ## Approach:
 
### Sorting, Max heap, Map:

Instead of brute forcing through all the possible sum combinations we should find a way to limit our search space to possible candidate sum combinations.

Sort both arrays array A and array B.

Create a max heap i.e priority_queue in C++ to store the sum combinations along with the indices of elements from both arrays A and B which make up the sum. 
Heap is ordered by the sum.

Initialize the heap with the maximum possible sum combination i.e (A[N – 1] + B[N – 1] where N is the size of array) and with the indices of elements from both arrays (N – 1, N – 1). The tuple inside max heap will be (A[N-1] + B[N – 1], N – 1, N – 1). Heap is ordered by first value i.e sum of both elements.

Pop the heap to get the current largest sum and along with the indices of the element that make up the sum. Let the tuple be (sum, i, j).

Next insert (A[i – 1] + B[j], i – 1, j) and (A[i] + B[j – 1], i, j – 1) into the max heap but make sure that the pair of indices i.e (i – 1, j) and (i, j – 1) are not
already present in the max heap. To check this we can use set in C++.

Go back to 4 until K times.

Time Complexity : O(NlogN) assuming C <= N


## Code:

~~~~~

vector<int> KMaxCombinations(vector<int>& A,vector<int>& B, int K)
{
    // sort both arrays A and B
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    vector<int>ans;
    int N = A.size();

    // Max heap which contains tuple of the format
    // (sum, (i, j)) i and j are the indices
    // of the elements from array A
    // and array B which make up the sum.
    priority_queue<pair<int, pair<int, int> > > pq;

    // my_set is used to store the indices of
    // the  pair(i, j) we use my_set to make sure
    // the indices doe not repeat inside max heap.
    set<pair<int, int> > my_set;

    // initialize the heap with the maximum sum
    // combination ie (A[N - 1] + B[N - 1])
    // and also push indices (N - 1, N - 1) along
    // with sum.
    pq.push(make_pair(A[N - 1] + B[N - 1],
                      make_pair(N-1, N-1)));

    my_set.insert(make_pair(N - 1, N - 1));

    // iterate upto K
    for (int count=0; count<K; count++) {

        // tuple format (sum, (i, j)).
        pair<int, pair<int, int> > temp = pq.top();
        pq.pop();

        ans.push_back(temp.first);

        int i = temp.second.first;
        int j = temp.second.second;

        if(i-1>=0)
        {
            int sum = A[i - 1] + B[j];

        // insert (A[i - 1] + B[j], (i - 1, j))
        // into max heap.
        pair<int, int> temp1 = make_pair(i - 1, j);

        // insert only if the pair (i - 1, j) is
        // not already present inside the map i.e.
        // no repeating pair should be present inside
        // the heap.
        if (my_set.find(temp1) == my_set.end()) {
            pq.push(make_pair(sum, temp1));
            my_set.insert(temp1);
        }
        }

        // insert (A[i] + B[j - 1], (i, j - 1))
        // into max heap
        if(j-1>=0)
        {
        int sum = A[i] + B[j - 1];
        pair<int,int>temp1 = make_pair(i, j - 1);

        // insert only if the pair (i, j - 1)
        // is not present inside the heap.
        if (my_set.find(temp1) == my_set.end()) {
            pq.push(make_pair(sum, temp1));
            my_set.insert(temp1);
        }
        }
    }
    return ans;
}
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    vector<int>temp=KMaxCombinations(A,B,C);
    return temp;
}

~~~~~

## Reference:

- [interviewBit](https://www.interviewbit.com/problems/maximum-sum-combinations/hints/)
