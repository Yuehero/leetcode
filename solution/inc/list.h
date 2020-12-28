//
// Created by 郭越 on 2020/12/28.
//

#ifndef LEETCODE_LIST_H
#define LEETCODE_LIST_H

#include "../util/commom.h"

namespace leetcode {
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    class List {
    private:
        int getListLength(ListNode* head);
    public:
        //19.给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点
        ListNode* removeNthFromEnd(ListNode* head, int n);
        //203.
        ListNode* removeElements(ListNode* head, int val);
        //24. 两两交换链表中的节点
        ListNode* swapPairs(ListNode* head);

    };

}

#endif //LEETCODE_LIST_H
