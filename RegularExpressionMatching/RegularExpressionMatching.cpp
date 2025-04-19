// RegularExpressionMatching.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/regular-expression-matching/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        // Pre-fill for pattern like a*, a*b*, etc.
        for (int j = 2; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[j] = dp[j - 2];
            }
        }

        for (int i = 1; i <= m; i++) {
            bool prevDiag = dp[0]; // this holds dp[i-1][j-1]
            dp[0] = false;
            for (int j = 1; j <= n; j++) {
                bool temp = dp[j]; // save dp[i-1][j] before overwriting
                char sc = s[i - 1], pc = p[j - 1];

                if (pc == '*') {
                    // Two options: zero occurrence or multiple occurrence
                    dp[j] = dp[j - 2] || ((p[j - 2] == '.' || p[j - 2] == sc) && dp[j]);
                }
                else {
                    dp[j] = (pc == '.' || pc == sc) && prevDiag;
                }

                prevDiag = temp;
    }

    bool oldIsMatch(string s, string p) {
        int sSize = s.size(), pSize = p.size();
        vector<vector<bool>> expArray(sSize + 1, vector<bool>(pSize + 1, false));
        expArray[0][0] = true;

        // empty string for first row
        for (int j = 1; j <= pSize; j++) {
            if (p[j - 1] == '*' && j >= 2)
            {
                expArray[0][j] = expArray[0][j - 2];
            }
        }

        // Other expression
        for (int i = 1; i <= sSize; i++)
        {
            for (int j = 1; j <= pSize; j++)
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
                {
                    expArray[i][j] = expArray[i - 1][j - 1];
                }
                else if (p[j - 1] == '*')
                {
                    expArray[i][j] = expArray[i][j - 2];
                    if (s[i - 1] == p[j - 2] || p[j - 2] == '.')
                    {
                        expArray[i][j] = expArray[i][j] || expArray[i - 1][j];
                    }
                }
            }
        }

        return expArray[sSize][pSize];
    }
};

int main()
{
    //string s = "aa";
    //string p = "a";
    //bool answer = false;
    //string s = "aa";
    //string p = "a*";
    //bool answer = true;
    //string s = "aab";
    //string p = "c*a*b";
    //bool answer = true;
    //string s = "ab";
    //string p = ".*c";
    //bool answer = false;
    //string s = "ab";
    //string p = ".*";
    //bool answer = true;
    string s = "aaa";
    string p = "a*a";
    bool answer = true;
    Solution sol;
    bool result = sol.isMatch(s, p);
    cout << result;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
