//
//  Test.cpp
//  artist
//
//  Created by 陈桐 on 2020/3/23.
//  Copyright © 2020 chentong. All rights reserved.
//

#ifndef LEETCODE_MAIN_H
#define LEETCODE_MAIN_H

#include "list/BinarySearch.h"
#include "util/util.h"
#include <assert.h>

#include <map>
#include <string>

using namespace std;

//定义函数
typedef void (*P_FUN)(int n);

/**
    所有测试回调写在这个地方
    保证主测试类没有其他代码干扰
 */
auto binarySearchCallBack = [](int num) {
    int *data = Util().generateOrderedArray(num);
    for (int i = 0; i < num; i++) {
        assert(i == binarySearch(data, num, i));
    }
};


#endif