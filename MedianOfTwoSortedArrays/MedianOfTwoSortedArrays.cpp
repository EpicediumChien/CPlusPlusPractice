// MedianOfTwoSortedArrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/median-of-two-sorted-arrays/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const vector<int>& numsA = (nums1.size() <= nums2.size()) ? nums1 : nums2;
        const vector<int>& numsB = (nums1.size() > nums2.size()) ? nums1 : nums2;

        int m = numsA.size();
        int n = numsB.size();
        int imin = 0, imax = m;
        int half_len = (m + n + 1) / 2;

        while (imin <= imax) {
            int i = (imin + imax) / 2;
            int j = half_len - i;

            if (i < m && numsB[j - 1] > numsA[i]) {
                // i is too small
                imin = i + 1;
            }
            else if (i > 0 && numsA[i - 1] > numsB[j]) {
                // i is too big
                imax = i - 1;
            }
            else {
                // i is perfect
                int max_of_left = 0;
                if (i == 0) max_of_left = numsB[j - 1];
                else if (j == 0) max_of_left = numsA[i - 1];
                else max_of_left = max(numsA[i - 1], numsB[j - 1]);

                if ((m + n) % 2 == 1)
                    return max_of_left;

                int min_of_right = 0;
                if (i == m) min_of_right = numsB[j];
                else if (j == n) min_of_right = numsA[i];
                else min_of_right = min(numsA[i], numsB[j]);

                return (max_of_left + min_of_right) / 2.0;
            }
        }

        return 0.0; // should never be reached
    }
};

int main()
{
    vector<int> nums1 {1, 2};
    vector<int> nums2 {3, 4};
    double answer = 2.50000;
    //vector<int> nums1 {1, 3};
    //vector<int> nums2 {2};
    //double answer = 2.00000;
    Solution sol;
    double result = sol.findMedianSortedArrays(nums1, nums2);
    cout << result;
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
