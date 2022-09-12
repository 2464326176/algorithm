//
// Created by 24643 on 2021/10/7.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
  int singleNumber(vector<int> &nums) {
      sort(nums.begin(), nums.end());
      int i = 0;
      if (nums.size() == 1) {
          return nums[0];
      }

      if ((nums[0] != nums[1]) && (nums[2] == nums[1])) {
          return nums[0];
      }

      if ((nums[nums.size() - 1] != nums[nums.size() - 2]) && (nums[nums.size() - 3] == nums[nums.size() - 2])) {
          return nums[nums.size() - 1];
      }
      for (i = 1; i < nums.size(); ++i) {
          if ((nums[i] != nums[i + 1]) && (nums[i] != nums[i - 1])) {
              break;
          }
      }
      return nums[i];
  }
};

int main() {
    Solution s;
    vector<int> nums = {1, 3, 1, -1, 3};
    cout << s.singleNumber(nums) << endl;

    return 0;
}
