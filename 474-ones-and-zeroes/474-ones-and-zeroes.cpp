class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int> > dp(m + 1, vector<int>(n + 1));
        int sz=strs.size();
        
        for(int i=0;i<sz;i++){
            int one=0,zero=0;
            for(auto it : strs[i]){
                if(it=='0')
                    zero++;
                else
                    one++;
            }
            for(int i = m; i >= zero; i--)
                for(int j = n; j >= one; j--)                    
                    dp[i][j] = max(dp[i][j], dp[i - zero][j - one] + 1);

        }
    
        
        return dp[m][n];
        
    }
};