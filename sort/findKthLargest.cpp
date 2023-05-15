/*
 * @Author: yh
 * @Date: 2022/11/3 1:05
 * @Description: 
 * @FilePath: findKthLargest.cpp
 */
#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &nums, int begin, int end) {
    srand(time(NULL));
    int random = (rand() % (end - begin + 1)) + begin;
    std::swap(nums[random], nums[end]);

    int sentinelBelow = begin - 1;
    for (int i = begin; i < end; ++i) {
        if (nums[i] < nums[end]) {
            sentinelBelow++;
            std::swap(nums[i], nums[sentinelBelow]);
        }
    }

    sentinelBelow++;
    swap(nums[sentinelBelow], nums[end]);
    return sentinelBelow;
}

int findKthLargest(vector<int> nums, int k) {
    int target = nums.size() - k;
    int start = 0;
    int end = nums.size() - 1;
    int index = partition(nums, start, end);
    while (index != target) {
        if (index > target) {
            end = index - 1;
        } else {
            start = index + 1;
        }
        index = partition(nums, start, end);
    }
    return nums[target];
}

int main() {
    vector<int> nums{3, 8, 7, 6, 2, 1, 6}; // 1 2 3 6 6 7 8
    cout << findKthLargest(nums, 3);
    return 0;
}
