//**************************
// Author:  yh
// Time:    2022/5/10
//**************************
#include "Sort.h"
//冒泡排序
class BubbleSort : public Sort {
public:
  void sortArray(int array[], int num) {
      bool flag = true;
      for (int i = num - 1; i > 0; --i) {
          for (int j = 0; j < i; ++j) {
              if (array[j + 1] < array[j]) {
                  int temp = array[j + 1];
                  array[j + 1] = array[j];
                  array[j] = temp;
                  flag = false;
              }
          }

          if (flag) {
              return;
          }
      }
      return;
  }
};

//快速排序
class QuickSort : public Sort {
public:

  void quickSort(int *array, int low, int high) {
      int i = low, j = high;

      if (low < high) {
          int temp = array[low];
          while (i < j) {
              // 从右向左找 找到一个小于temp的
              while ((i < j) && array[j] >= temp) {
                  --j;
              }

              if (i < j) {
                  array[i] = array[j];
                  ++i;
              }
              // 从左向右找 找到一个大于temp的
              while ((i < j) && array[i] < temp) {
                  ++i;
              }

              if (i < j) {
                  array[j] = array[i];
                  --j;
              }
          }
          // 第一次结束
          array[i] = temp;
          quickSort(array, low, i - 1);
          quickSort(array, i + 1, high);
      }
  }

  void sortArray(int array[], int num) {
      quickSort(array, 0, num - 1);
  }
};