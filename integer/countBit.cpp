/*
 * @Author: yh
 * @Date: 2022/11/13 23:36
 * @Description: 
 * @FilePath: countBit.cpp
 */
#include <iostream>
#include <vector>

using namespace std;

vector<int> countBit(int num) {
    vector<int> ret(num + 1, 0);
    for (int i = 1; i <= num; ++i) {
        //ret[i] = ret[(i & (i - 1))] + 1;
        int j = i;
        while (j != 0) {
            ret[i]++;
            j = j & (j - 1);
        }
    }
    return ret;
}

int main() {
    for(auto it : countBit(4)) {
        cout << it << " ";
    }

    return 0;
}



