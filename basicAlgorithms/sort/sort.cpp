//**************************
// Author:  yh
// Time:    2022/5/6
//**************************

#include <iostream>
#include "bubbleSort.cpp"
#include "halfSort.cpp"
#include "heapSort.cpp"
#include "insertSort.cpp"
#include "mergeSort.cpp"
#include "quickSort.cpp"
#include "selectSort.cpp"
#include "shellSort.cpp"

void sortArray(sort *sort, int *array, int num) {
    sort->sortArray(array, num);
    sort->printSortArray(array, num);
}

int main() {
    int order[] {2, 5, 8, 9, 14}, reverseOrder[] {14, 9, 8, 5, 2}, disorder[] {5, 2, 9, 8, 14};
    insertSort insertSort;
    sortArray(&insertSort, order, sizeof(order) / sizeof(order[0]));
    sortArray(&insertSort, reverseOrder, sizeof(reverseOrder) / sizeof(reverseOrder[0]));
    sortArray(&insertSort, disorder, sizeof(disorder) / sizeof(disorder[0]));

    return 0;
}