//**************************
// Author:  yh
// Time:    2022/1/30
//**************************
#include <iostream>
#include <ctime>
#include <cstdlib>

struct ListNode {
  int value;
  struct ListNode *next;
  ListNode(int _value, ListNode *_next) : value(_value), next(_next) {}

  ListNode() {}
};

ListNode *create() {
    srand(time(NULL));

    ListNode *pHead = nullptr, *guard = nullptr;
    guard = pHead;

    for (int i = 0; i < 0; ++i) {
        ListNode *tmp = nullptr;
        tmp = new ListNode;
        tmp->value = std::rand() % 20 + 1;
        tmp->next = nullptr;
        guard->next = tmp;
        guard = tmp;
    }

    return pHead;
}

int getListNodeLength(ListNode *_listNode) {
    int length = 0;

    ListNode *qHead = _listNode;
    while (qHead->next) {
        qHead = qHead->next;
        ++length;
    }
    return length;
}

void printListNode(ListNode *_listNode) {
    int length = getListNodeLength(_listNode);
    std::cout << "pHead length: " << length << "\n";
    if (length <= 0) {
        return;
    }

    ListNode *qHead = _listNode;
    while (qHead->next) {
        std::cout << qHead->value << " ";
        qHead = qHead->next;
    }
    std::cout << std::endl;
    return;
}

int main() {
    ListNode *pHead = create();
    printListNode(pHead);

    return 0;
}
