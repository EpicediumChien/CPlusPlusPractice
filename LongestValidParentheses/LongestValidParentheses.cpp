// LongestValidParentheses.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/longest-valid-parentheses/

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> parentheseBucket;
        parentheseBucket.push(-1);
        int maxRecord = 0;
        for (int i=0; i<s.length(); i++)
        {
            string w = string(1, s[i]);
            if (w == "(")
            {
                parentheseBucket.push(i);
            }
            else
            {
                parentheseBucket.pop();
                if (parentheseBucket.empty())
                {
                    parentheseBucket.push(i);
                }
                else
                {
                    int tempRecord = 0;
                    tempRecord = i - parentheseBucket.top();
                    maxRecord = max(tempRecord, maxRecord);
                }
            }
        }

        return maxRecord;
    }
};

int main()
{
    //string testCase = "()(()";
    //int answer = 2;
    //string testCase = ")()())";
    //int answer = 4;
    string testCase = "()(())";
    int answer = 6;
    Solution sol;
    cout << sol.longestValidParentheses(testCase);
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
