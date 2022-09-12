//
// Created by 24643 on 2021/10/18.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int dynamicProgram(vector<int> &nums) {
      if (nums.empty()) {
          return 0;
      }
      if (nums.size() == 1) {
          return nums[0];
      }
      int first = nums[0];
      int second = max(nums[0], nums[1]);

      for (int i = 2; i < nums.size(); ++i) {
          int tmp = second;
          second = max(second, first + nums[i]);
          first = tmp;
      }
      return second;
  }

  int climbStairs(int n) {
      if (n = 0) {
          return 0;
      }
      if (n = 1) {
          return 1;
      }
      int first = 1;
      int second = 2;
      for (int i = 2; i < n; ++i) {

      }
  }

  int minimumTotal(vector<vector<int>> &triangle) {
      if (triangle.empty()) {
          return 0;
      }
      for (int i = 1; i < triangle.size(); ++i) {
          triangle[i][0] = triangle[i - 1][0] + triangle[i][0];
          for (int j = 1; j < i; ++j) {
              triangle[i][j] = min(triangle[i - 1][j - 1], triangle[i - 1][j]) + triangle[i][j];
          }
          triangle[i][i] = triangle[i - 1][i - 1] + triangle[i][i];
      }
      return *min_element(triangle[triangle.size() - 1].begin(), triangle[triangle.size() - 1].end());
  }
};

int main() {
    Solution s;
    //vector<int> nums = {1, 3, 1, 2, 15,  6};
    //cout << "nums total: " << s.dynamicProgram(nums);
    //cout << s.climbStairs(5) << endl;

    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << s.minimumTotal(triangle) << endl;
    return 0;
}
