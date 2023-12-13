class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int c=0,cmax=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
             {     c++;
            cmax=max(c,cmax);
             }
             else
                c=0;


        }
        return cmax;
    }
};
public class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int ans = 0, sum = 0;
        for (int n : nums) {
            sum *= n;// reseting *0
            sum += n;//counting
            ans = Math.max(ans, sum);// storing max consecutive
        }
        return ans;
    }
}