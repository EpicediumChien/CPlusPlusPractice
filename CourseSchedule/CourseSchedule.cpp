#include <iostream>
#include <vector>
//#include "BFS.h"
#include "DFS.h"

using namespace std;

int main()
{
  //int numCourses = 2;
  //vector<vector<int>> prerequisites = {{1,0}};

  int numCourses = 2;
  vector<vector<int>> prerequisites = { {1,0}, {0,1} };

  Solution sol;
  bool result = sol.canFinish(numCourses, prerequisites);
  string s = result ? "true" : "false";
  cout << s << endl;
}