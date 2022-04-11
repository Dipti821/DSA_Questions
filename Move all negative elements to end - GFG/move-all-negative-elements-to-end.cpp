// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
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
    
    
    // With auxiliary space
    int temp[n];
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>0)
        temp[j++]=a[i];
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]<0)
        temp[j++]=a[i];
    }
    
    for(int i=0;i<n;i++)
    a[i]=temp[i];
    
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