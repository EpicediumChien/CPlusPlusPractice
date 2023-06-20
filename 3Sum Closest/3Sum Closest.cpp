// 3Sum Closest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2];
        int dist = closest - target;
        int curDist = dist;
        if (dist < 0) { dist *= -1; }
        for (int i = 0; i < nums.size() - 2; i++)
        {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k)
            {
                int threeSum = nums[i] + nums[j] + nums[k];
                if (threeSum == target)
                {
                    curDist = 0;
                    return nums[i] + nums[j] + nums[k];
                }
                else if (threeSum > target)
                {
                    curDist = nums[i] + nums[j] + nums[k] - target;
                    k--;
                }
                else
                {
                    curDist = target - nums[i] - nums[j] - nums[k];
                    j++;
                }

                if (curDist < dist)
                {
                    closest = threeSum;
                    dist = curDist;
                }
            }
        }
        return closest;
    }
};

int main()
{
    vector<int> testCase {-1, 2, 1, -4};
    int target = 1;
    int answer  = 0;
    Solution sol;
    int result = sol.threeSumClosest(testCase, target);
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
