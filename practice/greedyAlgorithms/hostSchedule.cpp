/*
 * @Author: yh
 * @Date: 2022-08-31 22:42:00
 * @LastEditTime: 2022-08-31 23:11:29
 * @Description: 
 * @FilePath: \algorithm\practice\greedyAlgorithms\hostSchedule.cpp
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   *
   * 计算成功举办活动需要多少名主持人
   * @param n int整型 有n个活动
   * @param startEnd int整型vector<vector<>> startEnd[i][0]用于表示第i个活动的开始时间，startEnd[i][1]表示第i个活动的结束时间
   * @return int整型
   */
  int minmumNumberOfHost(int n, vector<vector<int>> &startEnd) {
      vector<int> vStart, vEnd;
      int ret = 0, j = 0;
      for (auto it: startEnd) {
          vStart.push_back(it[0]);
          vEnd.push_back(it[1]);
      }

      std::sort(vStart.begin(), vStart.end());
      std::sort(vEnd.begin(), vEnd.end());

      for (int i = 0; i < n; ++i) {
          if (vStart[i] >= vEnd[j]) {
              ++j;
          } else {
              ++ret;
          }
      }

      return ret;
  }
};

int main() {
    Solution s;
    vector<vector<int>> vec{
        {1, 3},
        {2, 5},
        {3, 4},
        {4, 6}
    };

    cout << s.minmumNumberOfHost(4, vec);

    return 0;
}
