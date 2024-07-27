class Solution {
public:
    int solve(int idx, int target, vector<int>& coins, vector<vector<int>>& dp) {
        // Base case: If we're at the first coin
        if (idx == 0) {
            if (target % coins[0] == 0)
                return target / coins[0];
            else
                return 1e9;
        }
        
        // Check memoization table
        if (dp[idx][target] != -1)
            return dp[idx][target];

        // Recurrence relation
        int notTake = solve(idx - 1, target, coins, dp);
        int take = INT_MAX;
        if (coins[idx] <= target)
            take = 1 + solve(idx, target - coins[idx], coins, dp);
        
        // Store the result in dp table and return
        return dp[idx][target] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = solve(n - 1, amount, coins, dp);
        return ans >= 1e9 ? -1 : ans;
    }
};
