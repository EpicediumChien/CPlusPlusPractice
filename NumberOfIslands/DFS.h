#ifndef DFS_H  
#define DFS_H

#include <vector>

/* // Solution 1
class Solution {
private:
  void dfs(int i, int j, std::vector<std::vector<int>>& vis, std::vector<std::vector<char>>& grid, int m, int n) {
    if (i < 0 || j < 0 || i >= m || j >= n || vis[i][j] || grid[i][j] == '0') return;
    vis[i][j] = 1;
    dfs(i - 1, j, vis, grid, m, n);
    dfs(i, j + 1, vis, grid, m, n);
    dfs(i + 1, j, vis, grid, m, n);
    dfs(i, j - 1, vis, grid, m, n);
  }
public:
  int numIslands(std::vector<std::vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size(), island = 0;
    std::vector<std::vector<int>> vis(m, std::vector<int>(n, 0));
    for (int i = 0; i < m; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        if (!vis[i][j] && grid[i][j] == '1') {
          dfs(i, j, vis, grid, m, n);
          ++island;
        }
      }
    }
    return island;
  }
};
*/
// Solution 2
class Solution {
private:
  void dfs(int i, int j, std::vector<std::vector<char>>& grid) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') return;
    grid[i][j] = '0';
    dfs(i - 1, j, grid);
    dfs(i, j + 1, grid);
    dfs(i + 1, j, grid);
    dfs(i, j - 1, grid);
  }

public:
  int numIslands(std::vector<std::vector<char>>& grid) {
    int island = 0;
    for (int i = 0; i < grid.size(); ++i)
    {
      for (int j = 0; j < grid[0].size(); ++j)
      {
        if (grid[i][j] == '1') {
          dfs(i, j, grid);
          ++island;
        }
      }
    }
    return island;
  }
};

#endif DFS_H