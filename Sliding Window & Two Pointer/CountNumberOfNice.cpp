class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int left=0,right=0;
        int cnt=0,ans=0;
        while(right<n)
        {
            if(nums[right]%2==1)
            {
                k--;
                cnt=0;
            }
            while(k==0)
            {
                if(nums[left]%2==1)
                    k++;
                left++;
                cnt++;
            }
            ans+=cnt;
            right++;
        }
        return ans;
    }
};

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0,cnt=0;
        for(int i=0;i<n;i++)
            (nums[i]%2==0)?(nums[i]=0):(nums[i]=1);//converting into binary subarray sum problem 
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum==k)
                cnt++;
            if(mp.find(sum-k)!=mp.end())
                cnt+=mp[sum-k];
            mp[sum]++;
        }
        return cnt;
       
    }
};