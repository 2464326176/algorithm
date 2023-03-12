/*
 * @Author: yh
 * @Date: 2022/11/1 0:08
 * @Description: 
 * @FilePath: intervalMerge.cpp
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;

bool intervalFunction(const array<int, 2> &i, const array<int, 2> &j) {
    return i[0] < j[0];
}

struct IntervalClass{
public:
    bool operator()(const array<int, 2> &i, const array<int, 2> &j) {
        return i[0] < j[0];
    }
} intervalClass;

vector<array<int, 2>> intervalMerge(vector<array<int, 2>> intervals) {
    vector<array<int, 2>> ret;
    std::sort(intervals.begin(), intervals.end(), [](const array<int, 2> &i, const array<int, 2> &j) {
        return i[0] < j[0];
    });

//    std::sort(intervals.begin(), intervals.end(), intervalFunction);
//    std::sort(intervals.begin(), intervals.end(), intervalClass);
    for (auto it : intervals) {
        printf("[first: %d, second: %d]\n", it[0], it[1]);
    }

    printf("------------------------------------------\n");
    size_t length = intervals.size();
    array<int, 2> interval;
    int i = 0;
    while (i < length) {
        array<int, 2> tmpInterval {intervals[i][0], intervals[i][1]};
        int j = i + 1;
        while (j < length && intervals[j][0] <= tmpInterval[1]) {
            tmpInterval[1] = std::max(intervals[j][1], tmpInterval[1]);
            ++j;
        }
        ret.push_back(tmpInterval);
        i = j;
    }
    return ret;
}

int main() {
    vector<array<int, 2>> intervals{
        {1, 3},
        {4, 5},
        {8, 10},
        {2, 6},
        {9, 12},
        {15, 18},
    };

    vector<array<int, 2>>  ret = intervalMerge(intervals);

    for (auto it : ret) {
        printf("[first: %d, second: %d]\n", it[0], it[1]);
    }
    return 0;
}
