class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
//         int sz=nums.size();
//         int dp[sz];
//         dp[0]=nums[0];
        
//         for(int i=1;i<sz;i++){
//             dp[i]=-1e8;
//             for(int j=1;j<=k && i-j>=0;j++){
//                 dp[i]=max(dp[i],dp[i-j]);
//             }
//             dp[i]+=nums[i];
//         }
//         return dp[sz-1];
        
          long curr=0;
          deque<int> dq;     	
		
        for(int i=nums.size()-1;i>=0;i--)
        {
            curr=nums[i]+(dq.empty()?0:nums[dq.front()]);     
            while(!dq.empty()&&curr>nums[dq.back()])
                dq.pop_back();	
            dq.push_back(i);          
			
            if(dq.front()>=i+k)
                dq.pop_front();
            nums[i]=curr;      
        }
        return curr;                  
    }
};