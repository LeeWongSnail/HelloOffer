//
//  main.cpp
//  ReSortArray
//
//  Created by LeeWong on 2018/3/16.
//  Copyright © 2018年 LeeWong. All rights reserved.
//

/*
 输入一个整数数组,实现一个函数来调整该数组中数字的顺序,是的所有奇数位于数组的前半部分 所有的偶数位于数组的后半部分
 **/

#include <iostream>


//基本的解法 O(n^2)

void resortArray(int *str,int length) {
    
    for (int i = 0 ; i < length; i++) {
        
        if (str[i]%2==0) {
            //如果是偶数 则将偶数后面的所有数据往前移动
            char elem = str[i];
            for (int j = i+1; j<length; j++) {
                str[j-1] = str[j];
            }
            str[length-1] = elem;
        }
        
    }
    
}

// 更进一步的解法
void resortArray1(int *str,int length) {
    //两个指针指向 这个数组的首尾
    int *pBegin = str;
    int *pEnd = str+length-1;
    
    
    while (pBegin < pEnd) {
       
        //从begin开始
        while ((*pBegin & 0x1) != 0) {
            //如果是奇数
            pBegin++;
        }
        
        while ((*pEnd & 0x1) == 0) {
            pEnd--;
        }
        
        //找到之后交换
        if (pBegin < pEnd) {
           int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
        }
        
    }
}

// 此类问题可能有很多种 这个问题是奇数跟偶数作为区分条件 也有可能是其他的条件 比如正数负数  被三整除不能被三整除

//是否为偶数
bool SatisfyTheCondition(int n) {
    return (n & 0x1)== 0;
}

void resortArray2(int *str,int length) {
    //两个指针指向 这个数组的首尾
    int *pBegin = str;
    int *pEnd = str+length-1;
    
    
    while (pBegin < pEnd) {
        
        //从begin开始
        while (!SatisfyTheCondition(*pBegin)) {
            //如果是奇数
            pBegin++;
            printf("%d\n",*pBegin);
        }
        
        while (SatisfyTheCondition(*pEnd)) {
            pEnd--;
            printf("%d\n",*pEnd);
        }
        
        //找到之后交换
        if (pBegin < pEnd) {
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
        }
        
    }
}



int main(int argc, const char * argv[]) {
    // insert code here...
    
    int a[] = {1,2,3,4,5};
    resortArray2(a, 5);
    for (int i = 0; i < 5; i++) {
        printf("%d",a[i]);
    }
    
    return 0;
}
