//
//  main.cpp
//  TreeContainTree
//
//  Created by LeeWong on 2018/3/19.
//  Copyright © 2018年 LeeWong. All rights reserved.
//

/*
 输入两颗二叉树 A B 判断B是不是A的子结构 二叉树节点定义如下
 struct BinaryTreeNode {
 double m_dbValue;
 BinaryTreeNode *m_pLeft;
 BinaryTreeNode *m_pRight;
 };
 
        8                   8
    8      7            9       2
 9      2
    4       7
 **/

#include <iostream>

struct BinaryTreeNode {
    double m_dbValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};


//判断两个浮点数是否相同
// 计算机表示小数(double float)是有误差的 因此不可以直接使用==号判断是否相等 如果两个小数的差的绝对值很小比如小于
// 0.0000001 就可以认为他相等
bool Equal(double value1, double value2) {
    if (value1 - value2 > -0.0000001 && value1 - value2 < 0.0000001) {
        return true;
    } else {
        return false;
    }
}

// 判断tree1是否包含tree2
bool DoesTree1HaveTree2(BinaryTreeNode *pRoot1,BinaryTreeNode *pRoot2) {
    
    // tree2是空 那么肯定包含
    if (pRoot2 == nullptr) {
        return true;
    }
    //tree1 是空 那么肯定不包含
    if (pRoot1 == nullptr) {
        return false;
    }
    
    // 如果跟节点的值不相同 那么这一层来说肯定是不会包含的
    if (!Equal(pRoot1->m_dbValue, pRoot2->m_dbValue)) {
        return false;
    }
    
    return DoesTree1HaveTree2(pRoot1->m_pLeft, pRoot2->m_pLeft) &&
    DoesTree1HaveTree2(pRoot1->m_pRight, pRoot2->m_pRight);
}


bool HasSubTree(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2) {
    
    bool result = false;
    
    if (pRoot1 != nullptr && pRoot2 != nullptr) {
        
        if (Equal(pRoot1->m_dbValue, pRoot2->m_dbValue)) {
            result = DoesTree1HaveTree2(pRoot1, pRoot2);
        }
        
        //如果根节点的值不相同
        // 分别判断左右子树中是否可能包含pRoot2这个子树
        if (!result) {
            HasSubTree(pRoot1->m_pLeft, pRoot2);
        }
        
        if (!result) {
            HasSubTree(pRoot1->m_pRight, pRoot2);
        }
        
    }
    
    return result;
}


// ====================辅助测试代码====================
BinaryTreeNode* CreateBinaryTreeNode(double dbValue)
{
    BinaryTreeNode* pNode = new BinaryTreeNode();
    pNode->m_dbValue = dbValue;
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

void DestroyTree(BinaryTreeNode* pRoot)
{
    if(pRoot != nullptr)
    {
        BinaryTreeNode* pLeft = pRoot->m_pLeft;
        BinaryTreeNode* pRight = pRoot->m_pRight;
        
        delete pRoot;
        pRoot = nullptr;
        
        DestroyTree(pLeft);
        DestroyTree(pRight);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8.0);
    BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8.0);
    BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(7.0);
    BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(6.0);
    BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(2.0);
    BinaryTreeNode* pNodeA6 = CreateBinaryTreeNode(4.0);
    BinaryTreeNode* pNodeA7 = CreateBinaryTreeNode(7.0);
    
    ConnectTreeNodes(pNodeA1, pNodeA2, pNodeA3);
    ConnectTreeNodes(pNodeA2, pNodeA4, pNodeA5);
    ConnectTreeNodes(pNodeA5, pNodeA6, pNodeA7);
    
    BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8.0);
    BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9.0);
    BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(2.0);
    
    ConnectTreeNodes(pNodeB1, pNodeB2, pNodeB3);
    
    if (HasSubTree(pNodeA1, pNodeB1)) {
        printf("pNodeA1包含pNodeB1\n");
    } else {
        printf("pNodeA1不包含pNodeB1\n");
    }
    
    DestroyTree(pNodeA1);
    DestroyTree(pNodeB1);
    return 0;
}
