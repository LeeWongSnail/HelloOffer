## 题目

```
 输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树 假设输入的前序遍历和中序遍历的结果中都不含有重复的数字
 例如 输入的前序遍历序列{1，2，4，7，3，5，6，8}  和中序遍历序列{4,7,2,1,5,3,8,6}
```

## 思路

> 在二叉树的前序遍历序列中，第一个数字总是树的根节点的值，而在中序遍历中根节点位于序列的中间同时将左子树的值和右子树的值分隔
> 依据上面的 我们可以递归的拆分前序和中序遍历序列
> 如果最后 前序的第一个值(根节点)位于中序序列的中间位置 那么 可以平分左右子树 如果位于第一个位置那么后面的序列均为右子树 如果位于最后一个 那么前面的序列均为左子树


## 图示

![1](http://og0h689k8.bkt.clouddn.com/18-3-7/93992808.jpg)
![2](http://og0h689k8.bkt.clouddn.com/18-3-7/4003669.jpg)


## 代码实现

```C

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
```

```c
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
```

