//
// Created by 郭越 on 2020/12/28.
//
#include "../inc/list.h"

namespace leetcode {
    int List::getListLength(ListNode* head) {
        int len = 0;
        while (head) {
            ++len;
            head = head->next;
        }
        return len;
    }
    //19
    ListNode *List::removeNthFromEnd(ListNode *head, int n) {
        //设置dummyHead, 指向head, 最后删除dummyHead
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        int len = getListLength(head);
        //找到倒数第n个元素的前一个节点
        int i = 1;
        while (i < len - n + 1) {
            //cur 肯定有效
            cur = cur->next;
            i ++;
        }
        ListNode* del = cur->next;
        cur->next = del->next;
        delete del;
        ListNode* res = dummyHead->next;
        delete dummyHead;
        return res;
    }

    //203
    ListNode* List::removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead; //从虚拟头节点开始
        while (cur->next) {
            if (cur->next->val == val) {
                ListNode* del = cur->next;
                cur->next = del->next;
                delete del;
            } else {
                cur = cur->next;
            }
        }
        ListNode * res = dummyHead->next;
        delete dummyHead;
        return res;
    }
    //24
    ListNode* List::swapPairs(ListNode *head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* p = dummyHead;

        while (p->next && p->next->next) {
            ListNode* node1 = p->next;
            ListNode* node2 = node1->next;
            ListNode* next = node2->next;

            node1->next = next;
            node2->next = node1;
            p->next = node2;
            p = node1;
        }

        ListNode* res = dummyHead->next;
        delete dummyHead;
        return res;
    }

}