## 题目

```
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
```


## 思路

判断一棵树是否是另一棵树的子树 需要具备下面两个条件

> 1、根节点的值相同
> 2、除根节点之外的左子树相同 
> 3、除根节点之外的右子树相同

因此这个题目 也非常适合使用递归的思路去解决

## 代码实现

### 浮点数相等的判断方法

```c++
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
```

### 判断两棵树是否有包含关系

```c++

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
```

```c++

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
```



