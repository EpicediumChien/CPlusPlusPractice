// ReverseNodesInK-Group.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Example {
public:
    string romanNum;
    int res;
    Example* next;
    Example(string ro, int r) : romanNum(ro), res(r), next(nullptr) {}
};

Example* initialExample() {
    Example* start = new Example("MMCCCXCIX", 2399);
    Example* cursor = start;
    cursor->next = new Example("DCXXI", 621);

    return start;
}

class Solution {
public:
    int romanToInt(string s) {
        int value = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'I') {
                if ((i + 1) < s.length() && s[i + 1] == 'V') {
                    value += 4;
                    i++;
                    continue;
                }
                else if ((i + 1) < s.length() && s[i + 1] == 'X') {
                    value += 9;
                    i++;
                    continue;
                }
                else {
                    value += 1;
                }
            }
            else if (s[i] == 'V') {
                value += 5;
            }
            else if (s[i] == 'X') {
                if ((i + 1) < s.length() && s[i + 1] == 'L') {
                    value += 40;
                    i++;
                    continue;
                }
                else if ((i + 1) < s.length() && s[i + 1] == 'C') {
                    value += 90;
                    i++;
                    continue;
                }
                else {
                    value += 10;
                }
            }
            else if (s[i] == 'L') {
                value += 50;
            }
            else if (s[i] == 'C') {
                if ((i + 1) < s.length() && s[i + 1] == 'D') {
                    value += 400;
                    i++;
                    continue;
                }
                else if ((i + 1) < s.length() && s[i + 1] == 'M') {
                    value += 900;
                    i++;
                    continue;
                }
                else {
                    value += 100;
                }
            }
            else if (s[i] == 'D') {
                value += 500;
            }
            else if (s[i] == 'M') {
                value += 1000;
            }
        }
        return value;
    }
};

int main()
{
    Example* exp = initialExample();
    Solution sol;
    while (exp != NULL)
    {
        int result = sol.romanToInt(exp->romanNum);
        if(result != exp->res)
            cout << std::to_string(result) << endl;
        exp = exp->next;
    }
}