//
// Created by 陈桐 on 2020/4/15.
//

#ifndef LEETCODE_LISTNODE_H
#define LEETCODE_LISTNODE_H


#include <stdio.h>
#include <iostream>

using namespace std;

//创建节点
struct ListNode{
    int val;
    ListNode * next;

    ListNode(int x){
        val = x;
        next=NULL;
    };
};


ListNode * createLinkedList(int arr[], int n){

    if( n == 0){
        return NULL;
    }

    ListNode * head = new ListNode(arr[0]);
    ListNode * curNode = head;

    for (int i = 1; i< n; i++) {
        curNode->next = new ListNode(arr[i]);
        curNode = curNode->next;
    }
    curNode->next = NULL;

    return head;
}

void printLinkedList(ListNode *head){
    ListNode *curNode = head;
    while (curNode!=NULL) {
        cout << curNode->val << " -> ";
        curNode = curNode->next;
    }
    cout << "NULL" << endl;
    return;
}

void freeLinkedList(ListNode * head){
    ListNode * curNode = head;
    while(curNode!=NULL){
        ListNode * delNode = curNode;
        curNode = curNode->next;
        delete delNode;
    }
}

//删除元素
ListNode * removeListNode(ListNode *head, ListNode * delNode){

    if(head == NULL) return NULL;
    if(delNode == NULL) return head;

    ListNode * curNode = head;
    ListNode * preNode = NULL;
    ListNode * nextNode = NULL;

    while(curNode!=NULL){
        nextNode = curNode->next;

        //其他情况
        if(curNode == delNode){
            preNode->next = nextNode;
            delete curNode;
            return head;
        }

        preNode = curNode;
        curNode = nextNode;
    }
    return head;
}

//删除节点 操作val
void deleteNode(ListNode *node){

    if (node == NULL) return;

    if (node->next == NULL) {
        delete node;
        node = NULL;
        return;
    }

    node->val = node->next->val;
    ListNode *delNode = node->next;
    node->next = delNode->next;

    delete delNode;
    return;
}

ListNode * removeNthFromEnd(ListNode * head, int n){

    assert(head!=NULL);
    assert(n>=0);

    ListNode * dummyHead = new ListNode(0);
    dummyHead->next = head;

    ListNode * p = dummyHead;
    ListNode * q = dummyHead;

    for(int i = 0; i<=n+1; i++){
        assert(q);
        q = q->next;

    }

    while(q!=NULL){
        p=p->next;
        q=q->next;
    }

    ListNode *delNode = p->next;
    p->next=delNode->next;
    delete delNode;

    ListNode *retNode = dummyHead->next;
    delete dummyHead;

    return retNode;
}


#endif //LEETCODE_LISTNODE_H
