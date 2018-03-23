## 题目

 不分行从上到下打印二叉树
 从上到下打印出二叉树的每一个节点，同一层的节点按照从左到右的顺序打印
 
 ```
             8
    6               10
 5      7       9       11
 ```
 
  则依次打印出8，6，10，5，7，9，11
  
## 思路

### 思路一 直接打印(这是我最直接会想到的)

本文可以采用递归的思路 从根节点开始：
> 先打印根节点 然后将他的左子树和右子树分别作为根节点进行递归
> 在递归的方法中 先打印这两个节点 然后 如果两个节点子节点都存在 那么继续以子节点作为根节点进行递归

### 思路二 借助队列打印

可以借助队列 不停的出入队列的过程中打印树中的内容

> 将跟节点入队列,然后循环 输出队列中的内容 
> 输出队列中的第一个节点 如果这个节点有左子树或者右子树 将这个节点的左子树和右子树都入队列
> 一直到这个队列中元素全部出队列为止 

## 图示

题目简单 无需图示

## 代码实现

### 思路一

```c++

void PrintTreeNode(BinaryTreeNode *pLeft, BinaryTreeNode *pRight) {
    //先打印左子树
    if (pLeft != nullptr) {
        printf("%d\n",pLeft->m_pValue);
    }
    //再打印右子树
    if (pRight != nullptr) {
        printf("%d\n",pRight->m_pValue);
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
```

```c++

void PrintTree(BinaryTreeNode *pRoot) {
    if (pRoot == nullptr) {
        return;
    }
    // 先打印根节点
    printf("%d\n",pRoot->m_pValue);
    //打印根节点的左右两个子树
    PrintTreeNode(pRoot->m_pLeft, pRoot->m_pRight);
}
```

### 思路二

```c++
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
```


