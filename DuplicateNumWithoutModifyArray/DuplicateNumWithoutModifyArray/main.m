//
//  main.m
//  DuplicateNumWithoutModifyArray
//
//  Created by LeeWong on 2018/3/5.
//  Copyright © 2018年 LeeWong. All rights reserved.
//

/**
 题目二：不修改数组找出重复的数字。在一个长度为n+1的数组里的所有数字都在1~n的范围内，
 所以数组中至少有一个数字是重复的。请找出数组中任意一个重复的数字，但不能修改输入的数组。
 例如，如果输入长度为8的数组{2，3，5，4，3，2，6，7}，那么对应的输出是重复的数字2或者3。
 */

#import <Foundation/Foundation.h>

/**
 数组list 长度为length 在start到end区间内的值的个数
 */
int countInRange(int list[],int length,int start , int end) {

    if (sizeof(*list) == 0) {
        return -1;
    }
    
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (list[i] >= start && list[i] <= end) {
            count++;
        }
    }
    
    return count;
}


int getDuplicateWithoutModify(int list[],int length) {
    
    //先判断数组是否为空 length是否合法
    if (sizeof(*list) == 0 || length <= 0) {
        return -1;
    }
    
    int start = 1;
    int end = length -1;
    
    while (end >= start) {
        int middle = (end-start)/2 +start;
        //计算start到middle之间的数字的个数
        int count = countInRange(list, length, start, middle);
        
        if (start == end) {
            if (count > 1) {
                return start;
            } else {
                break;
            }
        }
        
        if (count > middle-start + 1) {
            end = middle;
        } else {
            start = middle+1;
        }
    }
    
    return -1;
}





int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...x
        int list[] = {2,3,5,4,3,2,6,7};
        int result = getDuplicateWithoutModify(list, 7);
        printf("结果是: %d\n",result);
    }
    return 0;
}
