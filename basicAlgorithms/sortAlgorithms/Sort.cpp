//**************************
// Author:  yh
// Time:    2022/5/6
//**************************
#include "insertSort.cpp"
#include "mergeSort.cpp"
#include "selectSort.cpp"
#include "exchangeSort.cpp"

void sortArray(Sort *sort, int *array, int num) {
    sort->sortArray(array, num);
    sort->printSortArray(array, num);
}

int main() {
    int order[]{2, 5, 8, 9, 14}, reverseOrder[]{14, 9, 8, 5, 2}, disorder[]{5, 2, 9, 8, 14};
    // 插入排序
//    insertSort insertSort;
//    sortArray(&insertSort, order, sizeof(order) / sizeof(order[0]));
//    sortArray(&insertSort, reverseOrder, sizeof(reverseOrder) / sizeof(reverseOrder[0]));
//    sortArray(&insertSort, disorder, sizeof(disorder) / sizeof(disorder[0]));

    // 快速排序
//    QuickSort quickSort;
//    sortArray(&quickSort, order, sizeof(order) / sizeof(order[0]));
//    sortArray(&quickSort, reverseOrder, sizeof(reverseOrder) / sizeof(reverseOrder[0]));
//    sortArray(&quickSort, disorder, sizeof(disorder) / sizeof(disorder[0]));

    // 冒泡排序
//    BubbleSort bubbleSort;
//    sortArray(&bubbleSort, order, sizeof(order) / sizeof(order[0]));
//    sortArray(&bubbleSort, reverseOrder, sizeof(reverseOrder) / sizeof(reverseOrder[0]));
//    sortArray(&bubbleSort, disorder, sizeof(disorder) / sizeof(disorder[0]));


    // 堆排序
    HeapSort heapSort;
    sortArray(&heapSort, order, sizeof(order) / sizeof(order[0]));
    sortArray(&heapSort, reverseOrder, sizeof(reverseOrder) / sizeof(reverseOrder[0]));
    sortArray(&heapSort, disorder, sizeof(disorder) / sizeof(disorder[0]));
    return 0;
}