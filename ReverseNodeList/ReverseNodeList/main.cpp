//
//  main.cpp
//  ReverseNodeList
//
//  Created by LeeWong on 2018/3/7.
//  Copyright © 2018年 LeeWong. All rights reserved.
//

#include <iostream>
#include<iostream>
#include<stack>

/*
 题目:
 输入一个链表的头结点，从头到尾反过来打印每个结点的值
 **/

struct ListNode {
    int m_nKey;
    ListNode * m_pNext;
};

/*
 遍历一遍链表 将链表的所有元素一次入栈 根据栈的 后进先出的特性 在依次输出栈内的元素
 **/
void ReverseNodeList(ListNode *pHead) {
    //声明一个栈
    std::stack <ListNode *> nodes;
    
    ListNode *pNode = pHead;
    while (pNode->m_pNext != nullptr) {
        nodes.push(pNode);
        pNode = pNode->m_pNext;
    }
    
    //先进后出 出站
    while (!nodes.empty()) {
        pNode = nodes.top();
        printf("%d\t",pNode->m_nKey);
        nodes.pop();
    }
    
}


/*利用递归的思路来解决
 问题：当链表非常长的时候 就会导致函数的调用层级很深从而有可能导致函数调用栈溢出
 */
void ReverseNodeListElem(ListNode *pHead) {
    
    if (pHead->m_pNext != nullptr) {
        ReverseNodeList(pHead->m_pNext);
    }
    printf("%d\t",pHead->m_nKey);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    ListNode *node = new ListNode();
    node->m_nKey = 1;
    node->m_pNext = nullptr;
    
    int j = 2;
    ListNode *pre = node;
    while (j < 10) {
        ListNode *n = new ListNode();
        pre->m_pNext = n;
        n->m_nKey = j;
        n->m_pNext = nullptr;
        pre = n;
        j++;
    }
    
    ReverseNodeListElem(node);
    return 0;
}
