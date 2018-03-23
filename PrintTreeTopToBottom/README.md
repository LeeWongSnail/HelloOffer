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

本文可以采用递归的思路 从根节点开始：
> 先打印根节点 然后将他的左子树和右子树分别作为根节点进行递归
> 在递归的方法中 先打印这两个节点 然后 如果两个节点子节点都存在 那么继续以子节点作为根节点进行递归

## 图示

题目简单 无需图示

## 代码实现

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


