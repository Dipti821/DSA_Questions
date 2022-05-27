class Solution {
public:
    vector<vector<int>> generate(int n) {
       vector<vector<int>> ans;
        vector<int> prev;
        for(int i=0;i<n;i++)
        {
            vector<int> help(i+1,1);
            if(i<=1)
                ans.push_back(help);
            else
            {
                for(int j=1;j<i;j++)
                {
                    help[j]=prev[j-1]+prev[j];
                }
                ans.push_back(help);
            }
            
            prev=help;
        }
        return ans;
    }
};