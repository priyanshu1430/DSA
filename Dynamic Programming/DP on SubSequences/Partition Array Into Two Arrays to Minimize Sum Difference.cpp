class Solution {
public:
    int minimumDifference(vector<int>& arr) {
        int totalSum = 0;
        int n = arr.size();
        
        // Calculate the total sum of the array
        for (int &i : arr)
            totalSum += i;
        
        // Initialize the dp array
        vector<bool> prev(totalSum+1, false);
        prev[0] = true;
        
        // If the first element is less than or equal to the total sum
        if (totalSum >= arr[0])
            prev[arr[0]] = true;
        
        // Update the dp array for each element in the array
        for (int idx = 1; idx < n; idx++) {
            vector<bool> cur(totalSum + 1, false);
            cur[0] = true;
            for (int target = 1; target <= totalSum; target++) {
                bool notTaken = prev[target];
                bool taken = false;
                if (arr[idx] <= target)
                    taken = prev[target - arr[idx]];
                cur[target] = notTaken || taken;
            }
            prev = cur; // Update prev to cur for the next iteration
        }
        
        // Find the minimum difference
        int mini = INT_MAX; // Use INT_MAX instead of 1e9 for better readability
        for (int i = 0; i <= totalSum; i++) {
            if (prev[i] == true) {
                // Calculate the absolute difference between two subset sums
                int diff = abs(i - (totalSum - i));
                mini = min(mini, diff);
            }
        }
        
        return mini;
    }
};
