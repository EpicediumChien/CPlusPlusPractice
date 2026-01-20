#ifndef BFS_H
#define BFS_H

#include <vector>
#include <queue>

class Solution {
private:
  void bfs(int i, int j, std::vector<std::vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    std::queue<std::pair<int, int>> q;
    q.push({ i, j });
    grid[i][j] = '0';

    std::vector<int> offsets = { 0,1,0,-1,0 };
    while (!q.empty()) {
      auto [curr_r, curr_c] = q.front();
      q.pop();

      for (int k = 0; k < 4; ++k) {
        int nr = curr_r + offsets[k];
        int nc = curr_c + offsets[k + 1];
        if (nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] == '1') {
          q.push({ nr, nc });
          grid[nr][nc] = '0';
        }
      }
    }
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') return;
  }

public:
  int numIslands(std::vector<std::vector<char>>& grid) {
    int island = 0;
    for (int i = 0; i < grid.size(); ++i)
    {
      for (int j = 0; j < grid[0].size(); ++j)
      {
        if (grid[i][j] == '1') {
          bfs(i, j, grid);
          ++island;
        }
      }
    }
    return island;
  }
};
#endif BFS_H