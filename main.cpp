#include <iostream>
#include <cmath>
#include <ctime>
#include "main.h"

/**
 c++代码也需要回调，代理来保证测试程序的通用性
 本例采用lambda方式写更简单一些
 */
//计时器
void timeFun(P_FUN pFun, int n);


//函数指针存入map未实现

/**
    主main函数要以代理方式，保证演示demo的可扩展性
 */
int main(int argc, const char *argv[]) {

    //数量级测试 2048 ~ 134217728
    for (int i = 10; i <= 20; i++) {
        int n = pow(2, i);
        //二分查找
        timeFun(binarySearchCallBack, n);
    }
    return 0;
}

//计时器
void timeFun(P_FUN pFun, int n) {
    clock_t startTime = clock();
    (pFun)(n);
    clock_t endTime = clock();
    std::cout << 2 * n << "\t opertions: \t ";
    std::cout << double(endTime - startTime) / CLOCKS_PER_SEC << " s\n";
}