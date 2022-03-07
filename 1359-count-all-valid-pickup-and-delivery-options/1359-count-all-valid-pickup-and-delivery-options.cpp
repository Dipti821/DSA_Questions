class Solution {
public:
const long long mod=1000000007;

    int countOrders(int n) {
        long long temp=1LL;
    
    for(int i=1;i<=n;i+=1) temp=(temp*i)%mod;
    
    for(int i=3;i<=2*(n-1)+1;i+=2) temp=(temp*i)%mod;
        
        return temp;
    }
};