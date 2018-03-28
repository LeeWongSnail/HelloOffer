//
//  main.cpp
//  SerializeBinaryTree
//
//  Created by LeeWong on 2018/3/28.
//  Copyright © 2018年 LeeWong. All rights reserved.
//

// 请实现两个函数 分别用来序列化和反序列化二叉树

#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;

struct BinaryTree {
    int m_nValue;
    BinaryTree *m_pLeft;
    BinaryTree *m_pRight;
};

// 序列化二叉树
void SerializeBinaryTree(BinaryTree *pRoot,ostream &stream) {
    if (pRoot == nullptr) {
        stream << "$,";
        return;
    }
    
    stream << pRoot->m_nValue<<',';
    SerializeBinaryTree(pRoot->m_pLeft, stream);
    SerializeBinaryTree(pRoot->m_pRight, stream);
}

// 反序列化这个二叉树
bool ReadStream(istream& stream, int* number)
{
    if(stream.eof())
        return false;
    
    char buffer[32];
    buffer[0] = '\0';
    
    char ch;
    stream >> ch;
    int i = 0;
    while(!stream.eof() && ch != ',')
    {
        buffer[i++] = ch;
        stream >> ch;
    }
    
    bool isNumeric = false;
    if(i > 0 && buffer[0] != '$')
    {
        *number = atoi(buffer);
        isNumeric = true;
    }
    
    return isNumeric;
}
void DeserializeBinaryTree(BinaryTree **pRoot,istream &stream) {
    int number;
    //每读出来一个字符判断这个是数字还是$字符
    if (ReadStream(stream,&number)) {
        *pRoot = new BinaryTree();
        (*pRoot)->m_nValue = number;
        (*pRoot)->m_pLeft = nullptr;
        (*pRoot)->m_pRight = nullptr;
        DeserializeBinaryTree(&((*pRoot)->m_pLeft), stream);
        DeserializeBinaryTree(&((*pRoot)->m_pRight), stream);
    }
    
    
}

BinaryTree* CreateBinaryTreeNode(int value)
{
    BinaryTree* pNode = new BinaryTree();
    pNode->m_nValue = value;
    pNode->m_pLeft = nullptr;
    pNode->m_pRight = nullptr;
    
    return pNode;
}

void ConnectTreeNodes(BinaryTree* pParent, BinaryTree* pLeft, BinaryTree* pRight)
{
    if(pParent != nullptr)
    {
        pParent->m_pLeft = pLeft;
        pParent->m_pRight = pRight;
    }
}

void PrintTreeNode(const BinaryTree* pNode)
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

void PrintTree(const BinaryTree* pRoot)
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

void DestroyTree(BinaryTree* pRoot)
{
    if(pRoot != nullptr)
    {
        BinaryTree* pLeft = pRoot->m_pLeft;
        BinaryTree* pRight = pRoot->m_pRight;
        
        delete pRoot;
        pRoot = nullptr;
        
        DestroyTree(pLeft);
        DestroyTree(pRight);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    BinaryTree* pNode8 = CreateBinaryTreeNode(8);
    BinaryTree* pNode6 = CreateBinaryTreeNode(6);
    BinaryTree* pNode10 = CreateBinaryTreeNode(10);
    BinaryTree* pNode5 = CreateBinaryTreeNode(5);
    BinaryTree* pNode7 = CreateBinaryTreeNode(7);
    BinaryTree* pNode9 = CreateBinaryTreeNode(9);
    BinaryTree* pNode11 = CreateBinaryTreeNode(11);
    
    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);
    
    char* fileName = "test.txt";
    ofstream fileOut;
    fileOut.open(fileName);
    SerializeBinaryTree(pNode8, fileOut);
     fileOut.close();
    
    // print the serialized file
    ifstream fileIn1;
    char ch;
    fileIn1.open(fileName);
    while(!fileIn1.eof())
    {
        fileIn1 >> ch;
        cout << ch;
    }
    fileIn1.close();
    cout << endl;
    
    
    ifstream fileIn2;
    fileIn2.open(fileName);
    BinaryTree* pNewRoot = nullptr;
    DeserializeBinaryTree(&pNewRoot, fileIn2);
    fileIn2.close();
    
    PrintTree(pNewRoot);
    
//    if(isSameTree(pNode8, pNewRoot))
//        printf("The deserialized tree is same as the oritinal tree.\n\n");
//    else
//        printf("The deserialized tree is NOT same as the oritinal tree.\n\n");
    DestroyTree(pNode8);
    return 0;
}
