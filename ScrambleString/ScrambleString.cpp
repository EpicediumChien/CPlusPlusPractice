// MergeKSortedLists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Example {
public:
    string s1;
    string s2;
    bool res;
    Example* next;
    Example(string string1, string string2, bool result) : s1(string1), s2(string2), res(result) {}
};

Example* InitExample() {
    Example* start = new Example("great", "rgeat", true);
    Example* cursor = start;
    cursor->next = new Example("abcde", "caebd", false);
    cursor = cursor->next;
    cursor->next = new Example("a", "a", true);

    return start;
}

class Solution {
private:
    static const int MAX = 30;
    int memo[MAX][MAX][MAX + 1];

    bool isScrambleHelper(const string& s1, int i1, const string& s2, int i2, int length) {
        if (memo[i1][i2][length] != -1)
            return memo[i1][i2][length] == 1;

        if (s1.compare(i1, length, s2, i2, length) == 0) {
            memo[i1][i2][length] = 1;
            return true;
        }

        int count[26] = { 0 };
        for (int i = 0; i < length; ++i) {
            count[s1[i1 + i] - 'a']++;
            count[s2[i2 + i] - 'a']--;
        }
        for (int i = 0; i < 26; ++i) {
            if (count[i] != 0) {
                memo[i1][i2][length] = 0;
                return false;
            }
        }

        for (int i = 1; i < length; ++i) {
            if ((isScrambleHelper(s1, i1, s2, i2, i) && isScrambleHelper(s1, i1 + i, s2, i2 + i, length - i)) ||
                (isScrambleHelper(s1, i1, s2, i2 + length - i, i) && isScrambleHelper(s1, i1 + i, s2, i2, length - i))) {
                memo[i1][i2][length] = 1;
                return true;
            }
        }
        memo[i1][i2][length] = 0;
        return false;
    }

public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        if (n != (int)s2.size()) return false;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                for (int k = 0; k <= n; ++k)
                    memo[i][j][k] = -1;

        return isScrambleHelper(s1, 0, s2, 0, n);
    }
};

int main()
{
    Example* exp = InitExample();
    Solution sol;
    while (exp != nullptr)
    {
        bool result = sol.isScramble(exp->s1, exp->s2);
        if (result != exp->res)
            cout << "Wrong on" << exp->s1 << exp->s2 << endl;
        exp = exp->next;
    }
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
