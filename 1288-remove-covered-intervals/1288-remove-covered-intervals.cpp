class Solution {
private:
     static bool compare(const vector<int>&v1 ,const vector<int>&v2 ){
        if(v1[0]==v2[0])
            return v1[1]>v2[1];
        return v1[0]<v2[0];
    }
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int del=0 ,last=-1;
         sort(intervals.begin(),intervals.end(),compare);
         for(int i=0;i<intervals.size();i++){
              int now = intervals[i][1];
              if(last >= now) 
                  del++;
              last = max(last, now);
             }
        return intervals.size()-del;
    }
};