bool isSubsetPresent(int n, int k, vector<int> &a)
{
    // Create a 2D dp array of size (n+1) x (k+1)
    vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));

    // Base case: a sum of 0 is always possible with an empty subset
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
    }

    // Fill the dp table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (j >= a[i - 1]) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // The answer will be in dp[n][k]
    return dp[n][k];
}