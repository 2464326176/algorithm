//
// Created by 24643 on 2021/10/8.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
      if (nums.empty()) {
          return 0;
      }
      int i = 0;
      for (int k = 1; k < nums.size(); ++k) {
          if (nums[i] != nums[k]) {
              swap(nums[i + 1], nums[k]);
              ++i;
          }
      }
      return ++i;
  }
};

int main() {
    Solution S;
    vector<int> nums = {0, 0, 1, 2, 3, 4, 5, 6, 6};
    cout << S.removeDuplicates(nums) << endl;

    return 0;
}