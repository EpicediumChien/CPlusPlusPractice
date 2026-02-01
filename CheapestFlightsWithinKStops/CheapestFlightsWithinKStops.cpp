// CheapestFlightsWithinKStops.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int, int>>> adj(n);
    vector<int> price_map(n, INT_MAX);
    price_map[src] = 0;
    for (vector<int>& flightInfo : flights)
      adj[flightInfo[0]].push_back({ flightInfo[1], flightInfo[2] });

    queue<pair<int, int>> city_cost;
    city_cost.push({ src, 0 });
    int totalStops = 0;
    while (!city_cost.empty() && totalStops <= k) {
      int q_size = city_cost.size();
      while (q_size--) {
        auto [cur_city, cur_cost] = city_cost.front();
        city_cost.pop();
        for (pair<int, int>& edge : adj[cur_city]) {
          auto [dest, cost] = edge;
          if (cur_cost + cost < price_map[dest]) {
            price_map[dest] = cur_cost + cost;
            city_cost.push({ dest, price_map[dest] });
          }
        }
      }
      totalStops++;
    }
    return price_map[dst] == INT_MAX ? -1 : price_map[dst];
  }
};

void main()
{
  Solution sol;
  //int n = 4, src = 0, dst = 3, k = 1;
  //vector<vector<int>> flights = { {0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200} };
  //int n = 3, src = 0, dst = 2, k = 1;
  //vector<vector<int>> flights = { {0,1,100},{1,2,100},{0,2,500} };
  int n = 3, src = 0, dst = 2, k = 0;
  vector<vector<int>> flights = { {0,1,100},{1,2,100},{0,2,500} };


  int result = sol.findCheapestPrice(n, flights, src, dst, k);

  cout << result << endl;
  return;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
