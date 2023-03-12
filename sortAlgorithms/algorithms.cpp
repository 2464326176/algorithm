/*
 * @Author: yh
 * @Date: 2022/11/3 0:28
 * @Description:
 * @FilePath: \algorithm\practice\sort\algorithms.cpp
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename type> bool myFunctionGreater(type i, type j) { return i < j; }
template <typename type> class MyClassGreaters {
  public:
    bool operator()(type i, type j) { return i > j; }
};

void printNumbers(const vector<int> &numbers) {
    for (auto &item : numbers) {
        std::cout << item << " ";
    }
    std::cout << endl;
}

int main() {
    vector<int> numbers{3, 8, 7, 6, 2, 1, 6};
    printNumbers(numbers);
    std::sort(numbers.begin(), numbers.end());
    printNumbers(numbers);

    vector<int> numbers1{3, 8, 7, 6, 2, 1, 6};
    printNumbers(numbers1);
    std::sort(numbers1.begin(), numbers1.end(), myFunctionGreater<int>);
    printNumbers(numbers1);

    vector<int> numbers2{3, 8, 7, 6, 2, 1, 6};
    printNumbers(numbers2);
    MyClassGreaters<int> myObject;
    std::sort(numbers2.begin(), numbers2.end(), myObject);
    printNumbers(numbers2);

    vector<int> numbers3{3, 8, 7, 6, 2, 1, 6};
    printNumbers(numbers3);
    std::stable_sort(numbers3.begin(), numbers3.end(), [&](int i, int j) { return i < j; });
    printNumbers(numbers3);

    return 0;
}
