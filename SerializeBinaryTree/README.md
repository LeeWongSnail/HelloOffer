## 题目

 请实现两个函数 分别用来序列化和反序列化二叉树
 
## 思路

### 序列化
按照先序遍历的顺序依次将树中的节点的值添加到一个字符串中,如果碰到二叉树的左子树或者右子树的指针为nullprt这就说明没有对应的子树那么僵一个$字符添加到字符串中，同时字符串中的每一个字符都用,隔开。
这样就组成该二叉树的一个序列化结果

### 反序列化
二叉树的序列化结果是一个字符串,字符串中的内容是树的先序遍历结果。字符之间用逗号隔开，nullprt用$表示

这个序列化的字符串的第一个字符肯定是根节点,那么我们可以一次读取这个字符串中的每个字符
如果这个字符是$那表明节点对应的这个字数是空
如果是对应的字符那么表示对应的节点的值
如果连续读出了两个$那么表明这个节点是叶子节点

## 图示
![](http://og0h689k8.bkt.clouddn.com/18-3-28/16920826.jpg)

## 代码实现

### 序列化

```c++
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
```

### 反序列化：

```c++
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
```


