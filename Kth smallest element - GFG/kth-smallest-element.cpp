// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int partition(int arr[] , int l , int r){
        int j=l,x=arr[r];
        for(int i=l;i<r;i++){
            if(arr[i]<=x)
            {
                swap(arr[i] , arr[j]);
                j++;
            }
        }
        swap(arr[j] , arr[r]);
        return j;
    }
    int rpartition(int arr[] , int l , int r){
        int pivot=rand()%(r-l+1);
        swap(arr[pivot+l], arr[r]);
        partition(arr, l ,r);
    }
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        // sort(arr,arr+r+1);
        // return arr[k-1];
        
        // returning kth smallest element using quicksort method since elements are distinct
        // Time Complexity : O(N) average
        
        
        // We can also do it by heap data structure
        if(k>0 && k<=(r-l+1)){
            
            int pos=rpartition(arr, l, r);
            
            if(pos-l==(k-1))
            return arr[pos];
            
            if(pos-l>(k-1)){
                return kthSmallest(arr , l , pos-1 , k);
            }
            else
            return kthSmallest(arr , pos+1 , r , k-pos+l-1);
        }
        
    }
};

// { Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends