// MergeKSortedLists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Example {
public:
    vector<vector<char>> example;
    bool result;
    Example(vector<vector<char>> ex, bool res) : example(ex), result(res) {}
};

class Solution {
public:
    vector<Example*> InitExamples()
    {
        vector<Example*> example;
        example.push_back(new Example(
            {
                {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
            },
            true  // <-- now pass true/false naturally
        ));
        return example;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> rowMasks(9, 0), colMasks(9, 0);
        vector<vector<int>> subbox(3, vector<int>(3, 0));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }

                int digit = board[i][j] - '0';
                int bit = (1 << digit);

                if ((rowMasks[i] & bit) ||
                    (colMasks[j] & bit) ||
                    (subbox[i / 3][j / 3] & bit)) {
                    return false;
                }

                rowMasks[i] |= bit;
                colMasks[j] |= bit;
                subbox[i / 3][j / 3] |= bit;
            }
        }

        return true;
    }
};

int main()
{
    Solution sol;
    vector<Example*> examples = sol.InitExamples();
    bool result = sol.isValidSudoku(examples[0]->example);
    if (result == examples[0]->result)
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
