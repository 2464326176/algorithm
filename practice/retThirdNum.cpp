//
// Created by 24643 on 2021/10/6.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool MyCompare(int &v1, int &v2) {
    return v1 > v2;
}

class Solution {
public:
  int thirdMax(vector<int> &nums) {
      if (nums.size() < 3) {
          return nums[0];
      }
      sort(nums.begin(), nums.end(), MyCompare);
      for (auto it: nums) {
          cout << it << " ";
      }
      vector<int> ret;
      ret.push_back(nums[0]);
      int k = 0;
      for (int i = 1; i < nums.size(); ++i) {
          if (ret[k] != nums[i]) {
              ret.push_back(nums[i]);
              ++k;
          }
          if (k == 2) {
              break;
          }
      }
      return ret[k];
  }
};

int main() {
    Solution s;
    vector<int> v = {1, 5, 9, 8, 98, 56};
    cout << s.thirdMax(v);
    return 0;
}