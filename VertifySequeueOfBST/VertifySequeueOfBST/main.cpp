//
//  main.cpp
//  VertifySequeueOfBST
//
//  Created by LeeWong on 2018/3/24.
//  Copyright © 2018年 LeeWong. All rights reserved.
//


/*
 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果
 如果是则返回true 如果不是则返回false
 假设输入的数组的任意两个数字都互不相同
 例如： 输入数组{5,7,6,9,11,10,8} 则返回true 因为这个整数序列是图4.9二叉搜索树的后续遍历结果。
 如果输入的数组是{7,4,6,5} 则由于没有哪个二叉搜索树的后续遍历结果是这个序列因此返回false
 
            8
    6               10
 5      7       9       11
 **/

#include <iostream>



// 这个题目的前提是要知道二叉搜索树的一个特点
// 根节点的值大于左子树的值
// 根节点的值大于右子树的值

bool VertifySequeueOfBST(int sequence[],int length) {
    
    if (sequence == nullptr || length <=0) {
        return false;
    }
    
    // 后续遍历特点 根节点是序列的最后一个元素
    int root = sequence[length-1];
    
    int i = 0;
    
    //找到左子树
    for (; i < length-1; i++) {
        if (sequence[i] > root) {
            break;
        }
    }
    
    // 前面的i个节点为左子树 剩下的为右子树
    int j = i;
    //右子树肯定要比根节点的值大
    for (; j <length-1; j++) {
        if (sequence[j] <= root) {
            return false;
        }
    }
    
    //判断左子树是否为二叉搜索树
    bool left = true;
    if (i > 0) {
        left = VertifySequeueOfBST(sequence, i);
    }
    //判断右子树是否为二叉搜索树
    bool right = true;
    if (j < length-1) {
        right = VertifySequeueOfBST(sequence, length-j-1);
    }
    
    return left && right;
}

int main(int argc, const char * argv[]) {
    // insert code here...
     int data[] = {4, 8, 6, 12, 16, 14, 10};
    if (VertifySequeueOfBST(data, 7)) {
        printf("这是二叉树的后续遍历的结果\n");
    } else {
        printf("这不是一个二叉树后续遍历的结果\n");
    }
    return 0;
}
