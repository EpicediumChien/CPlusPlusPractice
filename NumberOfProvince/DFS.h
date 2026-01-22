#ifndef DFS_H
#define DFS_H

#include <vector>

class Solution {
private:
  void dfs(int cityFrom, std::vector<std::vector<int>>& isConnected, std::vector<bool>& vis, int cities) {
    vis[cityFrom] = true;
    for (int cityTo = 0; cityTo < cities; ++cityTo) {
      if (!vis[cityTo] && isConnected[cityFrom][cityTo] == 1) {
        isConnected[cityFrom][cityTo] = 0;
        dfs(cityTo, isConnected, vis, cities);
      }
    }
  }
public:
  int findCircleNum(std::vector<std::vector<int>>& isConnected) {
    int cities = isConnected.size(), provices = 0;
    std::vector<bool> vis(cities, false);
    for (int i = 0; i < cities; ++i) {
      if (!vis[i]) {
        dfs(i, isConnected, vis, cities);
        ++provices;
      }
    }
    return provices;
  }
};

#endif DFS_H
