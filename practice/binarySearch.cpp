//
// Created by 24643 on 2021/10/11.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {
      int low = 0, high = nums.size() - 1;
      while (low <= high) {
          int mid = (low + high) / 2;
          if (nums[mid] > target) {
              high = mid - 1;
          }
          if (nums[mid] < target) {
              low = mid + 1;
          }
          if (nums[mid] == target) {
              return mid;
          }
      }
      return -1;
  }

  bool isBadVersion(int n) {
      vector<int> nums = {1, 1, 1, 1, 0};
      return (nums[n] == 0 ? true : false);
  }

  int firstBadVersion(int n) {
      int low = 0, high = n - 1;
      while (low <= high) {
          int mid = (low + high) / 2;
          if (isBadVersion(mid) && !isBadVersion(--mid)) {
              return ++mid;
          }
          ++mid;
          if (isBadVersion(mid) && isBadVersion(--mid)) {
              high = mid;
          }
          ++mid;
          if (!isBadVersion(mid) && !isBadVersion(++mid)) {
              low = ++mid;
          }
          --mid;
          if (!isBadVersion(mid) && isBadVersion(++mid)) {
              return mid;
          }
      }
      return -1;
  }
  int searchInsert(vector<int> &nums, int target) {
      int low = 0, high = nums.size() - 1, mid = 0;
      while (low <= high) {
          mid = (low + high) / 2;
          if (nums[mid] > target) {
              high = mid - 1;
          }
          if (nums[mid] < target) {
              low = mid + 1;
          }
          if (nums[mid] == target) {
              return mid;
          }
      }

      return (nums[mid] > target ? ((mid == 0) ? 0 : mid) : ++mid);
  }
};

int main() {
    vector<int> nums = {1, 3, 5, 7};
    Solution s;
    cout << s.searchInsert(nums, 0);
    return 0;
}