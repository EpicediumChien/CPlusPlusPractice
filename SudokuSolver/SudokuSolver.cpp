// SudokuSolver.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/sudoku-solver/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
    bool Col[9][9];
    bool Row[9][9];
    bool Block[9][9];
    stack<pair<int, int>> uncertain;
private:
    void set3Con(int i, int j, int x, bool val)
    {
        Col[i][x] = val;
        Row[j][x] = val;
        Block[((i / 3) * 3 + j / 3)][x] = val;
    }

    void setBoard(vector<vector<char>>& board)
    {
        memset(Col, 0, sizeof(Col));
        memset(Row, 0, sizeof(Row));
        memset(Block, 0, sizeof(Block));
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.') continue;
                else
                {
                    int x = board[i][j] - '1';
                    set3Con(i, j, x, true);
                }
            }
        }
    }

    bool valid(int i, int j, int x)
    {
        return !Col[i][x] && !Row[j][x] && !Block[((i / 3) * 3 + j / 3)][x];
    }

    bool solve(vector<vector<char>>& board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    int x;
                    for (char c = '1'; c <= '9'; c++)
                    {
                        x = c - '1';
                        if (valid(i, j, x))
                        {
                            board[i][j] = c;
                            set3Con(i, j, x, true);
                            if (solve(board))
                            {
                                return solve(board);
                            }

                            //Backtracking
                            board[i][j] = '.';
                            set3Con(i, j, x, false);
                        }
                    }
                    return false;
                }
            }
        }

        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        setBoard(board);
        solve(board);
    }
};

int main()
{
    vector<vector<char>> testCase {
        { '5', '3', '.', '.', '7', '.', '.', '.', '.'}, 
        { '6', '.', '.', '1', '9', '5', '.', '.', '.' }, 
        { '.', '9', '8', '.', '.', '.', '.', '6', '.' }, 
        { '8', '.', '.', '.', '6', '.', '.', '.', '3' }, 
        { '4', '.', '.', '8', '.', '3', '.', '.', '1' }, 
        { '7', '.', '.', '.', '2', '.', '.', '.', '6' }, 
        { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
        { '.', '.', '.', '4', '1', '9', '.', '.', '5' }, 
        { '.', '.', '.', '.', '8', '.', '.', '7', '9' }
    };
    Solution sol;
    sol.solveSudoku(testCase);

    int i = 0;
    for (auto row : testCase)
    {
        int j = 0;
        for (auto num : row)
        {
            cout << " " << num;
            j++;
            if (j % 3 == 0
                && j != 9)
            {
                cout << " |";
            }
        }
        cout << endl;
        i++;
        if (i % 3 == 0
            && i != 9)
        {
            cout << "-------+-------+------" << endl;
        }
    }
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
