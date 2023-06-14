// ReverseInteger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int buttom = -2147483648;
        int floor = 2147483647;
        int result = 0;
        string prefix = "";
        string xString = to_string(x);
        string rString = "";
        if (xString.substr(0, 1) == "-")
        {
            prefix = "-";
            xString = xString.substr(1, xString.length() - 1);
        }
        for (int i = xString.length() - 1; i >= 0; i--)
        {
            rString += xString.substr(i, 1);
        }
        try {
            if (prefix != "")
            {
                rString = prefix + rString;
            }
            result = stoi(rString);
        }
        catch (std::out_of_range& e)
        {
            return 0;
        }
        return result;
    }
};

int main()
{
    //int testCase = -2147483648;
    //int answer = 0;
    int testCase = 243242423;
    int answer = 324242342;
    Solution sol;
    cout << to_string(sol.reverse(testCase));
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
