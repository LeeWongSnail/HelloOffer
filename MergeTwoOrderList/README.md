## 题目

```
 输入liangge 递增排序的链表,合并这两个链表并使新的链表中的节点仍然是递增有序的。
 例如 输入图3.1.1中的 链表1和链表2 则合并之后的圣墟链表如链表3所示
1 3 5 7
2 4 6 8
 
 1 2 3 4 5 6 7 8
 
```

```c++
 struct ListNode{
 int m_nValue;
 ListNode *m_pNext;
 };
 
```

## 思路 + 图示

### 递归的方法

可以吧这个问题分解成小的问题 

假如：pHead1是最小的 那么 将pMergeHead 指向pHead1 pMergeHead的下一个元素 将指向剩余的元素组成的两个队列的 pMergeHead元素

每次找到最小的那个元素拼接到pMergeHead中 就可以解决这个问题

### 遍历的方法

![](http://og0h689k8.bkt.clouddn.com/18-3-19/56719035.jpg)


## 代码实现

### 递归思想

```c++
ListNode * MergeTwoList(ListNode *pHead1,ListNode *pHead2) {
    
    if (pHead1 == nullptr) {
        return pHead2;
    } else if (pHead2 == nullptr) {
        return pHead1;
    }
    
    ListNode *pMerageHead = nullptr;
    if (pHead1->m_nValue < pHead2->m_nValue) {
        pMerageHead = pHead1;
        pMerageHead->m_pNext = MergeTwoList(pHead1->m_pNext, pHead2);
    } else {
        pMerageHead = pHead2;
        pMerageHead->m_pNext = MergeTwoList(pHead1, pHead2->m_pNext);
    }
    return pMerageHead;
}
```

### 遍历方法

```c++

ListNode * MergeTwoList2(ListNode *pHead1,ListNode *pHead2) {
    
    if (pHead1 == nullptr) {
        return pHead2;
    } else if (pHead2 == nullptr) {
        return pHead1;
    }
    
    ListNode *pMerageHead = nullptr;
    ListNode *pNext = nullptr;
    ListNode *pPre = nullptr;
    while (pHead1!= nullptr && pHead2 != nullptr) {
        
        if (pHead1->m_nValue < pHead2->m_nValue) {
            if (pMerageHead == nullptr) {
                pMerageHead = pHead1;
                pHead1= pHead1->m_pNext;
                pNext = pMerageHead;
                pNext->m_pNext = nullptr;
            } else {
                pPre = pNext;
                pNext = pHead1;
                pPre->m_pNext = pNext;
                pHead1 = pHead1->m_pNext;
                pNext ->m_pNext = nullptr;
            }
            
        } else {
            if (pMerageHead == nullptr) {
                pMerageHead = pHead2;
                pHead2= pHead2->m_pNext;
                pNext = pMerageHead;
                pNext->m_pNext = nullptr;
            } else {
                pPre = pNext;
                pNext = pHead2;
                pPre->m_pNext = pNext;
                pHead2 = pHead2->m_pNext;
                pNext ->m_pNext = nullptr;
            }
            
        }
        
    }
    
    if (pHead1 == nullptr) {
        pNext->m_pNext = pHead2;
    }
    
    if (pHead2 == nullptr) {
        pNext->m_pNext = pHead1;
    }
    return pMerageHead;
}
```

