//
//  main.cpp
//  DeleteNodeInList
//
//  Created by LeeWong on 2018/3/14.
//  Copyright © 2018年 LeeWong. All rights reserved.
//

/*
 在O(1)的时间内删除链表的节点
 给定单项链表的头指针和一个节点指针 定义一个函数在O(1)时间内删除该节点。链表节点与函数定义如下
 
 struct ListNode
 {
 int       m_nValue;
 ListNode* m_pNext;
 };
 **/

#include <iostream>
#include <cstdio>

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


void deleteNodeInList(ListNode **pListHead,ListNode *pToBeDeleted) {
    if (!pListHead || !pToBeDeleted) {
        return;
    }
    
    //要删除的节点如果不是尾节点
    if (pToBeDeleted->m_pNext != nullptr) {
        ListNode *node = pToBeDeleted->m_pNext;
        pToBeDeleted->m_nValue = node->m_nValue;
        pToBeDeleted->m_pNext = node->m_pNext;
        
        delete node;
        node = nullptr;
    } else if (*pListHead == pToBeDeleted) {
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
        *pListHead = nullptr;
    } else {
        ListNode *pNode = *pListHead;
        while (pNode->m_pNext != pToBeDeleted) {
            pNode = pNode->m_pNext;
        }
        
        pNode->m_pNext = nullptr;
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }
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
    
    deleteNodeInList(&pNode1, pNode3);
    
    
    ListNode *pNode = pNode1;
    while (pNode->m_pNext != nullptr) {
        PrintListNode(pNode);
        pNode=pNode->m_pNext;
    }
    return 0;
}
