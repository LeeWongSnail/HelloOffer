//
//  main.cpp
//  ConvertBinarySearchTree
//
//  Created by LeeWong on 2018/3/27.
//  Copyright © 2018年 LeeWong. All rights reserved.
//


/*
 二叉搜索树与双向链表
 输入一颗二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。

 **/

#include <iostream>

struct BinaryTreeNode {
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};

// 因为组成链表的顺序是从小到大有序的因此 我们可以根据二叉搜索树的中序遍历的序列来做
// 这个题目我们可以采用递归的思路
// 第一: 根节点的m_pLeft肯定是指向左子树中值最大的那个节点 同时最大的节点的m_pRight也指向根节点
// 第二：根节点的m_pRight肯定指向右子树中值最小的那个节点 同时最小的节点的m_pLeft也指向根节点

//我们可以利用递归的思路 不断的去重复 ①和②这两个步骤 一直找到叶子节点 那么这个叶子节点的m_pLeft=nullptr
//叶子节点的m_pRight=叶子节点的父节点 因此利用一个变量(pLastNodeInList)来保存这个链表中的最后一个节点 在遇到下一个节点的时候
//将最后一个节点的m_pRight指向这个节点就可以了
void ConvertNode(BinaryTreeNode *pNode,BinaryTreeNode **pLastNodeInList) {
    
    if (pNode == nullptr) {
        return;
    }
    
    BinaryTreeNode *pCurrent = pNode;
    
    if (pCurrent->m_pLeft != nullptr) {
        ConvertNode(pCurrent->m_pLeft, pLastNodeInList);
    }
    
    //最左边的节点(最小值的节点)左边的指向null
    pCurrent->m_pLeft = *pLastNodeInList;
    
    
    if (*pLastNodeInList != nullptr) {
        (*pLastNodeInList)->m_pRight = pCurrent;
    }
    
    //更新链表中最后一个节点
    *pLastNodeInList = pCurrent;
    
    //递归去找右子树
    if (pCurrent->m_pRight != nullptr) {
        ConvertNode(pCurrent->m_pRight, pLastNodeInList);
    }
    
}


BinaryTreeNode *Convert(BinaryTreeNode *pRoot) {
    
    BinaryTreeNode *pLastNode = nullptr;
    
    ConvertNode(pRoot, &pLastNode);
    
    BinaryTreeNode *pHead = pLastNode;
    //获取到最后面的节点之后遍历这个双线链表 找到位于链表的第一个节点
    while (pHead != nullptr && pHead->m_pLeft != nullptr) {
        pHead = pHead->m_pLeft;
    }
    return pHead;
    
}

BinaryTreeNode* CreateBinaryTreeNode(int value)
{
    BinaryTreeNode* pNode = new BinaryTreeNode();
    pNode->m_nValue = value;
    pNode->m_pLeft = nullptr;
    pNode->m_pRight = nullptr;
    
    return pNode;
}

void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
    if(pParent != nullptr)
    {
        pParent->m_pLeft = pLeft;
        pParent->m_pRight = pRight;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode14 = CreateBinaryTreeNode(14);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
    BinaryTreeNode* pNode16 = CreateBinaryTreeNode(16);
    
    ConnectTreeNodes(pNode10, pNode6, pNode14);
    ConnectTreeNodes(pNode6, pNode4, pNode8);
    ConnectTreeNodes(pNode14, pNode12, pNode16);

    
   BinaryTreeNode *pHead = Convert(pNode10);
    
    while (pHead != nullptr) {
        printf("%d\n",pHead->m_nValue);
        pHead = pHead->m_pRight;
    }
    
    return 0;
}
