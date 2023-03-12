/*
 * @Author: yh
 * @Date: 2023-02-05 13:22:02
 * @LastEditTime: 2023-02-05 22:06:45
 * @Description:
 * @FilePath: \algorithm\practice\doublePointer\minSubArrayLen.cpp
 */
#include <iostream>
#include <vector>

using namespace std;

int minSubArrayLen(const vector<int> &array, int target) {
    int left = 0, right = 0, sum = 0;
    int length = array.size();
    int minLength = length;
    for (; right < length; ++right) {
        sum += array[right];
        while (left < right && sum >= target) {
            minLength = std::min(minLength, right - left + 1);
            sum -= array[left++];
        }
    }

    return (minLength == length && 0 == left) ? 0 : minLength;
}

int main() {
    vector<int> array{2, 3, 1};
    std::cout << minSubArrayLen(array, 7);

    return 0;
}