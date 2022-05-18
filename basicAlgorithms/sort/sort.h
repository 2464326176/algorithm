//**************************
// Author:  yh
// Time:    2022/5/6
//**************************

#ifndef ALGORITHM_SORT_H
#define ALGORITHM_SORT_H

class sort {
public:
    virtual void sortArray(int array[], int num) = 0;
    virtual void printSortArray(int array[], int num) {
        for(int i = 0; i < num; ++i) {
            printf("%d ", *(array + i));
        }
        printf("\n");
    };

};




#endif //ALGORITHM_SORT_H
