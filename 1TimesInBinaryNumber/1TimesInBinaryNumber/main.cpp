//
//  main.cpp
//  1TimesInBinaryNumber
//
//  Created by LeeWong on 2018/3/13.
//  Copyright © 2018年 LeeWong. All rights reserved.
//

/*
 请实现一个函数 输入一个整数,输出该数的二进制表示中1的个数
 例如 把 9表示成二进制是1001 有2位是1 因此如果输入9 则该函数输出2
 **/

#include <iostream>

int NumberOf1(int n)
{
    int count = 0;
    unsigned int flag = 1;
    while (flag)
    {
        if (n & flag)
            count++;
        
        flag = flag << 1;
    }
    
    return count;
}


int NumberOf1_2(int n)
{
    int count = 0;
    
    while (n)
    {
        ++count;
        n = (n - 1) & n;
    }
    
    return count;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int times = NumberOf1(9);
    printf("1出现了%d次",times);
    return 0;
}
