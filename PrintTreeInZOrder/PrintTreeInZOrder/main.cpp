//
//  main.cpp
//  PrintTreeInZOrder
//
//  Created by LeeWong on 2018/3/23.
//  Copyright © 2018年 LeeWong. All rights reserved.
//

/*
 题目：
 请实现一个函数按照之子形顺序打印二叉树，即第一行按照从左到右的顺序打印,第二层按照从右到左的顺序打印
 第三行 按照从左到右的顺序打印 其他行以此类推。
 **/

#include <iostream>
#include <stack>

struct BinaryTreeNode {
    int m_pValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};


//如果要按之字形打印 也就是说 奇数行从右往左 偶数行从左往右

void PrintTree(BinaryTreeNode *pRoot) {
    if (pRoot == nullptr) {
        return;
    }
    
    //声明了一个栈的数组 数组中包含两个元素
    std::stack<BinaryTreeNode *> level[2];
    
    int current =0;
    int next = 1;
    
    level[current].push(pRoot);
    
    while (!level[0].empty() || !level[1].empty()) {
        //当两个栈中的内容均不为空的时候
        
        //获取当前栈的栈顶位置元素
        BinaryTreeNode *pNode = level[current].top();
        //将该元素出栈
        level[current].pop();
        
        printf("%d",pNode->m_pValue);
        
        if (current == 0) {
            if (pNode->m_pLeft != nullptr) {
                level[next].push(pNode->m_pLeft);
            }
            if (pNode->m_pRight != nullptr) {
                level[next].push(pNode->m_pRight);
            }
        } else {
            if (pNode->m_pRight != nullptr) {
                level[next].push(pNode->m_pRight);
            }
            if (pNode->m_pLeft != nullptr) {
                level[next].push(pNode->m_pLeft);
            }
            
            
        }
        
        //如果当前的栈 为空 那么要切换去遍历另外一个栈
        if (level[current].empty()) {
            printf("\n");
            //这个方法可以使current和next在0和1之间切换
            current = 1-current;
            next = 1-next;
        }
    }
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
