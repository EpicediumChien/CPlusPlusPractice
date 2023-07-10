// WildcardMatching.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/wildcard-matching/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.length();
        int pLen = p.length();
        vector<vector<bool>> parseMap(s.length() + 1, vector<bool>(p.length() + 1, false));
        parseMap[0][0] = true;
        for (int j = 1; j <= pLen; j++)
        {
            if (p[j - 1] == '*')
            {
                parseMap[0][j] = parseMap[0][j - 1];
            }
        }
 
        for (int i = 1; i <= sLen; i++)
        {
            for (int j = 1; j <= pLen; j++)
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                {
                    parseMap[i][j] = parseMap[i - 1][j - 1];
                }
                else if (p[j - 1] == '*')
                {
                    parseMap[i][j] = parseMap[i - 1][j - 1] || parseMap[i][j - 1] || parseMap[i - 1][j];
                }
            }
        }

        return parseMap[sLen][pLen];
    }
};

int main()
{
    //string testCaseS = "aa";
    //string testCaseP = "a";
    //bool answer = false;
    //string testCaseS = "aa";
    //string testCaseP = "*";
    //bool answer = true;
    //string testCaseS = "adceb";
    //string testCaseP = "*a*b";
    //bool answer = true;
    string testCaseS = "abcabczzzde";
    string testCaseP = "*abc???de*";
    bool answer = true;
    Solution sol;
    cout << sol.isMatch(testCaseS, testCaseP);
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
