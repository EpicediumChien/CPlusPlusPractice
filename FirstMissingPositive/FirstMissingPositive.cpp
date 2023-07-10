// FirstMissingPositive.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int firstPositive = 1;
        sort(nums.begin(), nums.end());
        for (int num : nums)
        {
            if (num>0)
            {
                if(firstPositive==num)
                {
                    firstPositive++;
                }
                else if (firstPositive<num)
                {
                    return firstPositive;
                }
            }
        }

        return firstPositive;
    }
};

int main()
{
    vector<int> testCase {1, 2, 0};
    int answer = 3;
    Solution sol;
    cout << to_string(sol.firstMissingPositive(testCase));
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
