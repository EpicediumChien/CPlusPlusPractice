#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class UnionFind {
public:
  UnionFind(int n) {
    parent.resize(n + 1);
    rank.resize(n + 1, 0);
    iota(parent.begin(), parent.end(), 0);
  }

  bool unite(int x, int y) {
    int rootx = find(x);
    int rooty = find(y);
    if (rootx > rooty) parent[rootx] = rooty;
    else if (rootx < rooty) parent[rooty] = rootx;
    else
      return false;
    return true;
  }
private:
  vector<int> parent;
  vector<int> rank;
  int find(int n) {
    if (parent[n] != n) parent[n] = find(parent[n]);
    return parent[n];
  }
};

class Solution {
public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    UnionFind uf(n);
    for (const vector<int>& edge : edges) {
      if (!uf.unite(edge[0], edge[1]))
        return edge;
    }
    return {};
  }
};

int main()
{
  //vector<vector<int>> edges = { {1,2},{1,3},{2,3} };

  vector<vector<int>> edges = { {1,2},{2,3},{3,4},{1,4},{1,5} };

  Solution sol;
  vector<int> result = sol.findRedundantConnection(edges);
  cout << result[0] << " " << result[1] << endl;
}