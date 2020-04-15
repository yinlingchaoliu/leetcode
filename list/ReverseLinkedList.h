//
// Created by 陈桐 on 2020/4/15.
//

#ifndef LEETCODE_REVERSELINKEDLIST_H
#define LEETCODE_REVERSELINKEDLIST_H

#include "ListNode.h"

class ReverseLinkedList {

public:
    //字符串翻转
    ListNode *reverseList(ListNode *head) {
        ListNode *pre = NULL;
        ListNode *cur = head;

        while (cur != NULL) {
            ListNode *next = cur->next;
            cur->next = pre;

            //相当于i++
            pre = cur;
            cur = next;
        }

        return pre;
    }
};

#endif //LEETCODE_REVERSELINKEDLIST_H
