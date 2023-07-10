// TrappingRainWater.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/trapping-rain-water/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int leftTop = 0;
        int prevLeftTopIdx = 0;
        int leftIdx = 0;
        int rightTop = 0;
        int prevRightTopIdx = height.size() - 1;
        int rightIdx = height.size() - 1;
        int water = 0;
        while (leftIdx < rightIdx)
        {
            if (height[leftIdx] >= leftTop)
            {
                for (int i=prevLeftTopIdx+1; i < leftIdx; i++)
                {
                    water += min(height[prevLeftTopIdx], height[leftIdx]) - height[i];
                }
                prevLeftTopIdx = leftIdx;
                leftTop = height[leftIdx];
            }

            if (height[rightIdx] >= rightTop)
            {
                for (int i=prevRightTopIdx-1; i > rightIdx; i--)
                {
                    water += min(height[prevRightTopIdx], height[rightIdx]) - height[i];
                }
                prevRightTopIdx = rightIdx;
                rightTop = height[rightIdx];
            }

            if (height[prevLeftTopIdx] < height[prevRightTopIdx])
            {
                leftIdx++;
            }
            else if (height[prevLeftTopIdx] > height[prevRightTopIdx])
            {
                rightIdx--;
            }
            else
            {
                leftIdx++;
                rightIdx--;
            }
        }

        int edge = min(height[prevLeftTopIdx], height[prevRightTopIdx]);
        if (edge > 0)
        {
            while (prevLeftTopIdx < prevRightTopIdx)
            {
                if (edge > height[prevLeftTopIdx + 1])
                {
                    water += edge - height[prevLeftTopIdx + 1];
                }
                prevLeftTopIdx++;
            }
        }

        return water;
    }
};

int main()
{
    vector<int> testCase {6, 4, 2, 0, 3, 2, 0, 3, 1, 4, 5, 3, 2, 7, 5, 3, 0, 1, 2, 1, 3, 4, 6, 8, 1, 3};
    int answer = 83;
    //vector<int> testCase {5, 4, 1, 2};
    //int answer = 1;
    //vector<int> testCase {0, 2, 0};
    //int answer = 0;
    //vector<int> testCase {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    //int answer = 6;
    Solution sol;
    cout << sol.trap(testCase);
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
