#ifndef DFS_H
#define DFS_H
#include <vector>

class Solution {
private:
  // hasCircle
  bool dfs(int course, std::vector<std::vector<int>>& courseMap, std::vector<int>& state) {
    if (state[course] == 1) return true;
    if (state[course] == 2) return false;
    state[course] = 1;
    for (auto& availableCourse : courseMap[course]) {
      if (dfs(availableCourse, courseMap, state))
        return true;
    }
    state[course] = 2;
    return false;
  }
public:
  bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
    std::vector<std::vector<int>> courseMap(numCourses);
    // 0 = unvisited, 1 = visiting, 2 = visited
    std::vector<int> state(numCourses, 0);
    for (auto& relation : prerequisites)
      courseMap[relation[0]].push_back(relation[1]);

    for (int i = 0; i < numCourses; ++i) {
      if (state[i] == 0) {
        if (dfs(i, courseMap, state)) {
          return false;
        }
      }
    }
    return true;
  }
};
#endif DFS_H