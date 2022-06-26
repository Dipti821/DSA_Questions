class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int min_sum=INT_MAX,sum=0;
        int sz=cardPoints.size();
        int i=0,j=0;
        int temp=0;
        sum=accumulate(cardPoints.begin() ,cardPoints.end(),0);
        for( ;j<sz;j++){
            temp+=cardPoints[j];
            if((j-i+1)==sz-k){
              min_sum=min(min_sum ,temp);
                temp-=cardPoints[i];
              i++;
            }
        }
       
        return min_sum==INT_MAX?sum:sum-min_sum;
    }
};