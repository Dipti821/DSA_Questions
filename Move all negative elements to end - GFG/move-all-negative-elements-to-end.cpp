// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    void merge(int a[] ,int l ,int m , int r){
        int n1=m-l+1;
        int n2=r-m;
        
        int left[n1] ,right[n2];
        for(int i=0;i<n1;i++)
        left[i]=a[l+i];
        for(int i=0;i<n2;i++)
        right[i]=a[m+1+i];
        
        
        int i=0, j=0 ,k=l;
        
        while(i<n1 && left[i]>0)
        a[k++]=left[i++];
        
        while(j<n2 && right[j]>0)
        a[k++]=right[j++];
        
        while(i<n1)
        a[k++]=left[i++];
        
        while(j<n2)
        a[k++]=right[j++];
        
    }
    void RearrangeNeg(int a[] , int l ,int r){
      if(l<r){
          int m=l+(r-l)/2;
          RearrangeNeg(a , l ,m);
          RearrangeNeg(a , m+1 ,r);
          
          merge(a,l,m,r);
      }  
    }
    void segregateElements(int a[],int n)
    {
    // This solution is not optimised (modified insertion sort) TC: O(N^2) SC: O(1);
    //   int j;
    //   for(int i=0;i<n;i++){
    //       if(a[i]<0)
    //       continue;
           
    //       int temp=a[i];
    //       j=i-1;
    //       while(j>=0 && a[j]<0){
    //           a[j+1]=a[j];
    //           j--;
    //       }
    //       a[j+1]=temp;
    //   }
    
    
    // With SC: O(N) TC: O(N)
    
    // int temp[n];
    // int j=0;
    // for(int i=0;i<n;i++)
    // {
    //     if(a[i]>0)
    //     temp[j++]=a[i];
    // }
    // for(int i=0;i<n;i++)
    // {
    //     if(a[i]<0)
    //     temp[j++]=a[i];
    // }
    
    // for(int i=0;i<n;i++)
    // a[i]=temp[i];
    
    //with TC: O(N) SC: O(1)
    RearrangeNeg(a , 0, n-1);
  
    
    }
};

// { Driver Code Starts.
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}
  // } Driver Code Ends