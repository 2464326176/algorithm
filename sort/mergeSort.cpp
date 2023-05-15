/*
 * @Author: yh
 * @Date: 2022/11/8 0:02
 * @Description: 
 * @FilePath: mergeSort.cpp
 */
#include <iostream>
#include <vector>

using namespace std;


void sortArray(vector<int> &nums) {
    int length = nums.size();
    vector<int> dst(nums);

    for (int seg = 1; seg < length; seg += seg) {
        for (int start = 0; start < length; start += seg * 2) {
            int mid = std::min(start + seg, length);
            int end = std::min(start + seg * 2, length);
            int i = start, j = mid, k = start;
            while (i  < mid || j < end) {
                if (j == end || (i < mid && nums[i] < nums[j])) {
                    dst[k++] = nums[i++];
                } else {
                    dst[k++] = nums[j++];
                }
            }
        }
        std::swap(nums, dst);
    }
}

void mergerSort(vector<int> &src, vector<int> &dst, int start, int end) {
    if (start + 1 >= end) {
        return;
    }
    int mid = (start + end) / 2;
    mergerSort(src, dst, start, mid);
    mergerSort(src, dst, mid, end);

    int i = start, j = mid, k = start;
    while (i < mid || j < end) {
        if (j == end || (i < mid && src[i] < src[j])) {
            dst[k++] = src[i++];
        } else {
            dst[k++] = src[j++];
        }
    }
    swap(src, dst);
}
int sortArray2(vector<int> &nums) {
    vector<int> dst(nums);
    mergerSort(nums, dst, 0, nums.size() - 1);
}

int main() {
    vector<int> nums {1, 3, 4, 5, 8, 10, 2, 6, 9, 12, 15, 18};
    //sortArray(nums);
    sortArray2(nums);
    for (auto it : nums) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}