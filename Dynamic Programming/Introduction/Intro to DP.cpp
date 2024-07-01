class Solution {
  public:
  const long long MOD = 1e9+7;
    long long solve(int n,vector<long long>&dp)
    {
        if(n<=1)
            return n;
        if(dp[n]!=-1)
            return dp[n];
        return dp[n]=(solve(n-1,dp)+solve(n-2,dp))%MOD;
    }
    long long int topDown(int n) {
        vector<long long> dp(n+1,-1);
        return solve(n,dp);
        
    }
    long long int bottomUp(int n) {
        if(n==0)
            return 0;
         vector<long long> dp(n+1,-1);
         dp[0]=0;
         dp[1]=1;
         for(int i=2;i<=n;i++)
         {
             dp[i]=(dp[i-1]+dp[i-2])%MOD;
         }
         return dp[n];
    }
};