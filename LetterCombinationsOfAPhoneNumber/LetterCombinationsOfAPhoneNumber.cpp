// LetterCombinationsOfAPhoneNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> str;
        for (int i = 0; i < digits.length(); i++)
        {
            str = stringVectorInnerJoin(str, letters(digits[i]));
        }
        return str;
    }

private:
    vector<string> letters(char num)
    {
        vector<string> result;
        switch (num)
        {
        case '2':
            result.push_back("a");
            result.push_back("b");
            result.push_back("c");
            break;
        case '3':
            result.push_back("d");
            result.push_back("e");
            result.push_back("f");
            break;
        case '4':
            result.push_back("g");
            result.push_back("h");
            result.push_back("i");
            break;
        case '5':
            result.push_back("j");
            result.push_back("k");
            result.push_back("l");
            break;
        case '6':
            result.push_back("m");
            result.push_back("n");
            result.push_back("o");
            break;
        case '7':
            result.push_back("p");
            result.push_back("q");
            result.push_back("r");
            result.push_back("s");
            break;
        case '8':
            result.push_back("t");
            result.push_back("u");
            result.push_back("v");
            break;
        case '9':
            result.push_back("w");
            result.push_back("x");
            result.push_back("y");
            result.push_back("z");
            break;
        }
        return result;
    }

    vector<string> stringVectorInnerJoin(vector<string> a, vector<string> b)
    {
        vector<string> result;
        if (a.size() != 0) {
            for (auto ele : a)
            {
                vector<string> temp;
                temp.assign(b.begin(), b.end());
                for (auto tempEle : temp)
                {
                    string eleCopy = ele;
                    eleCopy += tempEle;
                    result.push_back(eleCopy);
                }
            }
        }
        else
        {
            result.assign(b.begin(), b.end());
        }
        return result;
    }
};

int main()
{
    string testCase = "23";
    vector<string> answer {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    Solution sol;
    vector<string> result = sol.letterCombinations(testCase);
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
