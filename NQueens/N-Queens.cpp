// MergeKSortedLists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Example {
public:
    int example;
    vector<vector<string>> result;
    Example(int ex, vector<vector<string>> res) : example(ex), result(res) {}
};

class Solution {
public:
    vector<Example*> InitExamples()
    {
        vector<Example*> example;
        example.push_back(new Example(4, vector<vector<string>>{{ ".Q..", "...Q", "Q...", "..Q." }, { "..Q.", "Q...", "...Q", ".Q.." }}));
        return example;
    }

    void backtracking(vector<string>& board, vector<bool>& col, vector<bool>& d1, vector<bool>& d2, vector<vector<string>>& ans, int i, int n)
    {
        for (int j = 0; j < n; j++)
        {
            if (!col[j] && !d1[i - j + n - 1] && !d2[i + j])
            {
                col[j] = d1[i - j + n - 1] = d2[i + j] = true;
                board[i][j] = 'Q';
                if (i == n - 1)
                {
                    ans.push_back(board);
                    col[j] = d1[i - j + n - 1] = d2[i + j] = false;
                    board[i][j] = '.';
                    return;
                }
                backtracking(board, col, d1, d2, ans, i + 1, n);
                col[j] = d1[i - j + n - 1] = d2[i + j] = false;
                board[i][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<bool>col(n, false);
        vector<bool>d1(2 * n - 1, false);//i-j+n
        vector<bool>d2(2 * n - 1, false);//i+j-1
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        backtracking(board, col, d1, d2, ans, 0, n);
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<string>> result = sol.solveNQueens(4);
    string output = "[";
    for (vector<string>& board:result)
    {
        for (string row : board) {
            output += "[" + row + "],";
        }
        output = output.substr(0, output.size() - 1);
    }

    cout << output << "]";
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
