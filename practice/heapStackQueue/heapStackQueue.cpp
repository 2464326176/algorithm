//**************************
// Author:  yh
// Time:    2022/5/9
//**************************
#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>
#include <list>
using namespace std;

class Solution {
public:
  void push(int node) {
      stack1.push(node);
  }

  int pop() {
      int ret = 0;
      while (!stack1.empty()) {
          stack2.push(stack1.top());
          stack1.pop();
      }

      ret = stack2.top();
      stack2.pop();

      while (!stack2.empty()) {
          stack1.push(stack2.top());
          stack2.pop();
      }

      return ret;
  }

private:
  stack<int> stack1;
  stack<int> stack2;
};

class Solution1 {
public:
  void push(int value) {
      s.push(value);
  }

  void pop() {
      s.pop();
  }

  int top() {
      int value = s.top();
      s.pop();
      return value;
  }

  int min() {
      stack<int> temp(s);

      int min = temp.top();
      temp.pop();

      while (!temp.empty()) {
          if (min > temp.top()) {
              min = temp.top();
          }
          temp.pop();
      }

      return min;
  }

  bool isValid(string s) {
//        stack<char> sch;
//        for (auto &val: s) {
//            if (('{' == val) || ('[' == val) || ('(' == val)) {
//                sch.push(val);
//            }
//
//            if (('}' == val) || (']' == val) || (')' == val)) {
//                char symbol = (('}' == val) ? '{' :
//                              ((']' == val) ? '[' : '('));
//                stack<char> temp;
//                int ret = false;
//                while (!sch.empty()) {
//                    if (symbol == sch.top()) {
//                        ret = true;
//                        sch.pop();
//                        break;
//                    }
//                    temp.push(sch.top());
//                    sch.pop();
//                }
//
//                if(!ret) {
//                    return false;
//                }
//
//                while (!temp.empty()) {
//                    sch.push(temp.top());
//                    temp.pop();
//                }
//            }
//
//        }
//        return sch.empty();
      stack<char> sch;
      for (auto &val: s) {
          if (('{' == val)) {
              sch.push('}');
          } else if (('[' == val)) {
              sch.push(']');
          } else if (('(' == val)) {
              sch.push(')');
          } else if (sch.empty()) {
              return false;
          } else if (val == sch.top()) {
              sch.pop();
          }
      }
      return sch.empty();
  }

private:
  stack<int> s;
};

class Solution2 {
public:
  vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
      vector<int> ret;
      /*sort(input.begin(), input.end());
     for(int i = 0; i < k; ++i) {
         ret.push_back(input[i]);
     }*/

      if ((0 == k) || (0 == input.size())) {
          return ret;
      }

      // 大顶堆
      priority_queue<int> que;
      for (int i = 0; i < k; ++i) {
          que.push(input[i]);
      }

      for (int i = k; i < input.size() - 1; ++i) {
          if (que.top() > input[i]) {
              que.pop();
              que.push(input[i]);
          }
      }

      for (int i = 0; i < k; ++i) {
          ret.push_back(que.top());
          que.pop();
      }
      return ret;
  }
};

class Solution3 {
public:
  vector<int> val;

  void Insert(int num) {
      if (val.empty()) {
          val.push_back(num);
      } else {
          int i = 0;
          for (; i < val.size(); ++i) {
              if (num <= val[i]) {
                  break;
              }
          }
          val.insert(val.begin() + i, num);
      }
  }

  double GetMedian() {
      int n = val.size();
      if (n % 2) {
          return double(val[n / 2]);
      } else {
          double a = val[n / 2];
          return (double(val[n / 2]) + double(val[n / 2 - 1]));
      }
  }

};

void printStack(stack<int> s) {
    while (!s.empty()) {
        printf("%d ", s.top());
        s.pop();
    }
    printf("\n");
}

int main() {
    //Solution s1;
    Solution1 s1;

    s1.push(9);
    s1.push(5);
    s1.push(1);
    //printf("%d ", s1.pop());
    //printf("%d ", s1.pop());
    printf("%d ", s1.min());
    s1.push(0);
    printf("%d ", s1.min());
    s1.pop();
    printf("%d ", s1.min());
    s1.pop();
    printf("%d ", s1.min());

    printf("%d \n", s1.isValid("]"));
    return 0;
}