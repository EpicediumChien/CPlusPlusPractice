#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    // 1. Build Adjacency List: adj[u] = list of {v, weight}
    vector<vector<pair<int, int>>> map(n + 1);
    for (vector<int>& time : times)
      map[time[0]].push_back({ time[1], time[2] });

    vector<int> distList(n + 1, INT_MAX);
    distList[k] = 0;

    // {weight, {parent, child}}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, k });

    while (!pq.empty()) {
      auto [dist, node] = pq.top();
      pq.pop();

      // Optimization: if we already found a shorter path to u, ignore this one
      if (dist > distList[node]) continue;

      for (auto& [child, childDist] : map[node]) {
        if ((distList[node] + childDist) < distList[child]) {
          distList[child] = distList[node] + childDist;
          pq.push({ distList[child], child });
        }
      }
    }

    int maxDist = *max_element(distList.begin() + 1, distList.end());
    return maxDist == INT_MAX ? -1 : maxDist;
  }
};

void main() {
  vector<vector<int>> times = { {2,1,1},{2,3,1},{3,4,1} };
  int n = 4, k = 2;
  Solution sol;
  int result = sol.networkDelayTime(times, n, k);

  cout << result << endl;
}