//
//  main.cpp
//  TreeMirror
//
//  Created by LeeWong on 2018/3/19.
//  Copyright © 2018年 LeeWong. All rights reserved.
//

/*
 请完成一个函数 输入一颗二叉树 该函数输出他的镜像。二叉树节点定义如下
 **/

#include <iostream>

struct BinaryTreeNode {
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};


// 使用递归的思路 将 二叉树镜像 变为么一个 根节点的左右子树的节点交换
void TreeMirror(BinaryTreeNode *pRoot) {
    if (pRoot == nullptr) {
        return;
    }
    
    if (pRoot->m_pLeft == nullptr && pRoot->m_pRight == nullptr) {
        return;
    }
    
    //使用递归的方法交换
    BinaryTreeNode *temp = pRoot->m_pLeft;
    pRoot->m_pLeft = pRoot->m_pRight;
    pRoot->m_pRight = temp;
    
    if (pRoot->m_pLeft) {
        TreeMirror(pRoot->m_pLeft);
    }
    if (pRoot->m_pRight) {
        TreeMirror(pRoot->m_pRight);
    }
    
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

void PrintTreeNode(const BinaryTreeNode* pNode)
{
    if(pNode != nullptr)
    {
        printf("value of this node is: %d\n", pNode->m_nValue);
        
        if(pNode->m_pLeft != nullptr)
            printf("value of its left child is: %d.\n", pNode->m_pLeft->m_nValue);
        else
            printf("left child is nullptr.\n");
        
        if(pNode->m_pRight != nullptr)
            printf("value of its right child is: %d.\n", pNode->m_pRight->m_nValue);
        else
            printf("right child is nullptr.\n");
    }
    else
    {
        printf("this node is nullptr.\n");
    }
    
    printf("\n");
}

void PrintTree(const BinaryTreeNode* pRoot)
{
    PrintTreeNode(pRoot);
    
    if(pRoot != nullptr)
    {
        if(pRoot->m_pLeft != nullptr)
            PrintTree(pRoot->m_pLeft);
        
        if(pRoot->m_pRight != nullptr)
            PrintTree(pRoot->m_pRight);
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);
    
    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);
    PrintTree(pNode8);

    TreeMirror(pNode8);
    
    PrintTree(pNode8);
    return 0;
}
