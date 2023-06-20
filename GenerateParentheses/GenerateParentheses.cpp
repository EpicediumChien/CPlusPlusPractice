// GenerateParentheses.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solve(string output, int left, int right, vector<string>& ans)
    {
        if (left == 0 && right == 0)
        {
            ans.push_back(output);
            return;
        }

        if (left == right)
        {
            string op1 = output;
            op1.push_back('(');
            solve(op1, left - 1, right, ans);
        }
        else if (left == 0)
        {
            string op1 = output;
            op1.push_back(')');
            solve(op1, left, right - 1, ans);
        }
        else if (right == 0)
        {
            string op1 = output;
            op1.push_back('(');
            solve(op1, left - 1, right, ans);
        }
        else
        {
            string op1 = output;
            string op2 = output;
            op1.push_back('(');
            op2.push_back(')');
            solve(op1, left - 1, right, ans);
            solve(op2, left, right - 1, ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        int left = n;
        int right = n;
        string output = "";
        vector<string> answer;
        solve(output, left, right, answer);

        return answer;
    }
};


int main()
{
    //int testCase = 1;
    //vector<string> answer {"()"};
    int testCase = 3;
    vector<string> answer {"((()))", "(()())", "(())()", "()(())", "()()()"};
    Solution sol;
    vector<string> result = sol.generateParenthesis(testCase);
    string output = "[";
    for (auto ele : result)
    {
        output += "\"" + ele + "\", ";
    }
    if (output.size() != 1 && output.substr(output.length() - 2, 2) == ", ")
    {
        output = output.substr(0, output.length() - 2);
    }
    output += "]";
    cout << output;
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
