#include "linkList.h"
#include <iostream>

int main(int argc, char **argv) {
    ListNode *list3 = new ListNode(3);
    ListNode *list2 = new ListNode(2, list3);
    ListNode *list1 = new ListNode(9, list2);

    ListNode *list6 = new ListNode(6);
    ListNode *list5 = new ListNode(5, list6);
    ListNode *list4 = new ListNode(9, list5);

    reverseList(list1);
    reverseList(list4);

    ListNode *head = addList(list1, list4);
    reverseList(head->next);
    printLinkNode(head->next);
    return 0;
}
