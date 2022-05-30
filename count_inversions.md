## Count no. of inversions in an array

For a given integer array/list 'ARR' of size 'N' containing all distinct values, find the total number of 'Inversions' that may exist.
An inversion is defined for a pair of integers in the array/list when the following two conditions are met.
A pair ('ARR[i]', 'ARR[j]') is said to be an inversion when:

1. 'ARR[i] > 'ARR[j]' 
2. 'i' < 'j'

Where 'i' and 'j' denote the indices ranging from [0, 'N').
                                                 
## Solution:
                                                   
## Approach 1: Merge sort Technique:
                                                   
The steps are as follows:

 

- The idea is similar to merge sort, divide the array from the middle to two parts, say, left sub-array and right sub-array.
- Write a logic that counts the number of inversions when the arrays, namely, left sub-array and right sub-array are merged. The idea is to have two indices or pointers. One of the pointers will refer to the left sub-array and the other one will point to the right sub-array. Let’s call them ‘LEFTINDEX’ and ‘RIGHTINDEX’ such that:
‘LEFTINDEX' < ‘RIGHTINDEX’ and
'LEFTSUBARRAY[LEFTINDEX]' > 'RIGHTSUBARRAY[RIGHTINDEX]'
- We can deduce major information from this configuration. We can say, there would be ('MID' - ‘LEFTINDEX’) inversions, where ‘MID’ is the index from where the array has been split into two. (We can say so because all the remaining elements in the left-subarray ('LEFTSUBARRAY[LEFTINDEX+ 1]', ‘LEFTSUBARRAY[LEFTINDEX+ 2]’ ….. ‘LEFTSUBARRAY[MID]’) will be greater than ‘RIGHTSUBARRAY[RIGHTINDEX]’)
Extend the same idea to calculate the number of inversions in the left sub-array and right sub-array.
                                                   
## Time Complexity
O(N * log(N)), Where ‘N’ is the total number of elements in the array. 

 

Since at each level one full array traversal is needed and there are log(N) levels as we are making each of the subarray half. Thus the time complexity will be O(N * log(N)).

## Space Complexity
O(N), Where ‘N’ is the total number of elements in the array.

 

Since we are using a temporary array of size N at each of the merge of two subarray. Thus the space complexity will be O(N).
                                                   
## Solution:
                                                   
~~~~

/*
    Time complexity : O(N * log(N))
    Space complexity : O(N)

    Where 'N' is the total number of elements in the array/list.
*/

// Function to merge the two subarrays.
long long merge(long long arr[], int left, int mid, int right){
    int i = left, j = mid, k = 0;
    long long invCount = 0;
    int temp[(right - left + 1)];

    while ((i < mid) && (j <= right)){
        if (arr[i] <= arr[j]){
            temp[k] = arr[i];
            ++k;
            ++i;
        }
        else{
            temp[k] = arr[j];
            invCount += (mid - i);
            ++k;
            ++j;
        }
    }

    while (i < mid){
        temp[k] = arr[i];
        ++k;
        ++i;
    }

    while (j <= right){
        temp[k] = arr[j];
        ++k;
        ++j;
    }

    for (i = left, k = 0; i <= right; i++, k++){
        arr[i] = temp[k];
    }

    return invCount;
}

// Function to split two subarrays and then merge them and count inversions.
long long mergeSort(long long arr[], int left, int right){
    long long invCount = 0;

    if (right > left){
        int mid = (right + left) / 2;

        /* 
            Divide the array into two parts
            total inversion count will be the
            sum of 'INVCOUNT' of left part +
            'INVCOUNT' of right part + 'INVCOUNT' of
            their combined part.
        */
        invCount = mergeSort(arr, left, mid);
        invCount += mergeSort(arr, mid + 1, right);

        // Merge both parts and count their combined inversions.
        invCount += merge(arr, left, mid + 1, right);
    }
    return invCount;
}

long long getInversions(long long arr[], int n){
    return mergeSort(arr, 0, n - 1);
}

~~~~

## Approach 2: Fenwick Tree

### Idea: 
Traverse through the array and for every index find the number of smaller elements on its right side of the array . Sum up the counts of all the indexes
in the array and print the sum.

In this approach, we will create a Fenwick tree with every element having value 0 and map the given array to get the position of every element according to sorted order and then iterate through the positions and update the Fenwick tree to 1 for every element.(As value can be very big and maybe negative so we convert array into relative ordering)


The steps are as follows:

- In the Main Function:
- Create an array “mask” in which we will store every element in the form of permutation of numbers from 1 to n having the same relative order of every element as of the original array.
For example, if your original array is {3, 22, 11, 5} then your “masked” array must be like {1, 4, 3, 2}.
- Create an array “fenwick” of size ‘n’ and initialize it to zero. Denoting that we have not encountered any element from the array and as we encounter that element we will update it to 1 by “fenwickUpdate” function.
Take a variable “answer” to store the final answer.
- Now iterate through the array “mask” from 0 to n-1(say iterator be i):
- Call the function “fenwickSum(mask[i], fenwick)” and add the value returned by this function to “answer”.
- Now call the function “fenwickUpdate(mask[i], mask.size(), fenwick).
Return “answer”.
                                                   
                                                   
- In the “fenwickSum” function:
- This function will help us to sum all the elements which are greater than the current element but have an index lower than the current index.
Take a variable “answer” in which we will keep count of those elements.
- “Index” will be the value that was passed to this function in our case it is “mask[i]”.
- While “index” is greater than 0:
Add “fenwick[index]” to “answer”.
Update “index” to “index” - (“index” & (- “index”)).
Return “Sum”.
                                                   
- In the “fenwickUpdate” function:
- In this function, we will update the values of elements that have been visited to be 1.
- Take a while loop till “index” is less than size of array:
Update “fenwick[index]” = 1.
Update “index” to “index” + (“index” & (- “index”)).
                                                   
                                                   
## Time Complexity
O( N * log( N ) ), where N is the size of the array.

 

Since we are using a Fenwick tree that updates or queries in log( N ).

Hence the total time complexity is O( N * log( N ) )

## Space Complexity
O( N ), where N is the size of the array.

 

As we are taking an array “fenwick” of size N.

Hence the total Space complexity is O( N )

## Code:
                                                   
 ~~~~ 
 /*
    Time Complexity : O(N*log(N))
    Space Complexity : O(N)

    Where, N is the size of the array.
*/

#include <vector>
#include <algorithm>
void fenwickUpdate(int index, int siz, vector<long long> &fenwick)
{
    while (index <= siz)
    {
        // Update the current element in the fenwick vector.
        fenwick[index] += 1;

        // Increase the index to the child index in the fenwick tree.
        index = index + (index & (-index));
    }
}
long long fenwickSum(int index, vector<long long> &fenwick)
{
    long long sum = 0;
    while (index > 0)
    {

        // Add the value of current node in sum.
        sum += fenwick[index];

        // Move to the parent node of the current node.
        index = index - (index & (-index));
    }
    return sum;
}

long long getInversions(long long *arr, int n) {

    // Take a 2D vector to store the sorted array and their initial index.
    vector<vector<int>> mapping(n, vector<int>(2));

    vector<long long> fenwick(n + 1, 0), mask(n);

    for (int i = 0; i < n; i++) {
        mapping[i][0] = arr[i];
        mapping[i][1] = i;
    }

    // Sort the mapping array and update all the permutations to mask vector.
    sort(mapping.begin(), mapping.end());
    for (int i = 0; i < n; i++) {
        mask[mapping[i][1]] = i + 1;
    }

    long long answer = 0;
    for (int i = n - 1; i >= 0; i--) {

        // Calculate the number of elements greater than the current element.
        answer += fenwickSum(mask[i] - 1, fenwick);

        // Update the element that has been visited.
        fenwickUpdate(mask[i], n, fenwick);
    }
    return answer;
}
                                                   
 ~~~~~ 
 
 ## Reference
 You can refer here
 
 - [Codestudio](https://www.codingninjas.com/codestudio/problems/count-inversions_615?leftPanelTab=2)
 - [gfg](https://www.geeksforgeeks.org/counting-inversions/)
 - [fenwick_tree](https://github.com/luvk1412/youtube_codes/blob/master/binary_indexed_trees/q1_rangesum.cpp)


