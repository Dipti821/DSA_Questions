class Solution {
public:
    static bool compare(vector<int>&v,vector<int>&v1){
        return v[1]>=v1[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),compare);
        
        int ans=0;
        for(auto it:boxTypes){
            if(it[0]<=truckSize)
            {
               ans+=(it[0]*it[1]); 
                truckSize-=it[0];
            }
            else{
                ans+=truckSize*it[1];
                break;
            }
        }
        return ans;
    }
};