class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        int sz=path.size();
        string ans="";
        string dir="";
        for(int i=1;i<sz;i++){
            dir="";
           while (i <  sz && path[i] != '/') {
            dir += path[i];
            i++;
          }
        if (dir == "..") {
            if (!v.empty())
                v.pop_back();
        }
        else if (dir == "." || dir == "") {
           
        }
        else {
            v.push_back(dir);
        }
    }
    for (auto i : v) {
        ans += "/" + i;
    }
    if (ans == "")
        return "/";
 
    return ans;

                
        }
    
};