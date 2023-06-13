// ZigZagConversion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string zigzagResult = "";
        vector<string> v(numRows, "");
        if (numRows > 1) {
            int j = 0, dir = -1;
            for (int i = 0; i <= s.length(); i++)
            {
                if (j == numRows - 1 || j == 0) dir *= -1;

                v[j] += s.substr(i, 1);

                if (dir == 1) j++;
                else j--;
            }

            for (auto& str : v) zigzagResult += str;

        }
        else {
            if (numRows == 1)
            {
                zigzagResult = s;
            }
        }
        return zigzagResult;
    }
};

int main()
{
    Solution sol;
    /*
    string testCase = "PAYPALISHIRING";
    int numRows = 3;
    string result = "PAHNAPLSIIGYIR";
    */
    string testCase = "PAYPALISHIRING";
    int numRows = 4;
    string result = "PINALSIGYAHRPI";
    cout << to_string(result == sol.convert(testCase, numRows));
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
