#include <iostream>

class Solution {
public:
  double myPow(double x, int n) {
      if (n < 0) {
          return 1 / Pow(x, -n);
      }

      return Pow(x, n);
  }

  double Pow(double x, int n) {
      if (0 == n) {
          return 1;
      }

      double midNum = Pow(x, n / 2);

      if (0 == (n % 2)) {
          return midNum * midNum;
      } else {
          return x * midNum * midNum;
      }
  }
};

int main() {
    Solution su;
    std::cout << su.myPow(2, -3) << std::endl;

    return 0;
}

