// Combinations.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/combinations/

#include <vector>
#include <string>
#include "Combinations.h"
#include <iostream>

using namespace std;
class Example {
public:
    int n, k;
    string expected;
    Example* next;
    Example(int n_val, int k_val, string exp_val) : n(n_val), k(k_val), expected(exp_val)
        , next(nullptr) {}
};

Example* InitialExamples() {
    Example* start = new Example(4, 2, "[[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]");
    Example* cursor = start;
    cursor->next = new Example(1, 1, "[[1]]");
    return start;
}

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;
        backtrack(1, n, k, path, res);
        return res;
    }

    void backtrack(int start, int n, int k, vector<int>& path, vector<vector<int>>& res) {
        if (k == 0) {
            res.push_back(path);
            return;
        }
        for (int i = start; i <= n - k + 1; ++i) {  // Prune: need k elements
            path.push_back(i);
            backtrack(i + 1, n, k - 1, path, res);
            path.pop_back();  // backtrack
        }
    }
};

void main()
{
    Solution sol;
    Example* example = InitialExamples();
    while (example != nullptr)
    {
        vector<vector<int>> result = sol.combine(example->n, example->k);
        string string_res = "[";
        for (const vector<int> path: result) {
            string_res += "[";
            for (const int num: path) {
                string_res += std::to_string(num);
                string_res += ",";
            }
            string_res = string_res.substr(0, string_res.size() - 1);
            string_res += "],";
        }
        string_res = string_res.substr(0, string_res.size() - 1);
        string_res += "]";
        if (example->expected != string_res)
            cout << string_res << endl;
        example = example->next;
    }
    return;
}