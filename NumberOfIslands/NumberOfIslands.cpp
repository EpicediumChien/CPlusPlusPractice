#include <iostream>
#include <vector>
#include <string>
using namespace std;

class UnionFind {
public:
  UnionFind(vector<vector<char>>& grid)
  {
    count = 0;
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == '1') {
          parent.push_back(i * n + j);
          count++;
        }
        else
          parent.push_back(-1);
        rank.push_back(0);
      }
    }
  }

  int find(int i) {
    if (parent[i] != i) parent[i] = find(parent[i]);
    return parent[i];
  }

  int getCount() const {
    return count;
  }

  void Union(int x, int y)
  {
    int root_x = find(x);
    int root_y = find(y);
    if (root_x != root_y)
    {
      if (rank[root_x] > rank[root_y]) parent[root_y] = root_x;
      else if (rank[root_x] < rank[root_y]) parent[root_x] = root_y;
      else {
        parent[root_y] = root_x;
        rank[root_x]++;
      }
      --count;
    }
  }
private:
  vector<int> parent;
  vector<int> rank;
  int count;
};

class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    int nr = grid.size();
    if (!nr) return 0;
    int nc = grid[0].size();
    int offsets[] = { 0, 1, 0, -1, 0 };
    UnionFind uf(grid);
    for (int r = 0; r < nr; ++r)
    {
      for (int c = 0; c < nc; ++c)
      {
        if (grid[r][c] == '1')
        {
          grid[r][c] = 0;
          for (int k = 0; k < 4; k++)
          {
            int rr = r + offsets[k], cc = c + offsets[k + 1];
            if (rr >= 0 && rr < nr && cc >= 0 && cc <= nc && grid[rr][cc] == '1')
              uf.Union(r * nc + c, rr * nc + cc);
          }
        }
      }
    }
    return uf.getCount();
  }
};

int main()
{
  vector<vector<char>> grid = {
    { '1', '1', '1', '1', '0' },
    { '1', '1', '0', '1', '0' },
    { '1', '1', '0', '0', '0' },
    { '0', '0', '0', '0', '0' }
  };
  Solution sol;
  int result = sol.numIslands(grid);
  cout << result << endl;
}