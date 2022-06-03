class Solution {
public:
    int trap(vector<int>& height) {
        int sz=height.size();
//         vector<int>mxl(sz),mxr(sz);
//         mxl[0]=height[0];
//         mxr[sz-1]=height[sz-1];
        
//         for(int i=1;i<sz;i++)
//             mxl[i]=max(mxl[i-1],height[i]);
//         for(int i=sz-2;i>=0;i--)
//             mxr[i]=max(mxr[i+1],height[i]);
        
// //           for(int i=0;i<sz;i++)
// //            cout<<mxl[i]<<" "<<mxr[i]<<endl;
        
//         int ans=0;
//         for(int i=0;i<sz;i++){
//            ans+=min(mxl[i],mxr[i])-height[i] ;
//         }
//         return ans;
        
        
        //Method 2: using two pointers
        
        int l=0,r=sz-1,ans=0,lmax=0,rmax=0;
        while(l<=r){
            if(lmax<=rmax){
                if(lmax<height[l]) lmax=height[l];
                else
                ans+=(lmax-height[l]);
                l++;
            }
            else{
                if(rmax<height[r]) rmax=height[r];
                else
                    ans+=(rmax-height[r]);
                r--;
                   
            }
        }
        return ans;    
        
    }
};