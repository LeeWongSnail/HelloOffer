//
//  main.cpp
//  DeleteDuplicationNode
//
//  Created by LeeWong on 2018/3/15.
//  Copyright © 2018年 LeeWong. All rights reserved.
//

/*
 删除链表中的重复节点
 在一个排序的链表中 如何删除重复的节点
 例如 1 2 3 3 4 4 5 中重复的节点被删除后  1 2 5
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


void deleteDuplication(ListNode **pHead) {
    if (pHead == nullptr || *pHead == nullptr) {
        return;
    }
    
    ListNode *pPreNode = nullptr;
    ListNode *pNode = *pHead;
    
    while (pNode != nullptr) {
        
        ListNode *pNext = pNode->m_pNext;
        bool needDelete = false;
        //判断是否可以被删除
        if (pNext != nullptr && pNext->m_nValue == pNode->m_nValue) {
            needDelete = true;
        }
        
        if (!needDelete) {
            //如果不需要被删除
            pPreNode = pNext;
            pNode = pNode->m_pNext;
        } else {
            //如果需要被删除 这里 因为相同的节点可能大于2个 因此这里需要重新遍历一下
            int value = pNode->m_nValue;
            ListNode *pToBeDelete = pNode;
            while (pToBeDelete != nullptr && pToBeDelete->m_nValue == value) {
                //删除这个节点
                pNext = pToBeDelete->m_pNext;
                delete pToBeDelete;
                pToBeDelete = nullptr;
                
                pToBeDelete = pNext;
            }
            
            //以上可以将要删除的节点删除 下面考虑 删除之后
            if (pPreNode == nullptr) {
                //被删除的是链表的首节点
                *pHead = pNext;
            } else {
                pPreNode->m_pNext = pNext;
            }
            
            pNode = pNext;
            
        }
        
        
    }
    
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(2);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);
    
    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    
    deleteDuplication(&pNode1);
    
    
    ListNode *pNode = pNode1;
    while (pNode != nullptr) {
        PrintListNode(pNode);
        pNode=pNode->m_pNext;
    }
    return 0;
}
