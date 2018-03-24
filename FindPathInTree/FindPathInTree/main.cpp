//
//  main.cpp
//  FindPathInTree
//
//  Created by LeeWong on 2018/3/24.
//  Copyright © 2018年 LeeWong. All rights reserved.
//

/*
 二叉树中和为某一值的路径
 输入一颗二叉树和一个整数，打印出二叉树中节点值的和为输入证书的所有路径。从树的根节点开始往下一直到叶节点所经过的节点
 形成一条路径。
 **/

#include <iostream>
#include <vector>

struct BinaryTreeNode {
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};


// 思路 我们这里可以利用一个数组来保存我们经过的所有节点
// 前提：二叉树的路径肯定是从根节点开始的 而 二叉树只有先序遍历才将根节点放在第一个位置 因此我们可以利用先序遍历将 所有的元素放到一个序列中 然后我们通过遍历这个序列中的元素 去确定路径
// 每次想数组中添加一个元素我们就判断是否数组中每一项的和为22 如果是 那么将最后一个元素弹出数组 然后在让其他元素加入数组

void FindPath(BinaryTreeNode *pRoot,int expectedSum,std::vector<int> &path,int currentSum)
{
    // 首先将根节点如队列 同时当前路径上的数字之和+根节点的值
    currentSum += pRoot->m_nValue;
    path.push_back(pRoot->m_nValue);
    
    //是否是叶子节点
    bool isLeaf = pRoot->m_pLeft == nullptr && pRoot->m_pRight == nullptr;
    
    if (currentSum == expectedSum && isLeaf) {
        //如果是叶子节点 且 路径中的数的和恰好是我们要的
        printf("Find A Path :");
        std::vector<int> :: iterator iter = path.begin();
        for (; iter != path.end(); ++iter) {
            printf("%d\t",*iter);
        }
        printf("\n");
    }
    
    //如果不是叶子节点
    if (pRoot->m_pLeft != nullptr) {
        FindPath(pRoot->m_pLeft, expectedSum, path, currentSum);
    }
    
    if (pRoot->m_pRight != nullptr) {
        FindPath(pRoot->m_pRight, expectedSum, path, currentSum);
    }
    
    //将路径中的一个值移除
    path.pop_back();
}


//expectedSum 数字之和
void FindPath(BinaryTreeNode *pRoot, int expectedSum) {
    
    if (pRoot == nullptr) {
        return;
    }
    
    std::vector<int> path;
    int currentSum = 0;
    
    FindPath(pRoot, expectedSum, path, currentSum);
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
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    
    ConnectTreeNodes(pNode10, pNode5, pNode12);
    ConnectTreeNodes(pNode5, pNode4, pNode7);
    
    printf("Two paths should be found in Test1.\n");
    FindPath(pNode10, 22);
    return 0;
}
