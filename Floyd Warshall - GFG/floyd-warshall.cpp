// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&d){
	    // Code here
// 	Time complexity: O(N^3)
//  Space complexity: O(N^2)
int n=d.size();

	// Apply Flloyd Warshall's Algorithm.
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
			    if(d[i][k]==-1 || d[k][j]==-1)
			    continue;
			        if(d[i][j]==-1)
					d[i][j]=d[i][k] + d[k][j];
				    else if (d[i][k] != -1 && d[k][j] != -1)
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends