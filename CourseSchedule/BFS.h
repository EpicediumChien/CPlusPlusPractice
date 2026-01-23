#ifndef BFS_H
#define BFS_H
#include <vector>
#include <queue>

class Solution {
public:
  bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
    std::vector<std::vector<int>> courseMap(numCourses);
    std::vector<int> indegree(numCourses, 0);
    for (auto& relation : prerequisites) {
      int course = relation[0], prerequisite = relation[1];
      courseMap[prerequisite].push_back(course);
      ++indegree[course];
    }

    std::queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
      if (indegree[i] == 0)
        q.push(i);
    }

    int coursesProcessed = 0;
    while (!q.empty()) {
      int curCourse = q.front();
      q.pop();
      ++coursesProcessed;

      for (int availableCourse : courseMap[curCourse]) {
        --indegree[availableCourse];
        if (indegree[availableCourse] == 0)
          q.push(availableCourse);
      }
    }

    return coursesProcessed == numCourses;
  }
};
#endif BFS_H