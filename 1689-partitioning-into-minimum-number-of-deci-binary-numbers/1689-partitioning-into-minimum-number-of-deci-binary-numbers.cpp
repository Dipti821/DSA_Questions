class Solution {
public:
    int minPartitions(string n) {
        int sz=n.size();
        int ans=0;
        for(int i=sz-1;i>=0;i--){
            ans=max(ans,n[i]-'0');
        }
        return ans;
    }
};