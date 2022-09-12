//
// Created by 24643 on 2021/10/7.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
      vector<vector<int>> ret;
      if (nums.empty()
          || (nums.size() < 3)) {
          return ret;
      }
      sort(nums.begin(), nums.end());
      if ((nums[0] * (nums[nums.size() - 1])) < 0) {
          for (int i = 0; i < nums.size(); ++i) {
              int flag = i;
              while (nums[flag] == nums[++flag] && (flag < nums.size()));
              int k = i + 1;
              int m = nums.size() - 1;
              while (k < m) {
                  int tmp = nums[i] + nums[k] + nums[m];
                  if (tmp == 0) {
                      vector<int> tmp = {nums[i], nums[k], nums[m]};
                      ret.push_back(tmp);
                      while (nums[k] == nums[++k] && (k < m));
                  }
                  if (tmp > 0) {
                      while (nums[m] == nums[--m]);
                  } else if (tmp < 0) {
                      while (nums[k] == nums[++k]);
                  }
              }
              i = flag - 1;
          }
      } else if ((nums[0] == nums[nums.size() - 1]) && (nums[0] == 0)) {
          vector<int> tmp = {0, 0, 0};
          ret.push_back(tmp);
      }
      for (auto it: ret) {
          for (auto tit: it) {
              cout << tit << " ";
          }
          cout << "\n";
      }
      return ret;
  }

};

int main() {
    Solution S;
    vector<int> nums = {1, 2, -2, -1};
    cout << nums.size() << endl;
    S.threeSum(nums);
    return 0;
}