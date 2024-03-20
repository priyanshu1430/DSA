class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int mp[2]={0};
        int n=nums.size();
        int left=0,right=0;
        int maxLength=0;
        while(right<n)
        {
            mp[nums[right]]++;
            while(right-left+1-mp[1]>k)
            {
                mp[nums[left]]--;
                left++;
            }
            maxLength=max(maxLength,right-left+1);
            right++;
        }
        return maxLength;
    }
};