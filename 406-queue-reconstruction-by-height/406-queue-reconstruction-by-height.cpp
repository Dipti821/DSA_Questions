class Solution {
static bool cmp(vector<int> a, vector<int> b){
    if(a[0] != b[0]){
        return a[0] > b[0];
    }else{
        return a[1] < b[1];
    }
}   
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> res;
        for(auto p : people){
            res.insert(res.begin()+p[1], p);
        }
        return res;
    }
};