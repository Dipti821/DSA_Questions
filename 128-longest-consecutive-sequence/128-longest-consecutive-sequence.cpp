class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        int sz=nums.size();
        
        for(auto it: nums)
            s.insert(it);
        int ans=0;
        for(int num :s){
            if(s.find(num-1)==s.end()){
                int current_num=num;
                int current_streak=1;
                
                while(s.find(current_num+1)!=s.end())
                {
                    current_num++;
                    current_streak++;
                }
                
                ans=max(ans,current_streak);
            }
        }
        return ans;
    }
};