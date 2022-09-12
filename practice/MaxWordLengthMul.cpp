//
// Created by 24643 on 2021/10/6.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

bool MyCampare(string v1, string v2) {
    return v1.size() > v2.size();
}

class Solution {
public:
  int maxProduct(vector<string> &words) {
      int *mask = new int[words.size()];
      memset(mask, 0, sizeof(int) * words.size());

      for (int i = 0; i < words.size(); ++i) {
          for (auto it: words[i]) {
              mask[i] |= 1 << (it - 'a');
          }
      }

      int ret = 0;
      for (int i = 0; i < words.size() - 1; ++i) {
          for (int j = words.size() - 1; j > i; --j) {
              if (!(mask[i] & mask[j])) {
                  int tmp = words[i].size() * words[j].size();
                  ret = max(tmp, ret);
              }
          }
      }
      return ret;
  }
  bool subStr(string s1, string s2) {
      string s3;
      set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s3, s3.begin()));
      if (s3.empty()) {
          return true;
      }
      return false;
  }
};

int main() {
    Solution s;
    vector<string> wd = {"lyh", "uiop", "zxczvb", "qwert"};
    cout << s.maxProduct(wd) << endl;

    return 0;
}