//
//  main.m
//  DuplicateNumInArray
//
//  Created by LeeWong on 2018/3/5.
//  Copyright © 2018年 LeeWong. All rights reserved.
//

//面试题3：数组中重复的数字
//题目一：找出数组中重复的数字
//    在一个长度为n的数组里的所有数字都在0~n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了儿次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2，3，1，0，2，5，3}，那么对应的输出是重复的数字2或者3。

#import <Foundation/Foundation.h>



void sort(int *a, int left, int right)
{
    if(left >= right)/*如果左边索引大于或者等于右边的索引就代表已经整理完成一个组了*/
    {
        return ;
    }
    int i = left;
    int j = right;
    int key = a[left];
    
    while(i < j)                               /*控制在当组内寻找一遍*/
    {
        while(i < j && key <= a[j])
        /*而寻找结束的条件就是，1，找到一个小于或者大于key的数（大于或小于取决于你想升
         序还是降序）2，没有符合条件1的，并且i与j的大小没有反转*/
        {
            j--;/*向前寻找*/
        }
        
        a[i] = a[j];
        /*找到一个这样的数后就把它赋给前面的被拿走的i的值（如果第一次循环且key是
         a[left]，那么就是给key）*/
        
        while(i < j && key >= a[i])
        /*这是i在当组内向前寻找，同上，不过注意与key的大小关系停止循环和上面相反，
         因为排序思想是把数往两边扔，所以左右两边的数大小与key的关系相反*/
        {
            i++;
        }
        
        a[j] = a[i];
    }
    
    a[i] = key;/*当在当组内找完一遍以后就把中间数key回归*/
    sort(a, left, i - 1);/*最后用同样的方式对分出来的左边的小组进行同上的做法*/
    sort(a, i + 1, right);/*用同样的方式对分出来的右边的小组进行同上的做法*/
    /*当然最后可能会出现很多分左右，直到每一组的i = j 为止*/
}

/**
 先把输入的数组排序(快速排序) 然后从头到尾扫描数组中的数字
 */
int duplicateNum1(int list[]) {
    
    //先排序
    sort(list, 0, 6);
    int index = -1;
    for (int i = 1; i<7; i++) {
        if (list[i] == list[i-1]) {
            index = i;
            break;
        }
    }
    
    
    return list[index];
}


void duplicateNum2(int list[]) {
    //创建一个空的哈希表
    //遍历这个数组 判断当前元素是否在哈希表中
    //如果没有则加入哈希表
    //如果有那么久找到了这个重复的元素
}

//这个方法只是适用于 长度为n的数组 且数组中包含0~n-1之内的数字
int duplicateNum3(int list[],int length) {
    
    //先判断数组是否为空
    if (sizeof(*list) == 0 || length <=0) {
        return -1; //-1表示不符合条件的输入
    }
    for (int i = 0; i < length; i++) {
        if (list[i] < 0 || list[i] > length-1) {
            return -1;  //-1表示不符合条件的输入
        }
    }

   
    
    int index = -1;
    for (int i = 0; i < length; i++) {
        
        while (list[i] != i) {
            if (list[i] < length) {
                int j = list[i];
                if (list[j] == j) {
                    return list[i];
                }
                int temp = j;
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
    
    return list[index];
}


int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        
        int a[] = {2,3,1,0,2,5,3};
        int value = duplicateNum3(a,7);
        printf("重复数字的值为:%d\n",value);
        
    }
    return 0;
}


