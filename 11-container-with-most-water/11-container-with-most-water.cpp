class Solution {
public:
    int maxArea(vector<int>& height) {
        int sz=height.size();
        int left=0,right=sz-1,area=0;
        while(left<right){
            area=max(area,(right-left)*min(height[left],height[right]));
            if(height[left]>height[right])
                right--;
            else
                left++;
        }
        return area;
    }
};