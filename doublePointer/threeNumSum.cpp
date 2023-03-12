/*
 * @Author: yh
 * @Date: 2022-10-01 14:12:37
 * @LastEditTime: 2023-02-05 13:12:58
 * @Description:
 * @FilePath: \algorithm\practice\doublePointer\threeNumSum.cpp
 */
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
    std::vector<std::vector<int>> res;

    int n = nums.size();
    if (n < 3) {
        return res;
    }

    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 2; ++i) {
        if (i != 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        int left = i + 1;
        int right = n - 1;
        int target = -nums[i];
        while (left < right) {
            if (nums[left] + nums[right] == target) {
                res.push_back({nums[i], nums[left], nums[right]});

                while (left + 1 < right && nums[left] == nums[left + 1]) {
                    left++;
                }

                while (right - 1 > left && nums[right] == nums[right - 1]) {
                    right--;
                }
                left++;
                right--;
            } else if (nums[left] + nums[right] > target) {
                right--;
            } else {
                left++;
            }
        }
    }
    return res;
}

int main() {
    std::vector<int> vt{10, -10, 20, 0, 5, -5};
    threeSum(vt);
    return 0;
}
