/*
 * @Author: yh
 * @Date: 2022/11/14 0:04
 * @Description: 
 * @FilePath: singleNum.cpp
 */
#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int> nums) {
    vector<int> bitSums(32, 0);
    for (auto num : nums) {
        for (int i = 0; i < 32; ++i) {
            bitSums[i] += (num >> (31 - i)) & 1;
        }
    }

    int ret = 0;
    for (int i = 0; i < 32; ++i) {
        ret = (ret << 1) + bitSums[i] % 3;
    }

    return ret;
}


int main() {
    vector<int> nums{1, 1, 1, 3, 3, 3, 5, 6, 6, 5, 6, 5, 9};
    cout << singleNumber(nums) << endl;

    return 0;
}
