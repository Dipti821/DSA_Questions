class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int len=coins.size();
        vector<int> dp(amount+1);
        dp[0]=0;
        for(int i=1;i<=amount;i++)
            dp[i]=INT_MAX;
        
         for(int i=1;i<=amount;i++){
             for(int j=0;j<len;j++){
               if(coins[j]<=i)
               {
                   if(dp[i-coins[j]]!=INT_MAX && dp[i-coins[j]]+1<dp[i] )
                       dp[i]=dp[i-coins[j]]+1;
               }
    }
  }
        if(dp[amount]==INT_MAX)
            return -1;
        else
      return dp[amount];

    }
};

