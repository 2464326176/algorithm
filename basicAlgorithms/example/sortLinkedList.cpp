//**************************
// Author:  yh
// Time:    2022/5/18
//**************************

//**************************
// Author:  yh
// Time:    2022/5/15
//**************************
#include <iostream>

using namespace std;

struct LNode {
  int data;
  LNode *next;
  LNode(int data) : data(data), next(nullptr) {}
};

LNode *sequencetable(LNode *str1, LNode *str2) {
    LNode *pHead = new LNode(-1); // 制造一个表头节点
    LNode *q = pHead;
    while (str1 && str2) {
        if (str1->data > str2->data) {
            q->next = str2;
            q = str2;
            str2 = str2->next;
        } else {
            q->next = str1;
            q = str1;
            str1 = str1->next;
        }
    }

    if (str1) {
        q->next = str1;
    } else {
        q->next = str2;
    }
    return pHead->next;
}

int main() {

    LNode *p1 = new LNode(1);
    LNode *p2 = new LNode(3);
    LNode *p3 = new LNode(5);
    LNode *p4 = new LNode(7);
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;

    LNode *q1 = new LNode(2);
    LNode *q2 = new LNode(4);
    LNode *q3 = new LNode(6);
    LNode *q4 = new LNode(8);
    q1->next = q2;
    q2->next = q3;
    q3->next = q4;
    LNode *pHead = sequencetable(p1, q1);

    while (pHead) {
        printf("%d ", pHead->data);
        pHead = pHead->next;
    }
    printf("\n");
    return 0;
}