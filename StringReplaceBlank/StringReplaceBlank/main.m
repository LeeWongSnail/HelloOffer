//
//  main.m
//  StringReplaceBlank
//
//  Created by LeeWong on 2018/3/6.
//  Copyright © 2018年 LeeWong. All rights reserved.
//

/*
 题目
 请事先一个函数,把字符串中的每个空格替换成“%20”。例如 输入“We are happy.” 则输出"We%20are%20happy."
 **/

#import <Foundation/Foundation.h>


/*从前向后遍历这个字符串 如果遇到空格 将后面的元素后移两个格 插入%20
 时间复杂度O(n²)
 */

void replaceStringBlank(char *a,int length)
{
    int len = length;
    for (int i = 0; i < len; i++) {
        char elem = a[i];
        printf("%c\n",elem);
        if (elem == ' ') {
            //如果是空格 将空格后面的元素后移
            for (int j = len; j > i; j--) {
                a[j+2] = a[j];
            }
            len += 2;
            a[i] = '%';
            a[i+1] = '2';
            a[i+2] = '0';
            i+=2;
            printf("%s\n",a);
        }
    }
}


/*
 从后往前遍历 用两个指针 分别指向数组的最后一个位置 和数组最后一个值的位置(要求必须预先计算替换后的数组大小)
 **/

void replaceStringToBlank(char *a,int length) {
    //先计算一共有多少空格
    int blankCount = 0;
    for (int i = 0; i < length; i++) {
        char elem = a[i];
        if (elem == ' ') {
            blankCount++;
        }
    }

    // 计算 添加空格之后的数组长度
    int len = length + blankCount * 2;

    int lastP = len;
    int lastV = length-1;

    //从后往前遍历
    for (int i = lastV; i >=0; i--) {
        char elem = a[i];
        printf("%c\n",elem);
        if (elem == ' ') {
            //如果是空格
            int index = lastV;
            for (int j = lastP; j > lastV; j--) {
                printf("%c\n",a[index]);
                a[lastP] = a[index];
                index--;
                lastP--;
                printf("%s\n",a);
            }

            a[i] = '%';
            a[i+1] = '2';
            a[i+2] = '0';

            lastV-=2;
            printf("%s",a);
        }

    }
    
    printf("%s",a);

}

void replaceStringToBlank1(char *a,int length) {
    if (length <= 0) {
        return;
    }
    
    int originalLength = 0;
    int numberOfBlank = 0;
    int i = 0;
    while (a[i] != '\0') {
        ++originalLength;
        if (a[i] == ' ') {
            ++numberOfBlank;
        }
        ++i;
    }
    
    int newLength = originalLength + numberOfBlank * 2;
    
    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
    while (indexOfOriginal >=0 && indexOfNew > indexOfOriginal) {
        if (a[indexOfOriginal] == ' ') {
            a[indexOfNew--] = '0';
            a[indexOfNew--] = '2';
            a[indexOfNew--] = '%';
        } else {
            a[indexOfNew--] = a[indexOfOriginal];
        }
        
        --indexOfOriginal;
        
    }
    
    printf("%s",a);
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        char a[20] = "we are happy.";
        replaceStringToBlank(a, 17);
        
        printf("---");
        printf("%s",a);
    }
    return 0;
}
