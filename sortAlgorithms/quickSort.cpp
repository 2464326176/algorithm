/*
 * @Author: yh
 * @Date: 2022/11/3 0:28
 * @Description: 
 * @FilePath: quickSort.cpp
 */
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

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

void quickSort(vector<int> &nums, int begin, int end) {
    if(begin < end) {
        int pivot = partition(nums, begin, end);
        quickSort(nums, begin, pivot - 1);
        quickSort(nums, pivot + 1, end);
    }
}

void sortArray(vector<int> &nums) {
    quickSort(nums, 0, nums.size() - 1);
}

int main() {
    vector<int> nums{3, 8, 7, 6, 2, 1, 6};
    sortArray(nums);
    for (auto &it : nums) {
        std::cout << it << " ";
    }

    return 0;
}
