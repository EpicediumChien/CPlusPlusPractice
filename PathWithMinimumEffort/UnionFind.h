#ifndef UnionFind_H
#define UnionFind_H
#include <vector>
#include <numeric>
#include <algorithm>

class UnionFind {
  std::vector<int> parent, size;
public:
  UnionFind(int totalBlocks) {
    parent.resize(totalBlocks);
    size.resize(totalBlocks, 1);
    iota(parent.begin(), parent.end(), 0);
  }
  int find(int n) {
    if (parent[n] != n)parent[n] = find(parent[n]);
    return parent[n];
  }
  void unite(int x, int y) {
    int root_x = find(x);
    int root_y = find(y);
    if (root_x != root_y) {
      if (size[root_x] < size[root_y]) std::swap(root_x, root_y);
      parent[root_y] = root_x;
      size[root_x] += size[root_y];
    }
  }
};

class Solution {
public:
  int minimumEffortPath(std::vector<std::vector<int>>& heights) {
    int m = heights.size(), n = heights[0].size();
    if (m == 1 && n == 1)
      return 0;

    std::vector<std::vector<int>> edges;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int curId = i * n + j;
        if (i > 0) edges.push_back({ abs(heights[i][j] - heights[i - 1][j]),curId,(i - 1) * n + j });
        if (j > 0) edges.push_back({ abs(heights[i][j] - heights[i][j - 1]),curId,i * n + (j - 1) });
      }
    }

    sort(edges.begin(), edges.end());

    UnionFind uf(m * n);
    for (const std::vector<int>& edge : edges) {
      uf.unite(edge[1], edge[2]);
      if (uf.find(0) == uf.find(m * n - 1)) return edge[0];
    }

    return 0;
  }
};
#endif UnionFind_H