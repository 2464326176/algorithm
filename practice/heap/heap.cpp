/*
 * @Author: yh
 * @Date: 2022/10/2 12:46
 * @Description: 
 * @FilePath: heap.cpp
 */
#include "./heap.h"
#include <iostream>
#include <algorithm>

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    //  std::priority_queue<int> hp; //  大顶堆
    //  std::priority_queue<int, vector<int>, std::greater<>> hp(input.begin(), input.end()); //  小顶堆
    if (input.size() < k) {
        return {};
    }

    std::priority_queue<int, vector<int>, std::less<>> hp(input.begin(), input.end()); //  大顶堆
    input.clear();
    while (k >= 1) {
        input.emplace_back(hp.top());
        hp.pop();
        --k;
    }

    return input;
}

int findKth(vector<int> input, int n, int K) {
    if (n < K) {
        return {};
    }

    std::priority_queue<int, vector<int>, std::less<>> hp(input.begin(), input.end()); //  大顶堆
    input.clear();
    while (K > 1) {
        hp.pop();
        --K;
    }

    return hp.top();
}

void print(const vector<int> &vt) {
    for (auto key : vt) {
        cout << key << " ";
    }
    cout << endl;
}

int main() {
    vector<int> vt{6, 5, 2, 7, 8, 9};
    print(GetLeastNumbers_Solution(vt, 2));
    return 0;
}