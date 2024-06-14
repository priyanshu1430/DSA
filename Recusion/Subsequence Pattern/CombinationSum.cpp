class Solution {
public:
    void solve(int ind,vector<int>& candidates, int target,vector<vector<int>>&ans,vector<int>&ds)
    {
        if(ind==candidates.size())
        {
            if(target==0)
                ans.push_back(ds);
            return;
        }
        if(candidates[ind]<=target)
        {
            ds.push_back(candidates[ind]);
            solve(ind,candidates,target-candidates[ind],ans,ds);// not changing index because it can be picked once more
            ds.pop_back();
        }
        solve(ind+1,candidates,target,ans,ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        solve(0,candidates,target,ans,ds);
        return ans;
        
    }
};