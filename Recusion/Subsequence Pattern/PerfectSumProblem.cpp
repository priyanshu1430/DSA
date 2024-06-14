class Solution{

	public:
	int mod = 1e9+7;

    int countSum(int arr[], int n, int sum, vector<vector<int>> &dp) {
         // If result is already computed, return it
        if (dp[n][sum] != -1) 
            return dp[n][sum];
        // Base Cases
         if (n == 0 && sum>0)
            return 0;      // No subsets possible if no elements are left
        else if(n==1)
        { 
            if (sum == 0) 
            {
               if(arr[0]==0)
                return 2;
               else
                return 1;
            }
            else
            {
                if(arr[0]==sum)
                    return 1;
                else
                    return 0;
            }
                
        }
        else if(n==0&&sum==0)
             return 1;
        
        // Exclude the current element
        int ans = countSum(arr, n - 1, sum, dp) % mod;
        
        // Include the current element if it is not greater than the sum
        if (arr[n - 1] <= sum) {
            ans += countSum(arr, n - 1, sum - arr[n - 1], dp);
            ans %= mod;
        }
        
        // Store the result in dp array and return
        return dp[n][sum] = ans;
    }

    int perfectSum(int arr[], int n, int sum) {
        // Create a dp array initialized to -1
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        return countSum(arr, n, sum, dp) % mod;
    }
	  
};