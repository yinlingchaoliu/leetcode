//
// Created by 陈桐 on 2020/4/15.
//

#ifndef LEETCODE_BINARYSEARCH_H
#define LEETCODE_BINARYSEARCH_H

#include <stdio.h>

template<typename T>
//闭区间写程序更简单一些
int binarySearch(T arr[], int n, T target){
    int left =  0;  //设置初值 左边界 右边界
    int right = n-1; //在[left...right]范围内寻找target

    while (left <= right) {
//        int mid = (left +right)/2;
        //加法存在整型溢出
        int mid = left + (right-left)/2;

        if (arr[mid] == target) {
            return mid;
        }

        if (target > arr[mid]) {
            left = mid + 1;
        }

        if (target < arr[mid]) {
            right = mid - 1;
        }
    }

    return -1;
}



#endif //LEETCODE_BINARYSEARCH_H
