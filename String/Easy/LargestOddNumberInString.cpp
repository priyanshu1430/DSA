#include <string>
class Solution {
public:
    string largestOddNumber(string num) {
        int end = num.size() -1;
        string ans = "";
        for(int i= end; i>=0;i--){
            if((int)num[i] % 2 == 1){
                ans = num.substr(0,i+1);
                break;
            }
        }
        return ans;
    }
};