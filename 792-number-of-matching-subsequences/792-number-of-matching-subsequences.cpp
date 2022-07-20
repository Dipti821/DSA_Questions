class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
       vector<const char*> waiting[128];
    for (auto &w : words)
        waiting[w[0]].push_back(w.c_str());
    for (char c : s) {
        auto advance = waiting[c];
        waiting[c].clear();
        for (auto it : advance)
            waiting[*++it].push_back(it);
    }
    return waiting[0].size();
    }
};