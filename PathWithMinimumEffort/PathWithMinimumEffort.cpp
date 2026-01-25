#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <queue>
//#include "BFS.h"
#include "UnionFind.h"

using namespace std;

int main()
{
  vector<vector<int>> heights = { {1,2,2},{3,8,2},{5,3,5} };

  Solution sol;
  int result = sol.minimumEffortPath(heights);
  cout << result << endl;
}