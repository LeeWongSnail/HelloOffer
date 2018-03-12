//
//  CQueue.h
//  TwoStack2Queue
//
//  Created by LeeWong on 2018/3/12.
//  Copyright © 2018年 LeeWong. All rights reserved.
//

#pragma once
#include <stack>
#include <exception>

template <typename T>
class CQueue {
private:
    std::stack<T> stack1;
    std::stack<T> stack2;
    
public:
    CQueue(void);
    ~CQueue(void);
    
    void appendTail(const T & node);
    T deleteHead();
    void printQueue();
};

template <typename T> CQueue<T>::CQueue(void)
{
}

template <typename T> CQueue<T>::~CQueue(void)
{
}

template <typename T>
void CQueue<T>::printQueue() {
    std::stack<T> tempStack;
//    printf("%d\n",stack2.size());
    if (stack2.size() > 0) {
        int size = stack2.size();
        for (int i = 0; i < size; i++) {
            T head = stack2.top();
            stack2.pop();
            tempStack.push(head);
        }
        //还原stack2
        for (int j = 0; j < size; j++) {
            T head = tempStack.top();
            tempStack.pop();
            stack2.push(head);
            printf("%d\n",head);
        }
    }
//    printf("%d\n",stack1.size());
    if (stack1.size() > 0)
    {
        for (int j = 0; j < tempStack.size(); j++) {
            tempStack.pop();
        }
        int size = stack1.size();
        for (int i = 0; i < size; i++) {
            T head = stack1.top();
            stack1.pop();
            tempStack.push(head);
        }
        //还原stack1
        for (int j = 0; j < size; j++) {
            T head = tempStack.top();
            tempStack.pop();
            stack1.push(head);
            printf("%d\n",head);
        }
        
    }
}

//在队列尾部插入节点
template <typename T>
void CQueue<T>::appendTail(const T & element) {
    stack1.push(element);
}

//在队列头部删除节点
template <typename T>
T CQueue<T>::deleteHead() {
    if (stack2.size() > 0) {
        //如果stack2中有值则直接top这个值
        T head = stack2.top();
        stack2.pop();
        return head;
    } else if (stack2.size() == 0 && stack1.size() > 0) {
        //stack2为空 stack1 不为空
        //将stack1中的内容 转移到stack2中
        int size = stack1.size();
        for (int i =0; i < size; i++) {
            T head = stack1.top();
            stack2.push(head);
            stack1.pop();
        }
        
        //此时 stack1为空 stack2不为空
        T head  =stack2.top();
        stack2.pop();
        return head;
    } else {
        printf("queue is empty");
    }
    return 0;
}

