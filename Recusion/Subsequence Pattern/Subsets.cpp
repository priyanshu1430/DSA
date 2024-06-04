class Solution {
public:
    void solve(vector<int>& nums,vector<int>& temp,int i,vector<vector<int>> &result)
    {
        if(i>=nums.size())
        {
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);//take
        solve(nums,temp,i+1,result);
        temp.pop_back();
        solve(nums,temp,i+1,result);//not take i

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;// store subset
        solve(nums,temp,0,result);
        return result;
    }
};