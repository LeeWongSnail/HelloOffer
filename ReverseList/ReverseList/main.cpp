//
//  main.cpp
//  ReverseList
//
//  Created by LeeWong on 2018/3/17.
//  Copyright © 2018年 LeeWong. All rights reserved.
//

/*
 反转链表
 定义一个函数，输入一个链表的头结点 反转该链表并输出翻转后链表的头结点 链表的节点定义如下下
 
 struct ListNode
 {
 int       m_nValue;
 ListNode* m_pNext;
 };
 **/

#include <iostream>

struct ListNode
{
    int       m_nValue;
    ListNode* m_pNext;
};

ListNode* CreateListNode(int value)
{
    ListNode* pNode = new ListNode();
    pNode->m_nValue = value;
    pNode->m_pNext = nullptr;
    
    return pNode;
}

void ConnectListNodes(ListNode* pCurrent, ListNode* pNext)
{
    if(pCurrent == nullptr)
    {
        printf("Error to connect two nodes.\n");
        exit(1);
    }
    
    pCurrent->m_pNext = pNext;
}

void PrintListNode(ListNode* pNode)
{
    if(pNode == nullptr)
    {
        printf("The node is nullptr\n");
    }
    else
    {
        printf("The key in node is %d.\n", pNode->m_nValue);
    }
}


ListNode *ReverseListNode(ListNode *pHead) {
    
    ListNode *pReversedHead = nullptr;
    ListNode *pNode = pHead;
    ListNode *pPrev = nullptr;
    while (pNode != nullptr) {
        ListNode *next = pNode->m_pNext;
        
        //记录最后一个节点
        if (next == nullptr) {
            pReversedHead = pNode;
        }
        
        //主要的循环
        //第一次走的时候会把之前头结点的next置为null
        pNode->m_pNext = pPrev;
        //pPrev指向第一个节点
        pPrev = pNode;
        //pNode指向自己的下一个节点
        pNode = next;
    }
    return pReversedHead;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);
    
    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    
    ListNode *pNode = ReverseListNode(pNode1);
    
    while (pNode != nullptr) {
        PrintListNode(pNode);
        pNode=pNode->m_pNext;
    }
    return 0;
}
