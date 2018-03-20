//
//  main.cpp
//  SymmetricalTree
//
//  Created by LeeWong on 2018/3/19.
//  Copyright © 2018年 LeeWong. All rights reserved.
//

/*
 题目：请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和
 它的镜像一样，那么它是对称的
 **/

#include <iostream>

struct BinaryTreeNode {
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};

bool IsSymmetrical(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2) {
    //如果都是null 有可能最终的叶子节点 是对称的
    if (pRoot1 == nullptr && pRoot2 == nullptr) {
        return true;
    }
    //如果其中有一个为null那么肯定不是
    if (pRoot2 == nullptr || pRoot1 == nullptr) {
        return false;
    }
    //如果值不相等那么 肯定不是
    if (pRoot1->m_nValue != pRoot2->m_nValue) {
        return false;
    }
    
    //一次递归要求左子树的左边跟右子树的右边相等  左子树的右边 和右子树的左边相等
    return IsSymmetrical(pRoot1->m_pLeft, pRoot2->m_pRight) && IsSymmetrical(pRoot1->m_pRight, pRoot2->m_pLeft);
}

bool IsSymmetricalTree(BinaryTreeNode *pRoot) {
    if (pRoot == nullptr) {
        return false;
    }

    //判断左子树和右子树是否相同
    if (IsSymmetrical(pRoot->m_pLeft, pRoot->m_pRight)) {
        return true;
    }
    return false;
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
    BinaryTreeNode* pNode61 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode62 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode51 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode71 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode72 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode52 = CreateBinaryTreeNode(5);
    
    ConnectTreeNodes(pNode8, pNode61, pNode62);
    ConnectTreeNodes(pNode61, pNode51, pNode71);
    ConnectTreeNodes(pNode62, pNode72, pNode52);
    
    if (IsSymmetricalTree(pNode8)) {
        printf("这是一个堆成的树\n");
    }else {
        printf("这个树不是堆成的\n");
    }
    return 0;
}
