//
// Created by 陈桐 on 2020/4/15.
//

#ifndef LEETCODE_UTIL_H
#define LEETCODE_UTIL_H

#include <cstdlib>
#include <ctime>

/**
 *
 * 验证方法工具类
 *
 */
class Util {

public:

    Util(){

    }

    int * generateRandomArray(int n, int rangL, int rangR){
//        static_assert(n>0 && (rangL <= rangR), "数据异常");
        int *arr = new int[n];

        srand(time(NULL));
        for (int i = 0; i< n; i++) {
            arr[i] = rand()%(rangR-rangL+1) +rangL;
        }

        return arr;
    };


    int * generateOrderedArray(int n){
        int * arr = new int[n];
        for(int i = 0; i< n;i++)
            arr[i] = i;
        return arr;
    };

    int getRandom(){
        unsigned seed;
        seed = time(NULL);
        srand(seed);
        return rand();
    };

    /**

     */
    int getRandomRange(int n,int rangL ,int rangR ){
        srand(time(NULL));
        return rand() % (rangR - rangL + 1 ) + rangL;
    };

    /**
             0-n之间随机数
     */
    int getRandom(int n){
        return getRandomRange(n, 0, n);
    }

    void test(bool flag){

    }

};


#endif //LEETCODE_UTIL_H
