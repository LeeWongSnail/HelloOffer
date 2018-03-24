## 题目

```
 二叉树中和为某一值的路径
 输入一颗二叉树和一个整数，打印出二叉树中节点值的和为输入证书的所有路径。从树的根节点开始往下一直到叶节点所经过的节点
 形成一条路径。
```

## 思路

我们这里可以利用一个数组来保存我们经过的所有节点
`注意`：二叉树的路径肯定是从根节点开始的 而 二叉树只有先序遍历才将根节点放在第一个位置 因此我们可以利用先序遍历将 所有的元素放到一个序列中 然后我们通过遍历这个序列中的元素 去确定路径

> 当用前序遍的方式访问到某一节点时，我们把该节点添加到路径上，并累加该节值。
> 如果该节点为叶节点，并且路径中节点值的和刚好等于输入的整数则当前路径符合要求，我们把它打印出来。
> 如果当前节点不是叶节点继续访问它的子节点。
> 当前节点访问结束后，递归函数将自动回到它它的父节点。

因此，我们在函数退出之前要在路径上删除当前节点并减去当前点的值，以确保返回父节点时路径刚好是从根节点到父节点。我们不走出保存路径的数据结构实际上是一个栈，因为路径要与递归调用状态一致，而递归调用的本质就是一个压栈和出栈的过程。

## 图示
![](http://og0h689k8.bkt.clouddn.com/18-3-24/82362758.jpg)

## 代码实现

```c++

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
```



