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
#include <queue>

struct BinaryTreeNode {
    int m_pValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};


void PrintTreeNode(BinaryTreeNode *pLeft, BinaryTreeNode *pRight) {
    //先打印左子树
    if (pLeft != nullptr) {
        printf("%d     ",pLeft->m_pValue);
    }
    //再打印右子树
    if (pRight != nullptr) {
        printf("%d",pRight->m_pValue);
    }
    
 
    // 如果左子树不为空那么 递归打印左子树
    if (pLeft != nullptr) {
        
        PrintTreeNode(pLeft->m_pLeft, pLeft->m_pRight);
    }
    
    // 如果右子树不为空 那么递归打印右子树
    if (pRight != nullptr) {
        PrintTreeNode(pRight->m_pLeft, pRight->m_pRight);
    }
}

void PrintTree(BinaryTreeNode *pRoot) {
    if (pRoot == nullptr) {
        return;
    }
    // 先打印根节点
    printf("%d\n",pRoot->m_pValue);
    //打印根节点的左右两个子树
    PrintTreeNode(pRoot->m_pLeft, pRoot->m_pRight);
}

//方法二:
// 利用队列的特性 从根节点开始 打印根节点时 将根节点的左右子树入栈 每次打印一个节点的时候 如果这个节点有左右子树
// 那么就将左右子树加入到队列的尾部

void printFromTopToBottom(BinaryTreeNode *pRoot) {
    if (pRoot == nullptr) {
        return;
    }
    
    //这是存放数据的队列
    std::deque<BinaryTreeNode *> dequeueTreeNode;
    
    dequeueTreeNode.push_back(pRoot);
    
    //这是一个出队列的过程 如果队列中有元素存在就出队列
    while (dequeueTreeNode.size()) {
        //第一个元素出队列
        BinaryTreeNode *pNode = dequeueTreeNode.front();
        dequeueTreeNode.pop_front();
        //打印当前出队列的元素
        printf("%d",pNode->m_pValue);
        //如果这个元素有左子树 那么左子树的元素入栈
        if (pNode->m_pLeft) {
            dequeueTreeNode.push_back(pNode->m_pLeft);
        }
        //如果这个节点有右子树 那么这个节点的右子树入栈
        if (pNode->m_pRight) {
            dequeueTreeNode.push_back(pNode->m_pRight);
        }
    }
    
}

// 方法三 如果要求 将每一层打印到一行中 那么我们在解决这个问题的时候需要加上两个参数

void Print(BinaryTreeNode *pRoot) {
    if (pRoot == nullptr) {
        return;
    }
    
    //创建一个队列用来保存数据
    std::queue<BinaryTreeNode *> nodes;
    
    nodes.push(pRoot);
    
    int nextLevel = 0;  // 每一层需要被打印的节点个数
    int toBePrinted = 1;    // 队列中将要被打印的节点数
    while (!nodes.empty()) {
        
        BinaryTreeNode *pNode = nodes.front();
        printf("%d",pNode->m_pValue);
        
        if (pNode->m_pRight) {
            nodes.push(pNode->m_pRight);
            nextLevel++;
        }
        
        if (pNode->m_pLeft) {
            nodes.push(pNode->m_pLeft);
            nextLevel ++;
        }
        
        nodes.pop();
        --toBePrinted;
        //如果这一层 已经打印完了 可以接着打印下一层
        if (toBePrinted == 0) {
            printf("\n");
            //nextLevel 是记录 每一层toBePrinted的元素的个数
            toBePrinted = nextLevel;
            nextLevel = 0;
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
    
    Print(pNode10);
    return 0;
}
