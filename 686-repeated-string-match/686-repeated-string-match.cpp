class Solution {
public:
    int repeatedStringMatch(string a, string b) {
         for (auto i = 0, j = 0; i < a.size(); ++i) {
            for (j = 0; j < b.size() && a[(i + j) % a.size()] == b[j]; ++j);
            if (j == b.size()) 
            return (i + j - 1) / a.size() + 1;
    }
    return -1;
    }
};