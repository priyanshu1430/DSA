class Solution{

	public:
	int mod=1e9+7;
	int solve(int idx,int target,int arr[], vector<vector<int>>&dp)
	{
	   if(idx==0)
	   {
	       if(target==0&&arr[0]==0)
	           return 2;
	       if(target==0||target==arr[0])
	            return 1;
	       return 0;
	   }
	    if (dp[idx][target] != -1)
            return dp[idx][target];
    
        int notPick = solve(idx - 1, target, arr, dp) % mod;
        int pick = 0;
        if (target >= arr[idx])
            pick = solve(idx - 1, target - arr[idx], arr, dp) % mod;
        
        return dp[idx][target] = (pick + notPick) % mod;
    }
	int perfectSum(int arr[], int n, int sum)
	{
       vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return solve(n - 1, sum, arr, dp);
	}
	  
};