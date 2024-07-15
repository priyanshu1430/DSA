class Solution {
  public:
    int solve(vector<int>&height,int n,vector<int>&dp)//top down
    {
        if(n==0)
            return 0;
        if(dp[n]!=-1)
            return dp[n];
        int fs,ss=INT_MAX;
         fs=solve(height,n-1,dp)+abs(height[n]-height[n-1]);//taking one step
        if(n>1)
            ss=solve(height,n-2,dp)+abs(height[n]-height[n-2]);//taking 2 step
        return dp[n]=min(fs,ss);//min
    }
    int minimumEnergy(vector<int>& height, int n) {
        vector<int>dp(n,-1);
        // return solve(height,n-1,dp);
        dp[0]=0;
        for(int i=1;i<n;i++)//bottom up
        {
            int fs,ss=INT_MAX;
            fs=dp[i-1]+abs(height[i]-height[i-1]);
             if(i>1)
                ss=dp[i-2]+abs(height[i]-height[i-2]);
            dp[i]=min(fs,ss);
        }
        return dp[n-1];
    }
};