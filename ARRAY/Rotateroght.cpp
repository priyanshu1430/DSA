class Solution {
public:
    void rotate(vector<int>& nums, int k) {
         int n=nums.size();
         k=k%n;
        
    int temp,start,end;
    end=n-k-1,start=0;
    while(start<=end)
    {
        temp=nums[start];
        nums[start]=nums[end];
        nums[end]=temp;
        start++;
        end--;
    }
       // reverse(nums,k,n);
       start=n-k,end=n-1;
    while(start<=end)
    {
        temp=nums[start];
        nums[start]=nums[end];
        nums[end]=temp;
        start++;
        end--;
    }
        //reverse(nums,0,n);
        start=0,end=n-1;
    while(start<=end)
    {
        temp=nums[start];
        nums[start]=nums[end];
        nums[end]=temp;
        start++;
        end--;
    }
        
        for(int i=0;i<n;i++)
            cout << nums[i];
    }
};