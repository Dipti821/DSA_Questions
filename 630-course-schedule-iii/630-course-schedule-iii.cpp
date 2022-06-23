class Solution {
public:
    struct comparator{
     bool operator()(const vector<int>& v1, const vector<int>& v2) {
          return v1[1] < v2[1];
      }
    };
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<int>pq;
        sort(courses.begin() ,courses.end() ,comparator());
        long long time=0;
        for(auto it: courses){
            time+=it[0];
            pq.push(it[0]);
            
            if(time>it[1]){
                time-=pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};