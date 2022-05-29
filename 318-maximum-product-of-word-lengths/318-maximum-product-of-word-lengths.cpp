class Solution {
public:
    int maxProduct(vector<string>& words) {
        int sz=words.size();
        vector<int> val(sz,0);
        int ans=0;
       
        for(int i=0;i<sz;i++){
           for(auto it: words[i]) 
               val[i]|=1<<(it-'a');
        }
        
        for(int i=0;i<sz;i++){
            for(int j=i+1;j<sz;j++)
                if((val[i]&val[j])==0 && words[i].length()*words[j].length()>ans)
                    ans=words[i].length()*words[j].length();
        }
        return ans;
    }
};
