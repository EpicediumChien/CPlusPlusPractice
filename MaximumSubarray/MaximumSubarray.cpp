// CPlusPlusPractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/maximum-subarray

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Example {
public:
    vector<int> example;
    int result;
    Example* next;
    Example(vector<int> ex, int res) : example(ex), result(res) {}
};

class Solution {
public:
    Example* example;
    Example* InitExamples()
    {
        example = new Example({ -2, 1, -3, 4, -1, 2, 1, -5, 4 }, 6);
        Example* cursor = example;
        cursor->next = new Example({ 1 }, 1);
        cursor = cursor->next;
        cursor->next = new Example({ 5, 4, -1, 7, 8 }, 23);
    }

    int maxSubArray(vector<int>& nums) {
        int tempSum = 0;
        int maxSum = -10000;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= 0)
            {
                if (tempSum <= 0)
                {
                    tempSum = nums[i];
                }
                else
                {
                    tempSum += nums[i];
                }
            }
            else if (nums[i] < 0)
            {
                if (tempSum + nums[i] <= 0)
                {
                    tempSum = nums[i];
                }
                else
                {
                    tempSum += nums[i];
                }
            }

            if (tempSum > maxSum)
            {
                maxSum = tempSum;
            }
        }

        return maxSum;
    }
};

int main()
{
    Solution sol;
    Example* exampleInit = sol.InitExamples();
    while (exampleInit!=NULL)
    {
        int result = sol.maxSubArray(exampleInit->example);
        while (result!=NULL)
        {//result
            if (result != exampleInit->result)
            {
                cout << "Wrong answer at result " + to_string(result) + " answer " + to_string(exampleInit->result) + "\n";
                return 0;
            }
        }
        exampleInit = exampleInit->next;
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
