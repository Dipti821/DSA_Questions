class Solution {
public:
    int threeSumMulti(vector<int>& a, int target) {
        const long long mod=1e9+7;
        int sz=a.size();
        sort(a.begin(),a.end());
        int ans=0;
        
        for(int i=0;i<sz;i++){
            
            int t=target-a[i];
            int j=i+1,k=sz-1;
            
            while(j<k){
                
                if(a[j]+a[k]<t)
                    j++;
                else if(a[j]+a[k]>t)
                    k--;
                else if(a[j]!=a[k]){
                    
                    int left=1,right=1;
                    
                    while(j+1<k && a[j]==a[j+1]){
                        left++;
                        j++;
                    }
                     while(k-1>j && a[k]==a[k-1]){
                        right++;
                        k--;
                    }
                    ans+=left*right;
                    ans%=mod;
                    k--;
                    j++;
                }
                else{
                    ans+=(k-j+1)*(k-j)/2;
                    ans%=mod;
                    break;
                }
            }
        }
        return ans;
    }
};