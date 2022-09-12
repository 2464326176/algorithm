//**************************
// Author:  yh
// Time:    2022/5/18
//**************************

#include <iostream>

using namespace std;

void bubbleSort(int *array, int num) {

    for (int i = num - 1; i >= 1; --i) {
        int flag = 1;
        for (int j = 0; j < i; ++j) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
                flag = 0;
            }
        }

        if (flag) {
            return;
        }
    }
}

void removeDuplicates(int *array, int &num) {
    // 1 把重复的元素往后面搬 不重复的元素在前面
    /*
    int temp = array[0];
    for(int i = 1; i < num; ++i) {
        if(temp == array[i]) { // 当i下标的值和前驱 temp相等时  数组num减去1， 把后面的元素都往前搬
            // 比如之前是1 1 2 2 3 4 7 8 8 9
            //经过搬一次后1 2 2 3 4 7 8 8 9 1

            temp = array[i + 1];
            num -= 1;
            for(int j = i; j < num; ++j) {
                swap(array[j], array[j + 1]);
            }
        } else { //当i下标的值和前驱 temp不相等时 将array[i]赋值给 temp
            temp = array[i];
        }
    }*/

    // 2 将不重复的元素放到表头   重复的元素不管放到表尾部 避免了多次搬运元素 提升性能
    int i = 0, j = 1;
    for (; j < num; ++j) {
        if (array[i] != array[j]) { // 只管不一样的元素  一样的元素不管  执行结束 i就是所有不重复元素的总数
            array[++i] = array[j];
        }
    }
    num = i + 1; // i的下标是从0开始的  num是从1开始的  所以要+1才对
}

int main() {

    int array[] = {1, 2, 3, 1, 2, 4, 8, 9, 8, 7, 7, 7};
    int num = sizeof(array) / sizeof(int);
    bubbleSort(array, num); // 1 1 2 2 3 4 7 8 8 9

    for (auto &val: array) {
        printf("%d ", val);
    }
    printf("\n");

    removeDuplicates(array, num);
    for (int i = 0; i < num; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}