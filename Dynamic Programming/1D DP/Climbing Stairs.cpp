class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        // dp[0]=1;
        // dp[1]=1;
        int prev=1;
        int prev2=1;
        for(int i=2;i<=n;i++)
        {
            // dp[i]=dp[i-1]+dp[i-2];
            int cur_i=prev+prev2;
            prev2=prev;
            prev=cur_i;
        }
        return prev;
    }
};