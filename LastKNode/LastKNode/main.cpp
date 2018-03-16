//
//  main.cpp
//  LastKNode
//
//  Created by LeeWong on 2018/3/16.
//  Copyright © 2018年 LeeWong. All rights reserved.
//

/*
 输入一个链表,输入改链表中倒数第k个节点。
 为了符合大多数人的习惯，本题从1开始计数 即链表的尾节点是倒数第一个节点
 例如 一个链表有6个节点 从头结点开始 他们的值一次是 1 2 3 4 5 6 这个链表的倒数第三个节点的值为4 链表节点定义如下
 
 struct ListNode {
 int m_nValue;
 listNode *m_pNext;
 }
 **/

#include <iostream>

struct ListNode {
    int m_nValue;
    ListNode *m_pNext;
};

ListNode * LastKNode(ListNode *pListHead,unsigned int k) {
    
    //判断 是否符合条件
    //k从1开始 不能为0 链表的头结点也不可以为空
    if (k == 0 || pListHead == nullptr) {
        return nullptr;
    }
    
    ListNode *pAHead = pListHead;
    ListNode *pBehind = nullptr;
    
    for (unsigned int i = 0; i <k; i++) {
        //链表的长度可能不足k个节点 这里需要注意
        if (pAHead ->m_pNext != nullptr) {
            pAHead = pAHead->m_pNext;
        }else {
            return nullptr;
        }
    }
    
    pBehind = pListHead;
    
    while (pAHead != nullptr) {
        pAHead = pAHead->m_pNext;
        pBehind = pBehind->m_pNext;
    }
    
    return pBehind;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    return 0;
}
