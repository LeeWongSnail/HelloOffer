//
//  main.cpp
//  TwoStack2Queue
//
//  Created by LeeWong on 2018/3/12.
//  Copyright © 2018年 LeeWong. All rights reserved.
//

/*
 题目：
 用两个栈实现一个队列。
 队列声明如下 请实现他的两个函数appendTail和deleteHead 分别完成在队列尾部插入节点和队列头部删除节点的功能
 **/

#include "CQueue.h"






int main(int argc, const char * argv[]) {
    // insert code here...
     CQueue<int> queue;

    queue.appendTail(1);
    queue.appendTail(2);
    queue.appendTail(3);
    queue.appendTail(4);
    
    queue.printQueue();
    

    queue.deleteHead();
    queue.deleteHead();
    
    queue.printQueue();

    queue.appendTail(5);
    queue.appendTail(6);

    queue.printQueue();
    
    queue.deleteHead();
    
    queue.printQueue();
    

    
    return 0;
}
