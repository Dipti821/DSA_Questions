class Solution {
public:
    bool check(string s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++,j--;
        }
        return true;
    }
    void cal(string s, int ind,vector<string>&pal,vector<vector<string>> &ans ){
        if(ind==s.size()){
            ans.push_back(pal);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(check(s.substr(ind,i-ind+1))){
                pal.push_back(s.substr(ind,i-ind+1));
                cal(s,i+1,pal,ans); 
                pal.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
       vector<vector<string>> ans;
       vector<string>pal;
       cal(s,0,pal,ans);
        return ans;
    }
};