class Solution {
public:
    int atmost(vector<int>& nums, int k)
    {
        int n=nums.size();
        unordered_map<int,int> mpp;
        int left=0,right=0;
        int ans=0;
        while(right<n)
        {
            mpp[nums[right]]++;
            while(mpp.size()>k)
            {
                mpp[nums[left]]--;
                if(mpp[nums[left]]==0)
                    mpp.erase(nums[left]);
                left++;
            }
                ans+=right-left+1;
            right++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};