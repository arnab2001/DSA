class Solution {
public:
    int dfs(int i, int j , vector<vector<int>> & matrix,int prev, vector<vector<int>> &vis, vector<vector<int>> &dp)
    {
        if(i>=matrix.size() || j>=matrix[0].size() || i<0 || j < 0 || prev >= matrix[i][j] || vis[i][j]==1)
        {
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        vis[i][j] = 1;
        int down =1+dfs(i+1, j, matrix,matrix[i][j],vis,dp);
        int right = 1+dfs(i, j+1, matrix,matrix[i][j],vis,dp);
        int up =  1+dfs(i-1, j, matrix,matrix[i][j],vis,dp);
        int left =  1+dfs(i, j-1, matrix,matrix[i][j],vis,dp);
        vis[i][j] = 0;
        return dp[i][j] = max(down,max(up,max(right,left)));
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = INT_MIN;
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dp(n+1,vector<int>(m+1, -1));
        for(int i = 0; i< matrix.size(); i++)
        {
            for(int j  = 0; j < matrix[0].size(); j++)
            {
                ans = max(ans,dfs(i, j, matrix,-1,vis,dp));
            }
        }
        return ans;
    }
};