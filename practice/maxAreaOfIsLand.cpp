//
// Created by 24643 on 2021/10/16.
//
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
class Solution {
public:
  int IsLandDfs(vector<vector<int>> &grid, int x, int y) {
      if ((x < 0) || (y < 0) || (x >= grid.size()) || (y >= grid[0].size()) || (grid[x][y] == 0)) {
          return 0;
      }
      grid[x][y] = 0;
      int dx[] = {0, 0, 1, -1};
      int dy[] = {1, -1, 0, 0};
      int ret = 1;
      for (int index = 0; index < 4; ++index) {
          int next_x = x + dx[index], next_y = y + dy[index];
          ret += IsLandDfs(grid, next_x, next_y);
      }
      return ret;
  }

  int maxAreaOfIsland(vector<vector<int>> &grid) {
      int ret = 0;
      for (int i = 0; i < grid.size(); ++i) {
          for (int j = 0; j < grid[0].size(); ++j) {
              ret = max(ret, IsLandDfs(grid, i, j));
          }
      }
      return ret;
  }
};

int main() {
    vector<vector<int>> land = {
        {1, 1, 0, 1, 1},
        {0, 1, 0, 1, 1},
        {1, 0, 0, 1, 0},
        {1, 1, 1, 0, 0},
        {1, 1, 1, 1, 1}
    };
    Solution s;
    cout << s.maxAreaOfIsland(land);

    return 0;
}