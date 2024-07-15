class Solution {
public:
    int solve( int index,vector<int>& dp,vector<int>& nums,int n)
    {
        if (index >= n)
        return 0;
        if(dp[index]!=-1)
            return dp[index];
        int pick=nums[index]+solve(index+2,dp,nums,n);
        int notpick=0+solve(index+1,dp,nums,n);
        return dp[index]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n == 0)
             return 0;
        if (n == 1)
             return nums[0];
        vector<int> dp(n,-1);
        return solve(0,dp,nums,n);

        // if(n==1)
        //     return nums[0];
        
        // vector<int>ans(n);
        // ans[0]=nums[0];
        // ans[1]=max(nums[0],nums[1]);
        // for(int i=2;i<n;i++)
        //     ans[i]=max(ans[i-2]+nums[i],ans[i-1]);

        // return ans[n-1]; 
        
    }
};