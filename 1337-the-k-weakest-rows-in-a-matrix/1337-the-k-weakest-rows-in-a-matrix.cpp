class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int row=mat.size();
        int col=mat[0].size();
        vector<pair<int,int>>v;
        for(int i=0;i<row;i++){
            int j;
            for(j=0;j<col;j++){
                if(mat[i][j]==0)
                    break;
            }
            v.push_back({j,i});
        }
        sort(v.begin(),v.end());
        vector<int>ans(k);
        for(int i=0;i<k;i++){
            ans[i]=v[i].second;
        }
        return ans;
    }
};