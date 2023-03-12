//**************************
// Author:  yh
// Time:    2022/5/11
//**************************
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
  /*
   * [1, 2, 3]
   *      0           1           2
   *  0   123         213         321
   *  1   123         213         321
   *  2   132         231         312
   */
  void recursion(vector<vector<int> > &res, vector<int> &num, int index) {
      if (index == num.size() - 1) {
          res.push_back(num);
      } else {
          for (int i = index; i < num.size(); ++i) {
              swap(num[i], num[index]);  // i代表数字的位置 从0开始到结束 依次（i index）交换
              recursion(res, num, index + 1); // 递归
              swap(num[i], num[index]); // 回溯
          }
      }
  }

  vector<vector<int> > permute(vector<int> &num) {
      stable_sort(num.begin(), num.end());
      vector<vector<int>> res;
      recursion(res, num, 0);
      return res;
  }

/**
 *
 * @param n int整型
 * @return string字符串vector
 */
  void recursion(int left, int right, string temp, vector<string> &res, int n) {
      if ((left == n) && (right == n)) {
          res.push_back(temp);
      }

      if (left < n) {
          recursion(left + 1, right, temp + "(", res, n);
      }

      if (right < n && left > right) {
          recursion(left, right + 1, temp + ")", res, n);
      }

  }
  vector<string> generateParenthesis(int n) {
      vector<string> res;
      string temp;
      recursion(0, 0, temp, res, n);
      return res;
  }

  void recursion(vector<string> &res, string str, int pos) {
      if (pos == str.size() - 1) {
          res.push_back(str);
      } else {
          for (int i = pos; i < str.size(); ++i) {
              swap(str[i], str[pos]);
              recursion(res, str, pos + 1);
              swap(str[i], str[pos]);
          }
      }
  }
  vector<string> Permutation(string str) {
      vector<string> res;
      recursion(res, str, 0);
      return res;
  }

  void recursion(vector<vector<int> > &res, vector<int> &num, vector<int> &temp, vector<int> &vis) {
      if (temp.size() == num.size()) {
          res.push_back(temp);
          return;
      }

      for (int i = 0; i < num.size(); ++i) {
          if (vis[i]) {
              continue;
          }

          if (i > 0 && num[i - 1] == num[i] && !vis[i - 1]) {
              continue;
          }
          vis[i] = 1;
          temp.push_back(num[i]);
          recursion(res, num, temp, vis);
          vis[i] = 0;
          temp.pop_back();
      }
  }

  vector<vector<int> > permuteUnique(vector<int> &num) {
      stable_sort(num.begin(), num.end());
      vector<int> vis(num.size(), 0);
      vector<vector<int> > res;
      vector<int> temp;

      recursion(res, num, temp, vis);
      return res;
  }
};

int main() {
    vector<int> num{1, 1, 2};
    vector<vector<int>> res;

    Solution s;
    for (auto &val: s.permuteUnique(num)) {
        for (auto &v: val) {
            printf("%d ", v);
        }
        printf("\n");
    }

//    for(auto &val : s.generateParenthesis(2)) {
//        printf("%s\n", val.c_str());
//    }

//    for(auto &val : s.Permutation("abc")) {
//        printf("%s\n", val.c_str());
//    }
    return 0;
}