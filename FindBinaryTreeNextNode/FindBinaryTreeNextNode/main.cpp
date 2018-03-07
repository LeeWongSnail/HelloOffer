//
//  main.cpp
//  FindBinaryTreeNextNode
//
//  Created by LeeWong on 2018/3/7.
//  Copyright © 2018年 LeeWong. All rights reserved.
//

#include <iostream>
#include <exception>
#include <cstdio>

struct BinaryTreeNode {
    int m_nValue;
    BinaryTreeNode * m_pLeft;
    BinaryTreeNode * m_right;
    BinaryTreeNode * m_super;
};


// ==================== 辅助代码用来构建二叉树 ====================
BinaryTreeNode* CreateBinaryTreeNode(int value)
{
    BinaryTreeNode* pNode = new BinaryTreeNode();
    pNode->m_nValue = value;
    pNode->m_pLeft = nullptr;
    pNode->m_right = nullptr;
    pNode->m_super = nullptr;
    
    return pNode;
}

void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
    if(pParent != nullptr)
    {
        pParent->m_pLeft = pLeft;
        pParent->m_right = pRight;
        
        if(pLeft != nullptr)
            pLeft->m_super = pParent;
        if(pRight != nullptr)
            pRight->m_super = pParent;
    }
}



void PrintTreeNode(BinaryTreeNode* pNode)
{
    if(pNode != nullptr)
    {
        printf("value of this node is: %d\n", pNode->m_nValue);
        
        if(pNode->m_pLeft != nullptr)
            printf("value of its left child is: %d.\n", pNode->m_pLeft->m_nValue);
        else
            printf("left child is null.\n");
        
        if(pNode->m_right != nullptr)
            printf("value of its right child is: %d.\n", pNode->m_right->m_nValue);
        else
            printf("right child is null.\n");
    }
    else
    {
        printf("this node is null.\n");
    }
    
    printf("\n");
}

BinaryTreeNode * GetNext(BinaryTreeNode *pNode) {
    
    if (pNode == nullptr) {
        return nullptr;
    }
    
    //判断
    BinaryTreeNode *pNext = nullptr;
    if (pNode->m_right != nullptr) {
        //如果这个节点有右子树 那么找到这个右子树中最靠左的
        BinaryTreeNode *node = pNode->m_right;
        while (node->m_pLeft != nullptr) {
            pNext = node->m_pLeft;
        }
    } else if (pNode->m_super->m_pLeft == pNode) {
        //是父节点的左子树
        pNext = pNode->m_super;
    } else if (pNode->m_super->m_right == pNode) {
        //是父节点的右子树
        pNext = pNode->m_super;
        while (pNext->m_super != nullptr) {
            if (pNext->m_super->m_pLeft == pNext) {
                pNext = pNext->m_super;
                break;
            } else if (pNext->m_super->m_right == pNext) {
                pNext = pNext->m_super;
            }
        }
    }
    
    
    
    return pNext;
}

//            8
//        6      10
//       5 7    9  11
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
    
    BinaryTreeNode *node = GetNext(pNode9);
    printf("%tu",node->m_nValue);
    return 0;
}
