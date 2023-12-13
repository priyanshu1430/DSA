string read(int n, vector<int> book, int target)
{
   sort(book.begin(),book.end());
   int left=0,right=n-1;
   int sum=0;
   while(left<right)
   {
       sum=book[left]+book[right];
       if(sum==target)
        return("YES");
       if(sum>target)
        right--;
        else
            left++;
   }
   return("NO");
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        map<int,int> mpp;
        vector<int> str;
        for(int i=0;i<n;i++)
        {
            int num=nums[i];
            int rem=target-num;
            if(mpp.find(rem)!=mpp.end())
            {
                return {mpp[rem],i};
            }
            mpp[num]=i;
        }
        return{-1,-1};
 
    }
};