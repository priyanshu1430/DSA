class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int c;
	map <int,int> cnt;
	for(int i=0;i<n;i++)
	{
		cnt[nums[i]]++;
	}
	for(int i=0;i<n;i++)
	{
		if(cnt[nums[i]]==1)
			c=nums[i];
	}
    return c;
    }
};

// xor concept
#include<vector>

int getSingleElement(vector<int> &arr){
	int n=arr.size();
	int c=0;
	for(int i=0;i<n;i++)
	{
		c=c^arr[i];// even count =0;odd count=1;4^4=0.
	}
	return c;
		
}