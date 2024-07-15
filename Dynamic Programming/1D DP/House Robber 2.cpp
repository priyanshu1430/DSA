class Solution {
public:
    int solve(int index,vector<int>&dp,vector<int>nums,int n)
    {
        if(index>=n)
            return 0;
        if(dp[index]!=-1)
            return dp[index];
        int pick=nums[index]+solve(index+2,dp,nums,n);
        int notpick=solve(index+1,dp,nums,n);
        
        return dp[index]=max(pick,notpick);

    }
    int rob(vector<int>& nums) {
        int n=nums.size();
         if (n == 0)
             return 0;
        if (n == 1)
             return nums[0];
        vector<int>dp(n,-1);
        int ans1=solve(0,dp,nums,n-1);
        vector<int>dp1(n,-1);
        int ans2=solve(1,dp1,nums,n);
        return max(ans1,ans2);
    }
};