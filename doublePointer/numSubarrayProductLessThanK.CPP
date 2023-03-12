#include <iostream>
#include <vector>

using namespace std;

vector<int> numSubarrayProductLessThanK(vector<int> &numbers, int k) {
    int length = numbers.size();
    int product = 1;
    int left = 0, right = 0;
    for (; right < length; right++) {
        product *= numbers[right];
        while (left < right && product >= k) {
            product /= numbers[left];
            left++;
        }

        count += right
    }
}

int main(int argc, char **argv) { return 0; }