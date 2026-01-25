#ifndef BFS_H
#define BFS_H
#include <vector>
#include <queue>

class Solution {
public:
  int minimumEffortPath(std::vector<std::vector<int>>& heights) {
    int m = heights.size(), n = heights[0].size();

    std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>, std::greater<std::pair<int, std::pair<int, int>>>> pq;
    pq.push({ 0,{0,0} });

    // Distance array (effort array) initialized to infinity
    std::vector<std::vector<int>> dist(m, std::vector<int>(n, INT_MAX));
    std::vector<int> offsets = { 0,1,0,-1,0 };
    while (!pq.empty()) {
      auto [effort, pos] = pq.top();
      auto [cur_r, cur_c] = pos;
      pq.pop();
      if (cur_r == m - 1 && cur_c == n - 1) return effort;
      if (effort > dist[cur_r][cur_c]) continue;

      for (int k = 0; k < 4; ++k) {
        int tar_r = cur_r + offsets[k];
        int tar_c = cur_c + offsets[k + 1];
        if (tar_r >= 0 && tar_c >= 0 && tar_r < m && tar_c < n) {
          int maxEffort = std::max(effort, abs(heights[cur_r][cur_c] - heights[tar_r][tar_c]));
          if (maxEffort < dist[tar_r][tar_c]) {
            dist[tar_r][tar_c] = maxEffort;
            pq.push({ maxEffort, {tar_r, tar_c} });
          }
        }
      }
    }
    return 0;
  }
};
#endif BFS_H