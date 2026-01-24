#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> courseMap(numCourses);
    vector<int> indegree(numCourses, 0);
    for (const vector<int>& relation : prerequisites) {
      int course = relation[0], prerequisite = relation[1];
      courseMap[prerequisite].push_back(course);
      ++indegree[course];
    }

    queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
      if (indegree[i] == 0)
        q.push(i);
    }

    vector<int> courseBucket;
    while (!q.empty()) {
      int curCourse = q.front();
      courseBucket.push_back(curCourse);
      q.pop();

      for (int fullFilledCourse : courseMap[curCourse]) {
        --indegree[fullFilledCourse];
        if (indegree[fullFilledCourse] == 0)
          q.push(fullFilledCourse);
      }
    }

    if (courseBucket.size() != numCourses)
      return {};

    return courseBucket;
  }
};

int main()
{
  //int numCourses = 2;
  //vector<vector<int>> prerequisites = {{1,0}};

  int numCourses = 4;
  vector<vector<int>> prerequisites = { {1,0},{2,0},{3,1},{3,2} };

  //int numCourses = 2;
  //vector<vector<int>> prerequisites = { {1,0}, {0,1} };

  Solution sol;
  vector<int> result = sol.findOrder(numCourses, prerequisites);
  for (int& course : result) {
    cout << course << " ";
  }
}