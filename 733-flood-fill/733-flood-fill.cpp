class Solution {
    int d[5]= {0, 1, 0, -1, 0};
    int m, n;
   public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        if (image[sr][sc] == newColor) return image;
        
        m = image.size(); n = image[0].size();
        dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }

    void dfs(vector<vector<int>>& image, int r, int c, int oldColor, int newColor) {
        if (r < 0 || r == m || c < 0 || c == n || image[r][c] != oldColor) return;
        image[r][c] = newColor;
        for (int i = 0; i < 4; i++)
            dfs(image, r + d[i], c + d[i+1], oldColor, newColor);
    }
};