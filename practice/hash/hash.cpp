//**************************
// Author:  yh
// Time:    2022/5/10
//**************************
#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <iomanip>

using namespace std;

class Solution {
public:
  /**
   *
   * @param numbers int整型vector
   * @param target int整型
   * @return int整型vector
   */
  vector<int> twoSum(vector<int> &numbers, int target) {
      vector<int> res;
      unordered_map<int, int> hash;

      for (int i = 0; i < numbers.size(); ++i) {
          int temp = target - numbers[i];
          if (hash.find(temp) == hash.end()) {
              hash[numbers[i]] = i;
          } else {
              res.push_back(hash[temp] + 1);
              res.push_back(i + 1);
          }
      }

      return res;
  }

  int MoreThanHalfNum_Solution(vector<int> numbers) {
      unordered_map<int, int> hash;

      for (int i = 0; i < numbers.size(); ++i) {
          hash[numbers[i]]++;
          if (hash[numbers[i]] > numbers.size() / 2) {
              return numbers[i];
          }
      }
      return 0;
  }
};

int main() {
    int i = 7890;
    cout << setw(6) << i << endl;
    cout << i << endl;

    return 0;
}


