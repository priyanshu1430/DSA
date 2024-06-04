#include<bits/stdc++.h>
using namespace std;
void generateStringsHelper(int n,string s, char last_char,vector<string>& result) {
    if (s.length() == n)  // Base case: if the current string's length is equal to n, add it to the result
    {
        result.push_back(s);
        return;
    }
    generateStringsHelper(n, s + '0', '0', result); // Recursive case: add '0' to the string
    if (last_char != '1') // Add '1' to the string only if last_char is not '1'
    {
        generateStringsHelper(n, s + '1', '1', result);
    }
}

vector<string> generateBinaryStrings(int n) {
    vector<string> result;
    if (n == 0) {
        result.push_back("");
        return result;
    }
    generateStringsHelper(n, "", '\0', result); // Start with an empty string and no last character
    return result;
}

int main() {
    int n = 4;
    vector<string> binaryStrings = generateBinaryStrings(n);
    
    for (const string& str : binaryStrings) {
        cout << str << endl;
    }
    
    return 0;
}
