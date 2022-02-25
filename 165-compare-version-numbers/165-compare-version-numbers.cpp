class Solution {
public:
    int compareVersion(string version1, string version2) {
        int r0=0,r1=0;
        for (int i = 0, j = 0; (i < version1.length()
                            || j < version2.length());) {
        
        while (i < version1.length() && version1[i] != '.') {
            r0 = r0 * 10 + (version1[i] - '0');
            i++;
        }
        while (j < version2.length() && version2[j] != '.') {
            r1 = r1 * 10 + (version2[j] - '0');
            j++;
        }
 
        if (r0 > r1)
            return 1;
        if (r1 > r0)
            return -1;
        r0 = r1 = 0;
        i++;
        j++;
    }
     return 0;   
    }
};