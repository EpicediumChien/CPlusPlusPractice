// SearchInRotatedSortedArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/search-in-rotated-sorted-array

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Example {
public:
    vector<int> example;
    int target;
    int result;
    Example* next;
    Example(vector<int> ex, int target, int res) : example(ex), target(target), result(res) {}
};

class Solution {
public:
    Example* InitExamples()
    {
        Example* example = new Example({ 7, 0, 1, 2, 4, 5, 6 }, 0, 1);
        Example* cursor = example;
        cursor->next = new Example({ 4,5,6,7,0,1,2 }, 3, -1);
        cursor = cursor->next;
        cursor->next = new Example({ 1 }, 0, -1);
        cursor = cursor->next;
        cursor->next = new Example({ 1,3 }, 3, 1);
        return example;
    }

    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
                return mid;

            // Left part is sorted
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid])
                    right = mid - 1; // Move left
                else
                    left = mid + 1;  // Move right
            }
            // Right part is sorted
            else {
                if (nums[mid] < target && target <= nums[right])
                    left = mid + 1;  // Move right
                else
                    right = mid - 1; // Move left
            }
        }

        return -1;
    }
};

int main()
{
    Solution sol;
    Example* exampleInit = sol.InitExamples();
    while (exampleInit != NULL)
    {
        int result = sol.search(exampleInit->example, exampleInit->target);
        if (result != exampleInit->result)
        {
            cout << "Wrong answer at result " + to_string(result) + " answer " + to_string(exampleInit->result) + "\n";
            return 0;
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
