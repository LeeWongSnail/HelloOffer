## 题目

```
面试题8：二叉树的下一个结点
题目：给定一棵二叉树和其中的一个结点，如何找出中序遍历顺序的下一个结点？
树中的结点除了有两个分别指向左右子结点的指针以外，还有一个指向父结点的指针。
```

## 思路

> 如果这个节点有右子树 那么下一个节点是右子树中最左的子节点
> 如果这个节点是父节点的左子树 那么下一个节点就是他的父节点
> 如果这个节点是父节点的右子树，那么需要进一步判断 他的父节点是祖先节点的左子树还是右子树
  * 如果是左子树 那么下一个节点就是他的祖先节点
  * 如果是右子树 那么重复这一步 直到找到其作为祖先节点的左子树位置 否则就是最后一个节点
## 图解

查看思路即可 图不太好描述

## 代码实现

```c

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
```

注意：`这里给Node添加了一个super的属性，在创建这个二叉树的时候需要先create然后在connect`
  
  
  



