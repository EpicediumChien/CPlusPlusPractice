// ContainerWithMostWater.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxNumber = 0;
        int containResult = 0;
        int i = 0;
        int j = height.size() - 1;
        while (i < j)
        {
            maxNumber = max(maxNumber, min(height[i], height[j]) * (j - i));

            if (height[i] < height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }

        return maxNumber;
    }
};

int main()
{
    //vector<int> testCase {1, 1};
    //int answer = 1;
    vector<int> testCase {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int answer = 49;
    Solution sol;
    cout << to_string(sol.maxArea(testCase));
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
