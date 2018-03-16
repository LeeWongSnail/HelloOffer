//
//  main.cpp
//  EntryNodeOfLoop
//
//  Created by LeeWong on 2018/3/16.
//  Copyright © 2018年 LeeWong. All rights reserved.
//

/*
 如果一个链表中包含环 如何找出换的入口节点
 **/

#include <iostream>

struct ListNode {
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

//要查找到入口节点 首先确认这是一个有环的链表 然后找到一个在环中的节点
// pslow在第一个节点 pfast在第二个节点 pslow一次走一步 pfast一次走两步
// 直到最后相遇
ListNode *meetNode(ListNode *pHead) {
    
    if (pHead == nullptr) {
        return nullptr;
    }
    
    ListNode *pSlow = pHead->m_pNext;
    //一定要有这种判断
    if (pSlow->m_pNext == nullptr) {
        return nullptr;
    }
    
    ListNode *pFast = pSlow->m_pNext;
    while (pFast != nullptr && pSlow != nullptr) {
        
        if (pFast == pSlow) {
            return pFast;
        }
        
        pSlow = pSlow->m_pNext;
        
        pFast = pFast->m_pNext;
        if (pFast != nullptr) {
            pFast = pFast->m_pNext;
        }
    }
    
    //没有环
    return nullptr;
}


// 在已知这个链表有环的情况下 如何找到这个环的入口
// 1、先获取这个环中节点的数目n
// 2、p1指向第一个节点 p2指向 第n个节点
// 3、p1 p2一次向后走 如果p1==p2了 就说明这个节点是入口节点！
// 步骤3 的原因
// 链表的长度是n 环中的节点数是m 那么入口就在 n-m的地方
// p1走了n-m步之后到了环的入口 p2走了n-m不之后到了链表末尾元素的下一个元素也就是环的第一个元素
ListNode * EntryNodeOfLoop(ListNode *pHead) {
    
    ListNode *meettingNode = meetNode(pHead);
    if (meettingNode == nullptr) {
        //说明 链表中没有环
        return nullptr;
    }
    
    //计算环中节点的个数
    int nodeInLoop = 1;
    //meetingnode是环中的某个节点
    ListNode *pNode1 = meettingNode;
    while (pNode1->m_pNext != meettingNode) {
        pNode1 = pNode1->m_pNext;
        nodeInLoop ++;
    }
    
    //拿到环中的节点数
    // pNode 指向第nodeInLoop个节点
    pNode1 = pHead;
    for (int i = 0; i < nodeInLoop; i++) {
        pNode1 = pNode1->m_pNext;
    }
    
    //pNode2指向队首的元素
    ListNode *pNode2 = pHead;
    
    //一次往后走 直到这两个指针指向同一个节点
    while (pNode1 != pNode2) {
        pNode2 = pNode2->m_pNext;
        pNode1 = pNode1->m_pNext;
    }
    
    return pNode1;
    
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
    ConnectListNodes(pNode5, pNode3);
    
    ListNode *node = EntryNodeOfLoop(pNode1);
    printf("%d",node->m_nValue);
    return 0;
}
