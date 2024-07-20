class Solution {
  public:
    int mod=1e9+7;
    int solve(int idx,int target,vector<int>& arr,vector<vector<int>>& dp)
    {
        if(idx==0)
        {
            if(target==0&&arr[0]==0)
                return 2;
            if(target==0||arr[0]==target)
                return 1;
            return 0;
        }
        if(dp[idx][target]!=-1)
            return dp[idx][target];
        int notTake=solve(idx-1,target,arr,dp)%mod;
        int take=0;
        if(target>=arr[idx])
            take=solve(idx-1,target-arr[idx],arr,dp)%mod;
        return dp[idx][target]=(take+notTake)%mod;
    }
    int countPartitions(int n, int d, vector<int>& arr) {
       int totalSum=0;
       for(int &i:arr)
            totalSum+=i;
        int target=(totalSum-d);
        if(target%2==1||target<0)
            return 0;
        target=target/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return solve(n-1,target,arr,dp);
    }
};