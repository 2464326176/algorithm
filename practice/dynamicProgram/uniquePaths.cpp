/*
 * @Author: yh
 * @Date: 2022-09-06 01:02:55
 * @LastEditTime: 2022-09-06 01:12:02
 * @Description:
 * @FilePath: \algorithm\practice\dynamicProgram\uniquePaths.cpp
 */
#include <iostream>

int uniquePath(int m, int n) {
    if (m == 1 || n == 1) {
        return 1;
    }

    return uniquePath(m - 1, n) + uniquePath(m, n - 1);
}

int main() {
    std::cout << uniquePath(2, 2);
    return 0;
}