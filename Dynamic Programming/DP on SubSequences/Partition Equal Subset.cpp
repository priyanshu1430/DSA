class Solution {
public:
    bool solve(int idx,int target,vector<int>& nums,vector<vector<int>>&dp)
    {
        if(target==0)
            return true;
        if(idx==0)
            return(target==nums[0]);
        if(dp[idx][target]!=-1)
            return dp[idx][target];
        bool notTake=solve(idx-1,target,nums,dp);
        bool take=false;
        if(target>=nums[idx])
            take=solve(idx-1,target-nums[idx],nums,dp);
        return dp[idx][target]=take||notTake;
    }
    bool canPartition(vector<int>& nums) {
        int target=0;
        int n=nums.size();
        for(int &i:nums)
            target+=i;
        if(target%2!=0)
            return false;
        target=target/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return solve(n-1,target,nums,dp);

    }
};