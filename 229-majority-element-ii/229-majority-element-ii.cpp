class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Boyer-Moore Majority Vote algorithm
        // TC: O(N)+O(N)  SC: O(1)
        
        int n=nums.size();
        int cnt1=0,cnt2=0 ,candidate1=-1,candidate2=-1;
        for(auto it: nums){
            if(it==candidate1)
                cnt1++;
            else if(it==candidate2)
                cnt2++;
            else if(cnt1==0)
                candidate1=it ,cnt1++;
            else if(cnt2==0)
                candidate2=it ,cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
            }
        vector<int>ans;
        cnt1=0,cnt2=0;
        for(auto it: nums){
            if(it==candidate1) cnt1++;
            else if(it==candidate2) cnt2++;
        }
        if(cnt1>n/3)
            ans.push_back(candidate1);
        if(cnt2>n/3)
            ans.push_back(candidate2);
        
        return ans;
        
    }
};