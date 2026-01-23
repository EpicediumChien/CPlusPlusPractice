#include <iostream>
#include <vector>
#include <numeric>
//#include "DFS.h"
#include "UnionFind.h"

using namespace std;

int main()
{
  //vector<vector<int>> grid = {
  //{ 1,1,0 },
  //{ 1,1,0 },
  //{ 0,0,1 }
  //};

  vector<vector<int>> grid = {
  { 1,0,0,1 },
  { 0,1,1,0 },
  { 0,1,1,1 },
  { 1,0,1,1 }
  };

  Solution sol;
  int result = sol.findCircleNum(grid);
  cout << result << endl;
}