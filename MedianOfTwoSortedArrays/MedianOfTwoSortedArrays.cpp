// MedianOfTwoSortedArrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/median-of-two-sorted-arrays/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double midian = 0;
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        if (nums1.size() % 2 == 0)
        {
            int mid1 = nums1.size() / 2;
            int mid2 = mid1 - 1;
            midian = (((double)nums1[mid1] + (double)nums1[mid2]) / 2);
        }
        else
        {
            int mid = nums1.size() / 2;
            midian = nums1[mid];
        }

        return midian;
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
