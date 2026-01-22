#ifndef UnionFind_H
#define UnionFind_H

#include <vector>
#include <numeric>

class UnionFind {
public:
  UnionFind(std::vector<std::vector<int>>& isConnected, int n) {
    count = n;
    parent.resize(n);
    rank.resize(n, 0);
    std::iota(parent.begin(), parent.end(), 0);
  }

  void united(int x, int y) {
    int root_x = find(x);
    int root_y = find(y);
    if (rank[root_x] > rank[root_y]) parent[root_y] = root_x;
    else if (rank[root_y] > rank[root_x]) parent[root_x] = root_y;
    else {
      parent[root_y] = root_x;
      ++rank[root_x];
    }
    --count;
  }

  int getCount() {
    return count;
  }
private:
  std::vector<int> parent;
  std::vector<int> rank;
  int count;
  int find(int n) {
    if (parent[n] != n)parent[n] = find(parent[n]);
    return parent[n];
  }
};

class Solution {
public:
  int findCircleNum(std::vector<std::vector<int>>& isConnected) {
    int n = isConnected.size();
    UnionFind uf(isConnected, n);
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (isConnected[i][j] == 1)
          uf.united(i, j);
      }
    }
    return uf.getCount();
  }
};

#endif UnionFind_H