## 题目

```
 定义一个函数，输入一个链表的头结点 反转该链表并输出翻转后链表的头结点 链表的节点定义如下下
 
 struct ListNode
 {
 int       m_nValue;
 ListNode* m_pNext;
 };
```


## 图示+思路
![](http://og0h689k8.bkt.clouddn.com/18-3-17/80972724.jpg)


## 代码实现

```c++

ListNode *ReverseListNode(ListNode *pHead) {
    
    ListNode *pReversedHead = nullptr;
    ListNode *pNode = pHead;
    ListNode *pPrev = nullptr;
    while (pNode != nullptr) {
        ListNode *next = pNode->m_pNext;
        
        //记录最后一个节点
        if (next == nullptr) {
            pReversedHead = pNode;
        }
        
        //主要的循环
        //第一次走的时候会把之前头结点的next置为null
        pNode->m_pNext = pPrev;
        //pPrev指向第一个节点
        pPrev = pNode;
        //pNode指向自己的下一个节点
        pNode = next;
    }
    return pReversedHead;
}
```

