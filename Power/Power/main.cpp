//
//  main.cpp
//  Power
//
//  Created by LeeWong on 2018/3/14.
//  Copyright © 2018年 LeeWong. All rights reserved.
//

/*
 实现函数double Power(double base, int exponent)
 求 base的 exponent次方
 不得使用函数库 同时不需要考虑最大数问题
 **/


#include <iostream>

// 最简单 直接的做法
/*
 存在的问题：
 如果exponent 是0或者负数 没有考虑到
 **/
double Power(double base,double exponent) {
    double result = 1;
    for (int i = 0; i < exponent; i++) {
        result *=base;
    }
    
    return result;
}


double PowerWithUnsignedExponent(double base,unsigned int exponent) {
    double result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

// 进一步的优化 计算base的exponent次方
double PowerWithUnsignedExponent2(double base, unsigned int exponent) {
    if (exponent == 1) {
        return base;
    }
    if (exponent == 0) {
        return 1;
    }
    
    double result = PowerWithUnsignedExponent2(base, exponent>>1);
    result *= result;
    //判断exponent 这个是奇数还是偶数
    if ((exponent & 0x1) == 1) {
         result *=base;
    }
    return result;
}

// 考虑到0 和负数
bool g_InvalidInput = false;
double Power2(double base, double exponent) {
    
    g_InvalidInput = false;
    //基数是0 切 指数是负数 因为要通过求倒数得到结果 避免 分母是0的情况
    if (base == 0.0 && exponent < 0.0) {
        g_InvalidInput = true;
        return 0.0;
    }
    
    if (base == 0.0) {
        printf("没有意义的输入");
    }
    if (base == 1) {
        return 1;
    }
    
    unsigned int absExponent = (unsigned int)exponent;
    if (exponent < 0) {
        absExponent = (unsigned int)-exponent;
    }
    
    double result = PowerWithUnsignedExponent2(base, absExponent);
    if (exponent < 0) {
        return 1.0/result;
    } else {
        return result;
    }
    
    return  result;
}






int main(int argc, const char * argv[]) {
    // insert code here...
    double result = Power2(2, 4);
    printf("%f\n",result);
    return 0;
}
