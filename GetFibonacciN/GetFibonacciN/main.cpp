//
//  main.cpp
//  GetFibonacciN
//
//  Created by LeeWong on 2018/3/12.
//  Copyright © 2018年 LeeWong. All rights reserved.
//

// 面试题10：斐波那契数列
// 题目：写一个函数，输入n，求斐波那契（Fibonacci）数列的第n项。

#include <iostream>

//获取斐波那契数列 第n项
// 直接使用递归的方法  这种方法效率太低 原因是进行了大量的重复计算
// n = 50 Use Time:94
long long fibonacci(int n) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    
    return fibonacci(n-1) + fibonacci(n-2);
}

// 为了避免大量的重复计算 我们只需要把上次计算过的内容保存起来就可以
// 因此 我们可以采用从下往上的计算方式
// n = 50 Use Time:0
long long fibonacii2(int n) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    
    long long fibNMinusOne = 1;
    long long fibNMinusTwo = 0;
    long long fibN = 0;
    for (unsigned int i = 2; i <= n; i++) {
        fibN = fibNMinusOne + fibNMinusTwo;
        
        fibNMinusTwo = fibNMinusOne;
        fibNMinusOne = fibN;
    }
    
    return fibN;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    time_t start,stop;
    start = time(NULL);
    long long result = fibonacii2(100);
    stop = time(NULL);
    printf("Use Time:%ld\n",(stop-start));
 
    printf("%ld",result);
    
    return 0;
}
