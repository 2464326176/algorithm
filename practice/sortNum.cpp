//
// Created by 24643 on 2021/10/6.
//
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
  int factorialNum(int n) {
      if (n == 1) {
          return 1;
      }
      return n * factorialNum(n - 1);
  }

  string getPermutation(int n, int k) {
      int tmpNum = factorialNum(n - 1);
      int high = n - 1;
      int low = 0;
      int flag = 0;
      while (1) {
          if (high > low) {
              int mid = (high + low) / 2;
              if (mid * tmpNum >= k) {
                  high = mid - 1;
                  if ((mid - 1) * tmpNum < k) {
                      flag = k - mid * tmpNum;

                  }
              }

              if (mid * tmpNum < k) {
                  low = mid + 1;
                  if ((mid + 1) * tmpNum >= k) {
                      flag = k - (mid - 1) * tmpNum;
                  }
              }

          }
      }
  }
};
