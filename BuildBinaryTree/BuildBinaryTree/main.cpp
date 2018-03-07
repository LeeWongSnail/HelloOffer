//
//  main.cpp
//  BuildBinaryTree
//
//  Created by LeeWong on 2018/3/7.
//  Copyright © 2018年 LeeWong. All rights reserved.
//

#include <iostream>
#include <exception>
#include <cstdio>

/*
 题目：
 输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树 假设输入的前序遍历和中序遍历的结果中都不含有重复的数字
 例如 输入的前序遍历序列{1，2，4，7，3，5，6，8}  和中序遍历序列{4,7,2,1,5,3,8,6}
 
 */

struct BinaryTreeNode {
    int m_nValue;
    BinaryTreeNode * m_pLeft;
    BinaryTreeNode * m_right;
};


BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder,int* startInorder, int* endInorder)
{
    // 前序遍历序列的第一个数字是根结点的值
    int rootValue = startPreorder[0];
    BinaryTreeNode* root = new BinaryTreeNode();
    root->m_nValue = rootValue;
    root->m_pLeft = root->m_right = nullptr;
    
    if(startPreorder == endPreorder)
    {
        if(startInorder == endInorder && *startPreorder == *startInorder)
            return root;
        else
//            throw std::exception("Invalid input.");
            printf("---");
    }
    
    // 在中序遍历中找到根结点的值
    int* rootInorder = startInorder;
    while(rootInorder <= endInorder && *rootInorder != rootValue)
        ++ rootInorder;
    
    if(rootInorder == endInorder && *rootInorder != rootValue){
//        throw std::exception("Invalid input.");
    }
    
    int leftLength = rootInorder - startInorder;
    int* leftPreorderEnd = startPreorder + leftLength;
    if(leftLength > 0)
    {
        // 构建左子树
        root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd,
                                      startInorder, rootInorder - 1);
    }
    if(leftLength < endPreorder - startPreorder)
    {
        // 构建右子树
        root->m_right = ConstructCore(leftPreorderEnd + 1, endPreorder,
                                       rootInorder + 1, endInorder);
    }
    
    return root;
}

/*
 preorder 前序排列的数组
 inorder 中序排列的组
 length 宽度
 **/

BinaryTreeNode * Construct(int *preorder,int *inorder,int length)
{
    if (preorder == nullptr || inorder == nullptr || length <= 0) {
        return nullptr;
    }
    
    return ConstructCore(preorder,preorder+length-1,inorder,inorder+length-1);
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
        
        if(pNode->m_right != nullptr)
            printf("value of its right child is: %d.\n", pNode->m_right->m_nValue);
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
        
        if(pRoot->m_right != nullptr)
            PrintTree(pRoot->m_right);
    }
}



int main(int argc, const char * argv[]) {
    // insert code here...
    const int length = 8;
    int preorder[length] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[length] = {4, 7, 2, 1, 5, 3, 8, 6};
    BinaryTreeNode *root = Construct(preorder, inorder, length);
    PrintTree(root);
    return 0;
}
