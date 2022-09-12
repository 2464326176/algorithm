//
// Created by 24643 on 2021/10/7.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
  int majorityElement(vector<int> &nums) {
      if (nums.size() == 1) {
          return nums[0];
      }
      sort(nums.begin(), nums.end());
      int ret = nums[0];
      int m = 0;
      for (int i = 0; i < nums.size(); ++i) {
          int k = 1;
          while ((nums[i] == nums[++i]) && (i < nums.size())) {
              ++k;
          }
          if (m < k) {
              ret = nums[--i];
              m = k;
          }
          cout << "i: " << i << "ret: " << ret << endl;
      }
      return ret;
  }
};

int main() {
    vector<int> nums = {3, 3};
    Solution S;
    cout << S.majorityElement(nums);

    return 0;
}
