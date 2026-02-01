// LongestIncreasingPathInAMatrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Longest Increasing Path in a Matrix
// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  int memo[201][201];
  int DFS(int i, int j,
    vector<vector<int>>& matrix,
    int m, int n) {
    if (memo[i][j] != 0) return memo[i][j];
    int maxLen = 1;

    if (i - 1 >= 0 && matrix[i - 1][j] > matrix[i][j])
      maxLen = max(maxLen, 1 + DFS(i - 1, j, matrix, m, n));
    if (j - 1 >= 0 && matrix[i][j - 1] > matrix[i][j])
      maxLen = max(maxLen, 1 + DFS(i, j - 1, matrix, m, n));
    if (i + 1 < m && matrix[i + 1][j] > matrix[i][j])
      maxLen = max(maxLen, 1 + DFS(i + 1, j, matrix, m, n));
    if (j + 1 < n && matrix[i][j + 1] > matrix[i][j])
      maxLen = max(maxLen, 1 + DFS(i, j + 1, matrix, m, n));

    return memo[i][j] = maxLen;
  }
public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size(), result = 0;
    memset(memo, 0, sizeof(memo));

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        result = max(result, DFS(i, j, matrix, m, n));
      }
    }
    return result;
  }
};

void main()
{
  Solution sol;
  vector<vector<int>> matrix = { {9,9,4},{6,6,8},{2,1,1} };


  int result = sol.longestIncreasingPath(matrix);

  cout << result << endl;
  return;
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
