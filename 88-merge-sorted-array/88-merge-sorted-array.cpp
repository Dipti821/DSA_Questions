class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Method 1 sorting algo
        // Method 2 insertion sort algo SC: O(1)
        // Method 3 gap algo TC: O((N+M)LOG(N+M)) SC: O(1)
//         int nextGap(int gap)
//           {
//             if (gap <= 1)
//             return 0;
//             return (gap / 2) + (gap % 2);
//           }
 
//         void merge(int* arr1, int* arr2, int n, int m)
//         {
//           int i, j, gap = n + m;
//           for (gap = nextGap(gap);gap > 0; gap = nextGap(gap))
//           {
       
//              for (i = 0; i + gap < n; i++)
//               if (arr1[i] > arr1[i + gap])
//                 swap(arr1[i], arr1[i + gap]);
 
//              for (j = gap > n ? gap - n : 0; i < n && j < m;i++, j++)
//               if (arr1[i] > arr2[j])
//                 swap(arr1[i], arr2[j]);
 
//              if (j < m) {
//                 for (j = 0; j + gap < m; j++)
//                 if (arr2[j] > arr2[j + gap])
//                     swap(arr2[j], arr2[j + gap]);
//              }
//          }
//         }
        
        
        int i = m - 1, j = n - 1, tar = m + n - 1;
        while (j >= 0) 
            nums1[tar--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        
    }
};