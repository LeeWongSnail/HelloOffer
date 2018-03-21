//
//  main.cpp
//  StackWithMinFunction
//
//  Created by LeeWong on 2018/3/21.
//  Copyright © 2018年 LeeWong. All rights reserved.
//


/*
 定义栈的数据结构 请在该类型中实现一个能够得到站的最小元素的min函数
 在改栈中 调用min push pop 的时间复杂度都是O(1)
 **/

#include <iostream>
#include <stack>
#include "StackWithMin.h"

/*栈的特性是后进先出
正常思路 如果要在O(1)的时间内找到最小的元素 那么我们可以对栈内的元素进行排序 将最小的元素放到栈顶
 但是这样存在一个问题: 那么这个栈就不是后进先出的了 这根栈的最基本特性违背 因此这种做法是错误的
 
 其他方法: 我们可以 记住栈中的最小元素 每次push的时候都进行比较 然后记录最小值
 但是这样也存在一个问题： 最小值出栈之后 次小值是多少
 
 鉴于上面两种方法都不行 因此我们需要记录 栈中每个结点被push入栈的时候栈中所有元素的最小值 即便是最小值出栈了 我们仍然可以
 获取到剩余栈中的元素的最小值
**/



int main(int argc, const char * argv[]) {
    // insert code here...
    StackWithMin<int> stack;
    stack.push(3);
    stack.push(4);
    stack.push(2);
    printf("%d",stack.min());
    stack.push(3);
    printf("%d",stack.min());
    stack.pop();
    printf("%d",stack.min());
    stack.pop();
    stack.pop();
    printf("%d",stack.min());
    stack.push(0);
    printf("%d",stack.min());
    return 0;
}
