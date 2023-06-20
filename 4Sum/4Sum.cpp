// 4Sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> s;
        vector<vector<int>> result;
        if (nums.size() >= 4) {
            sort(nums.begin(), nums.end());
            for (int i = 0; i < nums.size() - 2; i++)
            {
                for (int l = nums.size() - 1; l > i + 2; l--)
                {
                    int j = i + 1;
                    int k = l - 1;
                    while (j < k)
                    {
                        if (summationOverflowCheck(nums[i], nums[j]) == 0
                            && summationOverflowCheck(nums[i] + nums[j], nums[k]) == 0
                            && summationOverflowCheck(nums[i] + nums[j] + nums[k], nums[l]) == 0)
                        {
                            int sum = nums[i] + nums[j] + nums[k] + nums[l];
                            if (sum == target)
                            {
                                vector<int> ansV {nums[i], nums[j], nums[k], nums[l]};

                                if (s.size() == 0
                                    || std::find(result.begin(), result.end(), ansV) == result.end())
                                {
                                    s.insert({ nums[i], nums[j], nums[k], nums[l] });
                                }
                                j++;
                                k--;
                            }
                            else if (sum < target)
                            {
                                j++;
                            }
                            else
                            {
                                k--;
                            }
                        }
                        else
                        {
                            if (summationOverflowCheck(nums[i], nums[j]) == 0)
                            {
                                if (summationOverflowCheck(nums[i] + nums[j], nums[k]) == 0)
                                {
                                    if (summationOverflowCheck(nums[i] + nums[j] + nums[k], nums[l]) > 0)
                                    {
                                        k--;
                                    }
                                    else
                                    {
                                        j++;
                                    }
                                }
                                else if (summationOverflowCheck(nums[i] + nums[j], nums[k]) > 0)
                                {
                                    k--;
                                }
                                else
                                {
                                    j++;
                                }
                            }
                            else if (summationOverflowCheck(nums[i], nums[j]) > 0)
                            {
                                k--;
                            }
                            else
                            {
                                j++;
                            }
                        }
                    }
                }
            }
            for (auto quadruplets : s)
                result.push_back(quadruplets);
        }
        return result;
    }

private:
    bool summationOverflowCheck(int a, int b)
    {
        if (b > 0 && a > std::numeric_limits<int>::max() - b)
            return 1;

        if (b < 0 && a < std::numeric_limits<int>::min() - b)
            return -1;
        return 0;
    }
};

int main()
{
    vector<int> testCase {1000000000, 1000000000, 1000000000, 1000000000};
    int target = 0;
    vector<vector<int>> answer {};
    Solution sol;
    vector<vector<int>> result = sol.fourSum(testCase, target);
    string output = "[";
    for (auto sumV : result)
    {
        output += "[";
        for (auto ele : sumV)
        {
            output += to_string(ele) + ", ";
        }
        if (output.substr(output.length() - 2, 2) == ", ")
        {
            output = output.substr(0, output.length() - 2);
        }
        output += "], ";
    }
    if (output.size() != 1 && output.substr(output.length() - 2, 2) == ", ")
    {
        output = output.substr(0, output.length() - 2);
    }
    output += "]";
    cout << output;
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
