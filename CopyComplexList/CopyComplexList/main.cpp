//
//  main.cpp
//  CopyComplexList
//
//  Created by LeeWong on 2018/3/26.
//  Copyright © 2018年 LeeWong. All rights reserved.
//

/*
 复杂的链表复制
 请实现函数ComplexListNode *Clone(ComplexListNode *pHead) 复制一个复杂链表。
 在复杂链表中 每个节点除了有一个m_pNext指针指向下一个节点，还有一个m_pSibling 指针指向链表中的任一节点
 或者 nullptr
 **/


#include <iostream>
#include <map>
#include <string>

struct ComplexListNode {
    int m_nValue;
    ComplexListNode *p_Next;
    ComplexListNode *p_Sibling;
};


ComplexListNode* CreateListNode(int value)
{
    ComplexListNode* pNode = new ComplexListNode();
    pNode->m_nValue = value;
    pNode->p_Next = nullptr;
    pNode->p_Sibling = nullptr;
    
    return pNode;
}

// 复制一个复杂的链表 最直观的方法是直接遍历一遍这个链表 将m_pNext指针指向正确的位置
// 然后在一次为每一个节点设置对应的m_pSibling

ComplexListNode *CloneList(ComplexListNode *pHead) {
    if (pHead == nullptr) {
        return nullptr;
    }
    
    ComplexListNode *pNode = pHead;
    ComplexListNode *pNewHead = nullptr;
    ComplexListNode *pNext = nullptr;
    while (pNode != nullptr) {
        ComplexListNode *node = CreateListNode(pNode->m_nValue);
        if (pNewHead == nullptr) {
            pNext = pNode;
            pNewHead = pNext;
        } else {
           pNext ->p_Next = pNode;
           pNext = node;
        }
        pNode= pNode->p_Next;
    }
    
    //下面开始设置 m_Silibing
    pNext = pNewHead;
    while (pNext != nullptr) {
        if (pNext->p_Sibling == nullptr) {
            pNode = pHead;
            ComplexListNode *pSilibing = nullptr;
            while (pNode != nullptr) {
                if (pNode->m_nValue == pNext->m_nValue) {
                    pSilibing = pNode->p_Sibling;
                    break;
                }
            }
            
            //找到要指向的元素之后
            pNode = pNewHead;
            while (pNode != nullptr) {
                if (pNode->m_nValue == pSilibing->m_nValue) {
                    pNext->p_Sibling = pNode;
                    break;
                }
                pNode = pNode->p_Next;
            }
        }
        
    }
    
    
    return pNewHead;
}


// 第二种方法是我们可以借助一个哈希表 以空间换时间 每次都记住这个节点的m_pSibling对应的节点位置
// 这样我们只需要O(n)的时间就可以完成复制
ComplexListNode *CloneList2(ComplexListNode *pHead) {
    
    if (pHead == nullptr) {
        return nullptr;
    }
    // 创建一个哈希表用来保存对应关系
    std::map<ComplexListNode, ComplexListNode> mapList;
//    std::map<ComplexListNode, ComplexListNode> mapList;
    
    ComplexListNode *pNode = pHead;
    ComplexListNode *pNewHead = nullptr;
    ComplexListNode *pNext = nullptr;
    //在
    while (pNode != nullptr) {
        ComplexListNode *node = CreateListNode(pNode->m_nValue);
        if (pNewHead == nullptr) {
            pNext = pNode;
            pNewHead = pNext;
        } else {
            pNext ->p_Next = pNode;
            pNext = node;
        }
        //插入对应的内容
//        mapList.insert(node, pNode->p_Sibling);
        pNode= pNode->p_Next;
    }
    
    pNode = pNewHead;
    ComplexListNode *siBling = nullptr;
    while (pNode != nullptr) {
        std::map<ComplexListNode, ComplexListNode>::iterator it;
        //这里操作不会 暂时先放一下
        
    }
    
    return nullptr;
}


// 第三种方法是  我们采用在链表里直接复制的方法,将原链表中的每一个元素指向将他复制之后的那个元素 然后复制出来的元素在指向原链表
// 节点中m_pNext指向的节点
// 然后通过一次遍历 将新复制出来的节点的m_pSibling节点的指向 之前指向节点的副本
// 最后将现有的节点拆开 将奇数节点和偶数节点 分别组成一个新的链表 那么这两个链表是一样的

//第一步 先复制一遍
void CloneNodes(ComplexListNode *pHead) {
    ComplexListNode *pNode = pHead;
    
    while (pNode != nullptr) {
        
        ComplexListNode *pCloned = CreateListNode(pNode->m_nValue);
        pCloned->p_Next = pNode->p_Next;
        pCloned->p_Sibling = nullptr;
        
        pNode->p_Next = pCloned;
        pNode = pCloned->p_Next;
    }
    
}

// 设置新复制节点的sibling指向
void ConnectSiblingNodes(ComplexListNode *pHead) {
    ComplexListNode *pNode = pHead;
    
    while (pNode != nullptr) {
        ComplexListNode *pCloneD = pNode->p_Next;
        if (pNode->p_Sibling != nullptr) {
            pCloneD->p_Sibling = pNode->p_Sibling->p_Next;
        }
        
        pNode = pCloneD->p_Next;
    }
}



// 将原来的一个链表 拆分为两个链表 奇数节点链接成一个链表 偶数节点链接成一个链表
ComplexListNode *ReConnectNodes(ComplexListNode *pHead) {
    
    ComplexListNode *pNode = pHead;
    ComplexListNode *pClonedHead = nullptr;
    ComplexListNode *pClonedNode = nullptr;
    
    //找到一个头结点
    if (pNode != nullptr) {
        pClonedHead = pClonedNode = pNode->p_Next;
        pNode->p_Next = pClonedNode->p_Next;
        pNode = pNode->p_Next;
    }
    
    
    while (pNode != nullptr) {
        pClonedNode->p_Next = pNode->p_Next;
        pClonedNode = pClonedNode->p_Next;
        pNode->p_Next = pClonedNode->p_Next;
        pNode = pNode->p_Next;
    }
    return pClonedHead;
}


ComplexListNode *Clone(ComplexListNode *pHead) {
    // 现将整体复制一遍 并将复制的节点链接在原来的节点后面
    CloneNodes(pHead);
    // 依次设置新复制节点的sibling节点
    ConnectSiblingNodes(pHead);
    //将奇数位置的节点和偶数节点分辨连城一个新的链表
    return ReConnectNodes(pHead);
}


void BuildNodes(ComplexListNode* pNode, ComplexListNode* pNext, ComplexListNode* pSibling)
{
    if(pNode != nullptr)
    {
        pNode->p_Next = pNext;
        pNode->p_Sibling = pSibling;
    }
}

void PrintList(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    while(pNode != nullptr)
    {
        printf("The value of this node is: %d.\n", pNode->m_nValue);
        
        if(pNode->p_Sibling != nullptr)
            printf("The value of its sibling is: %d.\n", pNode->p_Sibling->m_nValue);
        else
            printf("This node does not have a sibling.\n");
        
        printf("\n");
        
        pNode = pNode->p_Next;
    }
}

//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//  |       |      /|\             /|\
//  --------+--------               |
//          -------------------------
int main(int argc, const char * argv[]) {
    // insert code here...
    ComplexListNode* pNode1 = CreateListNode(1);
    ComplexListNode* pNode2 = CreateListNode(2);
    ComplexListNode* pNode3 = CreateListNode(3);
    ComplexListNode* pNode4 = CreateListNode(4);
    ComplexListNode* pNode5 = CreateListNode(5);
    
    BuildNodes(pNode1, pNode2, pNode3);
    BuildNodes(pNode2, pNode3, pNode5);
    BuildNodes(pNode3, pNode4, nullptr);
    BuildNodes(pNode4, pNode5, pNode2);

    ComplexListNode *pHead = Clone(pNode1);
    
    //打印之前的链表
    PrintList(pNode1);
    //打印拷贝的链表
    PrintList(pHead);
    return 0;
}
