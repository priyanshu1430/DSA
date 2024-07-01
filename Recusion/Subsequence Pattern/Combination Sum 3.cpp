class Solution {
public:
    void solve(int ind,int k,int n,vector<vector<int>> &ans,vector<int> &subset)
    {
        if(k<0||n<0)
            return;
        if(k==0&&n==0)
        {
            ans.push_back(subset);
            return;
        }
        for(int i=ind;i<=9;i++)
        {
            subset.push_back(i);
            solve(i+1,k-1,n-i,ans,subset);
            subset.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> subset;
        solve(1,k,n,ans,subset);
        return ans;
    }
};