## 将链表的数据逆置

### 题目：

```
 输入一个链表的头结点，从头到尾反过来打印每个结点的值
```

### 思路

> 数组的就地逆置,首先可以想到的就是利用栈后进先出的功能实现 遍历链表 依次入栈 在将栈内的值依次出栈
> 也可以利用递归的思路 循环调用最后输出


### 代码实现

#### 思路一

```c
/*
 遍历一遍链表 将链表的所有元素一次入栈 根据栈的 后进先出的特性 在依次输出栈内的元素
 **/
void ReverseNodeList(ListNode *pHead) {
    //声明一个栈
    std::stack <ListNode *> nodes;
    
    ListNode *pNode = pHead;
    while (pNode->m_pNext != nullptr) {
        nodes.push(pNode);
        pNode = pNode->m_pNext;
    }
    
    //先进后出 出站
    while (!nodes.empty()) {
        pNode = nodes.top();
        printf("%d\t",pNode->m_nKey);
        nodes.pop();
    }
    
}
```

#### 思路二

```c
/*利用递归的思路来解决
 问题：当链表非常长的时候 就会导致函数的调用层级很深从而有可能导致函数调用栈溢出
 */
void ReverseNodeListElem(ListNode *pHead) {
    
    if (pHead->m_pNext != nullptr) {
        ReverseNodeList(pHead->m_pNext);
    }
    printf("%d\t",pHead->m_nKey);
}
```

