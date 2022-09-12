//**************************
// Author:  yh
// Time:    2022/5/6
//**************************

#include "Sort.h"

// 直接插入排序
class insertSort : public Sort {
public:
  void sortArray(int array[], int num) override {
      for (int i = 1; i < num; ++i) {
          int tmp = array[i];
          int j = i;
          while ((tmp < array[j - 1]) && (j > 0)) {
              array[j] = array[j - 1];
              --j;
          }
          array[j] = tmp;
      }
  }
};

//折半插入排序


//希尔排序


