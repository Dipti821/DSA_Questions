class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
     int sz=people.size();
     sort(people.begin(),people.end());
        int j=sz-1,i=0;
        int ans=0;
     while(i<=j){
         ans++;
        if((people[i]+people[j])<=limit) 
            i++;
         j--;
     }  
        return ans;
    }
};