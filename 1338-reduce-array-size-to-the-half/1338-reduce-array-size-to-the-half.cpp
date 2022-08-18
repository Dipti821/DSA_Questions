class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int>m;
        for(auto it: arr)
            m[it]++;
        vector<int>v;
        for(auto it: m)
            v.push_back(it.second);
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        int n=arr.size(),sz=0,i=0;
        while(sz<(n+1)/2){
            sz+=v[i];
            i++;
        }
        return i;
    }
};