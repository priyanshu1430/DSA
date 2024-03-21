// https://www.youtube.com/watch?v=atUJS7ArOY0
// y-x=k;
// x=y-k;
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> prefSumFreqMp;
        int prefSum = 0;
        prefSumFreqMp[0] = 1;
        int subArrayCnt = 0;
        for (int i=0;i<nums.size();i++) {
            prefSum += nums[i];
            if (prefSumFreqMp.find(prefSum - goal) != prefSumFreqMp.end()) {
                subArrayCnt += prefSumFreqMp[prefSum - goal];
            }
            prefSumFreqMp[prefSum]++;
        }   
        return subArrayCnt;
    }
};