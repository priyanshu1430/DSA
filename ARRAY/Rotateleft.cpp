vector<int> rotateArray(vector<int>nums, int k) {
    int n=nums.size();
     int temp,start,end;
    start=0,end=k-1;
    //reverse(nums,0,k)
    while(start<=end)
    {
        temp=nums[start];
        nums[start]=nums[end];
        nums[end]=temp;
        start++;
        end--;
    }
       // reverse(nums,k,n);
       start=k,end=n-1;
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
    return nums;

}
