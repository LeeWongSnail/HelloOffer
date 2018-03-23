//
//  main.cpp
//  PrintTreeTopToBottom
//
//  Created by LeeWong on 2018/3/22.
//  Copyright © 2018年 LeeWong. All rights reserved.
//

/*
 不分行从上到下打印二叉树
 从上到下打印出二叉树的每一个节点，同一层的节点按照从左到右的顺序打印
 例如
            8
    6               10
 5      7       9       11
 则一次打印出8，6，10，5，7，9，11
 **/

#include <iostream>

struct BinaryTreeNode {
    int m_pValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};


void PrintTreeNode(BinaryTreeNode *pLeft, BinaryTreeNode *pRight) {
    if (pLeft != nullptr) {
        printf("%d\n",pLeft->m_pValue);
    }
    
    if (pRight != nullptr) {
        printf("%d\n",pRight->m_pValue);
    }
    if (pLeft != nullptr) {
        
        PrintTreeNode(pLeft->m_pLeft, pLeft->m_pRight);
    }
    if (pRight != nullptr) {
        PrintTreeNode(pRight->m_pLeft, pRight->m_pRight);
    }
}

void PrintTree(BinaryTreeNode *pRoot) {
    if (pRoot == nullptr) {
        return;
    }
    printf("%d\n",pRoot->m_pValue);
    PrintTreeNode(pRoot->m_pLeft, pRoot->m_pRight);
}

BinaryTreeNode* CreateBinaryTreeNode(int value)
{
    BinaryTreeNode* pNode = new BinaryTreeNode();
    pNode->m_pValue = value;
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
    
    PrintTree(pNode10);
    return 0;
}
