class Solution {
    // public:
    // int repeatedStringMatch(string a, string b) {
    //      for (auto i = 0, j = 0; i < a.size(); ++i) {
    //         for (j = 0; j < b.size() && a[(i + j) % a.size()] == b[j]; ++j);
    //         if (j == b.size()) 
    //         return (i + j - 1) / a.size() + 1;
    // }
    // return -1;
    // }
private:
    int BASE = 1000000;
public:
    // Rabin Karp Algorithm
    int repeatedStringMatch(string A, string B) {
        if(A == B) return 1;
        int count = 1;
        string source = A;
        while(source.size() < B.size()){
            count++;
            source+=A;
        }
        if(source == B) return count;
        if(Rabin_Karp(source,B) != -1) return count;
        if(Rabin_Karp(source+A,B) != -1) return count+1;
        return -1;
    }
    int Rabin_Karp(string source, string target){
        if(source == "" or target == "") return -1;
        int m = target.size();
        int power = 1;
        for(int i = 0;i<m;i++){
            power = (power*31)%BASE;
        }
        int targetCode = 0;
        for(int i = 0;i<m;i++){
            targetCode = (targetCode*31+target[i])%BASE;
        }
        int hashCode = 0;
        for(int i = 0;i<source.size();i++){
            hashCode = (hashCode*31 + source[i])%BASE;
            if(i<m-1) continue;
            if(i>=m){
                hashCode = (hashCode-source[i-m]*power)%BASE;
            }
            if(hashCode<0)
                hashCode+=BASE;
            if(hashCode == targetCode){
                if(source.substr(i-m+1,m) == target)
                    return i-m+1;
            }
        }
        return -1;
    }
};