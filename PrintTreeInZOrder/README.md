## 题目

 请实现一个函数按照之子形顺序打印二叉树，即第一行按照从左到右的顺序打印,第二层按照从右到左的顺序打印
 第三行 按照从左到右的顺序打印 其他行以此类推。
 
 ```
             8
    6               10
 5      7       9       11
 ```
 
  则依次打印出8 10 6 5 7 9 11
  
## 思路

可以借助两个栈(stack1 stack2) 保存每一层要打印的节点

> 打印根节点并将根节点的左子树和右子树分别放到stack1中
> 后进先出的形式 现将stack1的第一个元素出栈 观察是否有子节点 如果有 那么根据 奇数行从左到右 偶数行从右到左的顺序将子节点一次入栈
> stack1中的元素 依次出栈完成之后 那么stack2重的元素在依次出栈 并按照相同的规则将stack2中的元素依次出栈 stack1 将用来保存stack2中节点的子节点
> 一直到stack1和stack2中的所有节点都出栈 那么这个数打印完毕

## 图示

题目简单 无需图示

## 代码实现


```c++


//如果要按之字形打印 也就是说 奇数行从右往左 偶数行从左往右

void PrintTree(BinaryTreeNode *pRoot) {
    if (pRoot == nullptr) {
        return;
    }
    
    //声明了一个栈的数组 数组中包含两个元素
    std::stack<BinaryTreeNode *> level[2];
    
    int current =0;
    int next = 1;
    
    level[current].push(pRoot);
    
    while (!level[0].empty() || !level[1].empty()) {
        //当两个栈中的内容均不为空的时候
        
        //获取当前栈的栈顶位置元素
        BinaryTreeNode *pNode = level[current].top();
        //将该元素出栈
        level[current].pop();
        
        printf("%d",pNode->m_pValue);
        
        if (current == 0) {
            if (pNode->m_pLeft != nullptr) {
                level[next].push(pNode->m_pLeft);
            }
            if (pNode->m_pRight != nullptr) {
                level[next].push(pNode->m_pRight);
            }
        } else {
            if (pNode->m_pRight != nullptr) {
                level[next].push(pNode->m_pRight);
            }
            if (pNode->m_pLeft != nullptr) {
                level[next].push(pNode->m_pLeft);
            }
            
            
        }
        
        //如果当前的栈 为空 那么要切换去遍历另外一个栈
        if (level[current].empty()) {
            printf("\n");
            //这个方法可以使current和next在0和1之间切换
            current = 1-current;
            next = 1-next;
        }
    }
}
```



