## 题目
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果
如果是则返回true 如果不是则返回false
假设输入的数组的任意两个数字都互不相同
例如： 输入数组{5,7,6,9,11,10,8} 则返回true 因为这个整数序列是图4.9二叉搜索树的后续遍历结果。
如果输入的数组是{7,4,6,5} 则由于没有哪个二叉搜索树的后续遍历结果是这个序列因此返回false
 
``` 
            8
    6               10
 5      7       9       11
 ```

## 思路

首先了解二叉搜索树的特点:

> 这个题目的前提是要知道二叉搜索树的一个特点
> 根节点的值大于左子树的值
> 根节点的值大于右子树的值

这样可以通过下面的思路解决这个问题

> 1、找到根节点 然后通过比较 将前面的length-1个值区分为左子树和右子树(左子树的值均小于根节点右子树的值均大于根节点)
> 2、根据第一步 判断划分出来的右子树的值是否均大于根节点，如果均大于则继续后面的判断否则可以判断这不是一个二叉搜索树的后续遍历
> 3、将序列分成两部分之后 递归调用 1 2两步 进一步判断是否起左子树和右子树也是一个二叉搜索树的后续遍历序列


## 代码实现

```c++
bool VertifySequeueOfBST(int sequence[],int length) {
    
    if (sequence == nullptr || length <=0) {
        return false;
    }
    
    // 后续遍历特点 根节点是序列的最后一个元素
    int root = sequence[length-1];
    
    int i = 0;
    
    //找到左子树
    for (; i < length-1; i++) {
        if (sequence[i] > root) {
            break;
        }
    }
    
    // 前面的i个节点为左子树 剩下的为右子树
    int j = i;
    //右子树肯定要比根节点的值大
    for (; j <length-1; j++) {
        if (sequence[j] <= root) {
            return false;
        }
    }
    
    //判断左子树是否为二叉搜索树
    bool left = true;
    if (i > 0) {
        left = VertifySequeueOfBST(sequence, i);
    }
    //判断右子树是否为二叉搜索树
    bool right = true;
    if (j < length-1) {
        right = VertifySequeueOfBST(sequence, length-j-1);
    }
    
    return left && right;
}
```

