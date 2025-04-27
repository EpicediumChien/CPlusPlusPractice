// MergeKSortedLists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Example {
public:
    int example;
    int result;
    Example(int ex, int res) : example(ex), result(res) {}
};

class Solution {
private:
    void track_back(int& result_count, vector<int>& col, vector<int>& diag1, vector<int>& diag2, int i, int n)
    {
        if (i == n)  // All rows placed successfully
        {
            result_count++;
            return;
        }

        for (int j = 0; j < n; j++)
        {
            if (col[j] != 0 || diag1[i + j] != 0 || diag2[i - j + n - 1] != 0)
                continue;
            col[j] = diag1[i + j] = diag2[i - j + n - 1] = 1;
            track_back(result_count, col, diag1, diag2, i + 1, n);
            col[j] = diag1[i + j] = diag2[i - j + n - 1] = 0;
        }
    }
public:
    vector<Example*> InitExamples()
    {
        vector<Example*> example;
        example.push_back(new Example(4, 2));
        return example;
    }

    int totalNQueens(int n) {
        int result_count = 0;
        vector<int> col(n, 0);
        vector<int> diag1(2 * n - 1, 0);
        vector<int> diag2(2 * n - 1, 0);
        track_back(result_count, col, diag1, diag2, 0, n);
        return result_count;
    }
};

int main()
{
    Solution sol;
    vector<Example*> examples = sol.InitExamples();
    int result = sol.totalNQueens(examples[0]->example);
    if(result == examples[0]->result)
        cout << result << endl;
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
