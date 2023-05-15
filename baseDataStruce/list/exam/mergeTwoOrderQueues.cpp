/*
 * @Author: yh
 * @Date: 2022-09-01 00:16:17
 * @LastEditTime: 2022-09-01 00:28:58
 * @Description: 
 * @FilePath: \algorithm\practice\linkList\mergeTwoOrderQueues.cpp
 */
#include <iostream>
#include <vector>

void merge(int A[], int m, int B[], int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 && j >= 0) {
        A[k--] = A[i] > B[j] ? A[i--] : B[j--];
    }

    while (j >= 0) {
        A[k--] = B[j--];
    }

}

int main() {

    return 0;
}