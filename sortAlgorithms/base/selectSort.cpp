//**************************
// Author:  yh
// Time:    2022/5/6
//**************************
#include "Sort.h"

// 简单选择排序
class SelectSort : public Sort {
  void sortArray(int array[], int num) {
      for (int i = 0; i < num; ++i) {
          int k = i;
          for (int j = i + 1; i < num; ++i) {
              if (array[k] > array[j]) {
                  k = j;
              }
          }
          std::swap(array[k], array[i]);
      }
  }
};

// 堆排序
class HeapSort : public Sort {
  // 对[low, high] 区间 low位置调整
  void sift(int array[], int low, int high) {
      int i = low, j = i * 2; // i 双亲节点 j 左孩子
      int temp = array[i];
      while (j <= high) {
          // 右边孩子比较大 指向右孩子
          if (j < high && array[j] < array[j + 1]) {
              ++j;
          }

          if (temp < array[j]) {
              array[i] = array[j]; // 交换位置
              i = j;               // 修改i j 以便继续向下调整
              j = 2 * i;
          } else {
              break;
          }
      }
      array[i] = temp;
  }

  void sortArray(int array[], int num) {
      // 建立初始堆
      for (int i = num / 2; i >= 1; --i) {
          sift(array, i, num);
      }

      for (int i = num; i >= 2; --i) {
          int temp = array[1];
          array[1] = array[i];
          array[i] = temp;
          sift(array, 1, i - 1);
      }
  }
};
