#include <iostream>
#include <vector>
#include <string>
#include <queue>
//#include "UnionFind.h"
#include "DFS.h"
//#include "BFS.h"

using namespace std;

int main()
{
  //vector<vector<char>> grid = {
  //  { '1', '1', '1', '1', '0' },
  //  { '1', '1', '0', '1', '0' },
  //  { '1', '1', '0', '0', '0' },
  //  { '0', '0', '0', '0', '0' }
  //};
  //vector<vector<char>> grid = {
  //  { '1','1','0','0','0' },
  //  { '1','1','0','0','0' },
  //  { '0','0','1','0','0' },
  //  { '0','0','0','1','1' }
  //};
  vector<vector<char>> grid = {
  { '1','1','1' },
  { '0','1','0' },
  { '1','1','1' }
  };

  Solution sol;
  int result = sol.numIslands(grid);
  cout << result << endl;
}