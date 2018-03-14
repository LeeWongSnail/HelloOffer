## 题目

在O(1)的时间内删除链表的节点
给定单项链表的头指针和一个节点指针 定义一个函数在O(1)时间内删除该节点。链表节点与函数定义如下

```
 struct ListNode
 {
 int       m_nValue;
 ListNode* m_pNext;
 };
```

## 思路

### 思路一

我们可以从链表的首节点依次向后遍历,遍历到该节点之后 将该节点的next指针 指向这个要删除节点的next节点,从而实现删除这个节点的功能

这种方法完全没有利用到给我们提供要删除节点的这个参数

### 思路二

因为我们已经有了要删除的节点信息，我们可以将要删除节点的下一个节点的值 赋值给要删除的节点，然后将要删除的节点指向 要删除节点的下一个节点的下一个节点

当然这里也要考虑 如果要删除的节点如果不在这个链表中 我们改如何处理 如何给用户对应的提示！

## 图示

![](http://og0h689k8.bkt.clouddn.com/18-3-14/68390050.jpg)

## 代码实现

```c

//这种方法还包含一个问题是 如果链表中不存在这个节点 我们可能需要给用户一个反馈
//告知调用者 没有这么一个节点
void deleteNodeInList(ListNode **pListHead,ListNode *pToBeDeleted) {
    if (!pListHead || !pToBeDeleted) {
        return;
    }
    
    //要删除的节点如果不是尾节点
    if (pToBeDeleted->m_pNext != nullptr) {
        ListNode *node = pToBeDeleted->m_pNext;
        pToBeDeleted->m_nValue = node->m_nValue;
        pToBeDeleted->m_pNext = node->m_pNext;
        
        delete node;
        node = nullptr;
    } else if (*pListHead == pToBeDeleted) {
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
        *pListHead = nullptr;
    } else {
        ListNode *pNode = *pListHead;
        while (pNode->m_pNext != pToBeDeleted) {
            pNode = pNode->m_pNext;
        }
        
        pNode->m_pNext = nullptr;
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }
}
```




