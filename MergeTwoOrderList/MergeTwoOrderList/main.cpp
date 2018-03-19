//
//  main.cpp
//  MergeTwoOrderList
//
//  Created by LeeWong on 2018/3/19.
//  Copyright © 2018年 LeeWong. All rights reserved.
//

/*
 输入liangge 递增排序的链表,合并这两个链表并使新的链表中的节点仍然是递增有序的。
 例如 输入图3.1.1中的 链表1和链表2 则合并之后的圣墟链表如链表3所示
 
 struct ListNode{
 int m_nValue;
 ListNode *m_pNext;
 };
 
 1 3 5 7
 2 4 6 8
 
 1 2 3 4 5 6 7 8
 
 **/

#include <iostream>


struct ListNode{
    int m_nValue;
    ListNode *m_pNext;
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


ListNode * MergeTwoList(ListNode *pHead1,ListNode *pHead2) {
    
    if (pHead1 == nullptr) {
        return pHead2;
    } else if (pHead2 == nullptr) {
        return pHead1;
    }
    
    ListNode *pMerageHead = nullptr;
    if (pHead1->m_nValue < pHead2->m_nValue) {
        pMerageHead = pHead1;
        pMerageHead->m_pNext = MergeTwoList(pHead1->m_pNext, pHead2);
    } else {
        pMerageHead = pHead2;
        pMerageHead->m_pNext = MergeTwoList(pHead1, pHead2->m_pNext);
    }
    return pMerageHead;
}

ListNode * MergeTwoList2(ListNode *pHead1,ListNode *pHead2) {
    
    if (pHead1 == nullptr) {
        return pHead2;
    } else if (pHead2 == nullptr) {
        return pHead1;
    }
    
    ListNode *pMerageHead = nullptr;
    ListNode *pNext = nullptr;
    ListNode *pPre = nullptr;
    while (pHead1!= nullptr && pHead2 != nullptr) {
        
        if (pHead1->m_nValue < pHead2->m_nValue) {
            if (pMerageHead == nullptr) {
                pMerageHead = pHead1;
                pHead1= pHead1->m_pNext;
                pNext = pMerageHead;
                pNext->m_pNext = nullptr;
            } else {
                pPre = pNext;
                pNext = pHead1;
                pPre->m_pNext = pNext;
                pHead1 = pHead1->m_pNext;
                pNext ->m_pNext = nullptr;
            }
            
        } else {
            if (pMerageHead == nullptr) {
                pMerageHead = pHead2;
                pHead2= pHead2->m_pNext;
                pNext = pMerageHead;
                pNext->m_pNext = nullptr;
            } else {
                pPre = pNext;
                pNext = pHead2;
                pPre->m_pNext = pNext;
                pHead2 = pHead2->m_pNext;
                pNext ->m_pNext = nullptr;
            }
            
        }
        
    }
    
    if (pHead1 == nullptr) {
        pNext->m_pNext = pHead2;
    }
    
    if (pHead2 == nullptr) {
        pNext->m_pNext = pHead1;
    }
    return pMerageHead;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(5);
    
    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);
    
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode6 = CreateListNode(6);
    
    ConnectListNodes(pNode2, pNode4);
    ConnectListNodes(pNode4, pNode6);
    
    ListNode* pMergedHead = MergeTwoList2(pNode1, pNode2);
    while (pMergedHead != nullptr) {
        printf("%d\n",pMergedHead->m_nValue);
        pMergedHead= pMergedHead->m_pNext;
    }
    return 0;
}
