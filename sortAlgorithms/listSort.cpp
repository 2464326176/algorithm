/*
 * @Author: yh
 * @Date: 2022/11/10 23:10
 * @Description: 
 * @FilePath: listSort.cpp
 */
#include <iostream>

struct ListNode{
    int value;
    ListNode *next;
    ListNode(int value) : value(value), next(nullptr) {}
};
ListNode *split(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *second = slow->next;
    slow->next = nullptr;

    return second;
}

ListNode *megerList(ListNode *head1, ListNode *head2) {

    ListNode *dummy = new ListNode(-1);
    ListNode *cur = dummy;
    while(head1 && head2) {
        if (head1->value < head2->value) {
            cur->next = head1;
            head1 = head1->next;
        } else {
            cur->next = head2;
            head2 = head2->next;
        }
        cur = cur->next;
    }
    cur->next = head1 ? head1 : head2;
    return dummy->next;
}

ListNode *sortList(ListNode *head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode *head1 = head;
    ListNode *head2 = split(head);

    head1 = sortList(head1);
    head2 = sortList(head2);

    return megerList(head1, head2);
}

int main() {
    ListNode listNode1(2);
    ListNode listNode2(5);
    ListNode listNode3(3);
    ListNode listNode4(7);
    ListNode listNode5(0);
    ListNode listNode6(6);
    ListNode listNode7(4);
    ListNode listNode8(1);

    ListNode *head = nullptr;
    head = &listNode1;
    listNode1.next = &listNode2;
    listNode2.next = &listNode3;
    listNode3.next = &listNode4;
    listNode4.next = &listNode5;
    listNode5.next = &listNode6;
    listNode6.next = &listNode7;
    listNode7.next = &listNode8;

    ListNode *res = sortList(head);


    while (res) {
        printf("%d ", res->value);
        res = res->next;
    }
    return 0;
}
