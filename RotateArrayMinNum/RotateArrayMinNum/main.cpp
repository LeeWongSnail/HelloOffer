//
//  main.cpp
//  RotateArrayMinNum
//
//  Created by LeeWong on 2018/3/12.
//  Copyright © 2018年 LeeWong. All rights reserved.
//

/*
 把一个数组最开始的若干个元素搬到数组的末尾,我们称之为数组的旋转。
 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素
 例如：数组{3,4,5,1,2} 为{1，2，3，4，5}的一个旋转 该数组的最小值为1
 **/


#include <iostream>


int MinInOrder(int nums[],int index1, int index2) {
    int result = nums[index1];
    for (int i = 0; i < index2; i++) {
        if (result > nums[i]) {
            result = nums[i];
        }
    }
    return result;
}

//已知默认数组是一个递增的
int getMinNumInArray(int nums[],int length) {

    int index1 = 0;
    int index2 = length - 1;
    int indexMid = index1;
    
    while (nums[index1] >= nums[index2]) {
        
        if (index2 - index1 == 1) {
            indexMid = index2;
            break;
        }
        
        indexMid = (index1 + index2)/2;
        
        if (nums[index1] == nums[index2] && nums[indexMid] == nums[index1]) {
            MinInOrder(nums, index1, index2);
        }
        
        if (nums[indexMid] >= nums[index1]) {
            index1 = indexMid;
        } else if (nums[indexMid] <= nums[index2]) {
            index2 = indexMid;
        }
        
        
    }
    
    
    return nums[indexMid];
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int a[5] = {3,4,5,1,2};
    int min = getMinNumInArray(a,5);
    printf("%d",min);
    return 0;
}
