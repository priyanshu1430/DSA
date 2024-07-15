 class Solution {
  public:
  
    int solve(vector<int>& height, int n, int k,vector<int>&dp)
    {
        if(n==0)
            return 0;
        if(dp[n]!=-1)
            return dp[n];
        int mmsteps=INT_MAX;
        for(int i=1;i<=k;i++)
        {
            if(n-i>=0)
            {
                int jump=solve(height,n-i,k,dp)+abs(height[n]-height[n-i]);
                mmsteps=min(mmsteps,jump);
            }
        }
        return dp[n]=mmsteps;
    }
    int minimizeCost(vector<int>& height, int n, int k) {
        vector<int> dp(n,-1);
        // return solve(height,n-1,k,dp);
        dp[0]=0;
        for(int i=1;i<n;i++)
        {
            int mmsteps=INT_MAX;
            for(int j=1;j<=k;j++)
            {
                if(i-j>=0)
                {
                    int jump=dp[i-j]+abs(height[i]-height[i-j]);
                     mmsteps=min(mmsteps,jump);
                }
            }
            dp[i]=mmsteps;
        }
        return dp[n-1];
    }
};