class Solution {
public:
    int trap(vector<int>& height) {
        int sz=height.size();
        vector<int>mxl(sz),mxr(sz);
        mxl[0]=height[0];
        mxr[sz-1]=height[sz-1];
        
        for(int i=1;i<sz;i++)
            mxl[i]=max(mxl[i-1],height[i]);
        for(int i=sz-2;i>=0;i--)
            mxr[i]=max(mxr[i+1],height[i]);
        
//           for(int i=0;i<sz;i++)
//            cout<<mxl[i]<<" "<<mxr[i]<<endl;
        
        int ans=0;
        for(int i=0;i<sz;i++){
           ans+=min(mxl[i],mxr[i])-height[i] ;
        }
        return ans;
    }
};