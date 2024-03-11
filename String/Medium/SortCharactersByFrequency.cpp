class Solution {
public:
    static bool sortcol1(const pair<char, int>& a, const pair<char, int>& b) 
    {
        return a.second > b.second; 
    }

    string frequencySort(string s) {
        vector<pair<char, int>> mp(256, {0, 0}); 
        for (char c : s) {
            mp[c].first = c;
            mp[c].second++;
        }
        sort(mp.begin(), mp.end(), sortcol1);
        string ans = "";
        for (const auto& p : mp) {
            int count = p.second;
            while (count--) {
                ans += p.first;
            }
        }
        return ans;
    }
};