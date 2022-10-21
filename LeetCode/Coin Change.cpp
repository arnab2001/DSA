class Solution {
public:    
    int dp[12 + 1][10000 + 1];
    
    int findLowestCoins(vector<int> &coins, int arraySize, int amount) {
        for (int i = 0; i < arraySize + 1; i++)
            for (int j = 0; j < amount + 1; j++)
                if (i == 0 || j == 0)
                    dp[i][j] = (j == 0) ? 0 : INT_MAX - 1;
        
        for (int i = 1; i < arraySize + 1; i++) {
            for (int j = 1; j < amount + 1; j++) {
                if (coins[i - 1] > j)
                    dp[i][j] = 0 + dp[i - 1][j];
                else
                    dp[i][j] = min(0 + dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
            }
        }
        
        return dp[arraySize][amount];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int res = findLowestCoins(coins, coins.size(), amount);
        return (res == INT_MAX - 1) ? -1 : res;
    }
};