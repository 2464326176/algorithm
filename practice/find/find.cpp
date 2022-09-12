//**************************
// Author:  yh
// Time:    2022/5/8
//**************************
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   *
   *
   * @param nums int整型vector
   * @param target int整型
   * @return int整型
   */
  int search(vector<int> &nums, int target) {
      int low = 0, high = nums.size() - 1;

      while (low <= high) {
          int mid = (low + high) / 2;
          if (nums[mid] > target) {
              high = mid - 1;
          } else if ((nums[mid] < target)) {
              low = mid + 1;
          } else {
              return mid;
          }
      }

      return -1;
  }
  bool Find(int target, vector<vector<int> > array) {
      for (int i = 0; i < array.size(); ++i) {
          if (binary_search(array[i].begin(), array[i].end(), target)) {
              return true;
          }
      }

      return false;
  }

  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   *
   *
   * @param nums int整型vector
   * @return int整型
   */
  int findPeakElement(vector<int> &nums) {
      int left = 0, right = nums.size() - 1;

      while (left < right) {
          int mid = (left + right) / 2;
          if (nums[mid] > nums[mid + 1]) {
              right = mid;
          } else {
              left = mid + 1;
          }
      }

      return right;
  }

  int minNumberInRotateArray(vector<int> rotateArray) {
      int left = 0, right = rotateArray.size() - 1;

      while (left < right) {
          int mid = (left + right) / 2;
          // 左边小
          if (rotateArray[mid] > rotateArray[right]) {
              left = mid + 1;
          } else if (rotateArray[mid] == rotateArray[right]) {
              right--;
          } else {
              right = mid;
          }
      }

      return rotateArray[left];
  }

  /**
* 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
*
* 比较版本号
* @param version1 string字符串
* @param version2 string字符串
* @return int整型
*/
  int compare(string version1, string version2) {
      int n1 = version1.size(), n2 = version2.size();
      int i = 0, j = 0;
      while (i < n1 || j < n2) {
          int num1 = 0, num2 = 0;
          while (i < n1 && version1[i] != '.') {
              num1 = 10 * num1 + (version1[i] - '0');
              ++i;
          }
          ++i;

          while (j < n2 && version2[j] != '.') {
              num2 = 10 * num2 + (version2[j] - '0');
              ++j;
          }
          ++j;

          if (num1 > num2) {
              return 1;
          } else if (num1 < num2) {
              return -1;
          }
      }
      return 0;
  }
};

int main() {
    vector<int> nums{1, 3, 8, 4, 9};
    vector<int> num2{4, 8, 9, 10, 1, 2, 3, 4};

    vector<vector<int>> nums2{
        {1, 2, 6, 7},
        {8, 7, 96, 8},
        {2, 6, 4, 1},
        {7, 9, 6, 115},
    };
    Solution s1;
    //printf("%d ", s1.search(nums, 3));
    //printf("%d ", s1.Find(115, nums2));
    //printf("%d ", s1.findPeakElement(nums));
    //printf("%d ", s1.minNumberInRotateArray(num2));
    printf("%d ", s1.compare("01.02.30", "01.021.301"));

    return 0;
}
