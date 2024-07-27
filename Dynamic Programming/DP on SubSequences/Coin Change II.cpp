class Solution {
public:
    // Recursive function to calculate the number of ways to make the target amount using the given coins
    int solve(int idx, int target, vector<int>& coins, vector<vector<int>>& dp) {
        // Base case: If there's only one type of coin left (index 0)
        if (idx == 0) {
            // Check if the target amount can be exactly formed using only the coins[idx] (coin at index 0)
            if (target % coins[0] == 0)
                return 1; // If possible, there's 1 way to form the amount
            else
                return 0; // If not possible, return 0 ways
        }

        // Check if the result for this state (idx, target) is already computed and stored in dp table
        if (dp[idx][target] != -1)
            return dp[idx][target];

        // Option 1: Do not take the current coin (idx)
        long notTake = solve(idx - 1, target, coins, dp);

        // Option 2: Take the current coin (idx), if possible
        long take = 0;
        if (target >= coins[idx])
            take = solve(idx, target - coins[idx], coins, dp);

        // Store the result in the dp table and return it
        return dp[idx][target] = take + notTake;
    }

    // Main function to initialize the dp table and start the recursion
    int change(int amount, vector<int>& coins) {
        int n = coins.size(); // Number of different coins
        // Initialize the dp table with -1, meaning uncomputed states
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        // Start the recursion with the last coin index and the target amount
        return solve(n - 1, amount, coins, dp);
    }
};
