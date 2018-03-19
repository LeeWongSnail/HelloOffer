## 题目

请完成一个函数 输入一颗二叉树 该函数输出他的镜像。二叉树节点定义如下

```
struct BinaryTreeNode {
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};
```

## 思路

这很明显又是一个递归的题目,可以简单的只考虑一个根节点和两个左右子树,根节点值不变 交换左右叶子节点

如果左右叶子节点也有子节点 那么将左右叶子节点分别当做根节点 依次去交换他们的叶子节点

依次递归 就可以将这棵树 做成一个镜像

## 图示
![](http://og0h689k8.bkt.clouddn.com/18-3-19/31812723.jpg)

## 代码实现

```c++
// 使用递归的思路 将 二叉树镜像 变为么一个 根节点的左右子树的节点交换
void TreeMirror(BinaryTreeNode *pRoot) {
    if (pRoot == nullptr) {
        return;
    }
    
    if (pRoot->m_pLeft == nullptr && pRoot->m_pRight == nullptr) {
        return;
    }
    
    //使用递归的方法交换
    BinaryTreeNode *temp = pRoot->m_pLeft;
    pRoot->m_pLeft = pRoot->m_pRight;
    pRoot->m_pRight = temp;
    
    if (pRoot->m_pLeft) {
        TreeMirror(pRoot->m_pLeft);
    }
    if (pRoot->m_pRight) {
        TreeMirror(pRoot->m_pRight);
    }
    
}
```

