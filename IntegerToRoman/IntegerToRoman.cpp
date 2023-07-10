// IntegerToRoman.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/integer-to-roman/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string romNum(int num, string one, string five, string nextone)
    {
        string result = "";
        while (num > 0)
        {
            if (num < 4)
            {
                result += one;
                num--;
            }
            else if (num == 4)
            {
                result = one + five;
                num -= 4;
            }
            else if (num < 9)
            {
                result += five;
                num -= 5;
            }
            else if (num == 9)
            {
                result = one + nextone;
                num -= 9;
            }
        }
        return result;
    }

    string intToRoman(int num) {
        int m = num / 1000;
        m %= 10;
        int c = num / 100;
        c %= 10;
        int x = num / 10;
        x %= 10;
        int i = num % 10;
        string romanString = "";
        if (m != 0)
        {
            romanString += romNum(m, "M", "", "");
        }

        if (c != 0)
        {
            romanString += romNum(c, "C", "D", "M");
        }

        if (x != 0)
        {
            romanString += romNum(x, "X", "L", "C");
        }

        if (i != 0)
        {
            romanString += romNum(i, "I", "V", "X");
        }

        return romanString;
    }
};

int main()
{
    //int testCase = 58;
    //string answer = "LVIII";
    int testCase = 1994;
    string answer = "MCMXCIV";
    Solution sol;
    cout << sol.intToRoman(testCase);
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
