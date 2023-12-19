vector<int> nextGreaterPermutation(vector<int> &a) {
    int ind=-1;
    int n=a.size();
    for(int i=0;i<n-1;i++)
    {
        if(a[i]<a[i+1])
            ind=i;
    }
    if(ind==-1)
    {
        reverse(a.begin(),a.end());
        return a;
    }
    int l=ind+1;
    for(int i=ind+1;i<n;i++)
    {
        if(a[i]>a[ind])
        l=i;
    }
    swap(a[ind],a[l]);
    reverse(a.begin()+ind+1,a.end());
    return a;

}


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;
        for(int i = 0; i < n-1; i++) {
          if(nums[i]<nums[i+1]) idx = i;
        }
        if(idx == -1) {
          reverse(nums.begin(), nums.end());
          return;
        }
        int l = idx + 1;
        for(int i = idx + 1; i < n; i++) {
            if(nums[i] > nums[idx]) l = i;
        }
        swap(nums[idx], nums[l]);
        reverse(nums.begin() + 1 + idx, nums.end());
        return;
    }
};