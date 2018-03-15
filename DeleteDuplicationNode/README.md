## 题目

```
 删除链表中的重复节点
 在一个排序的链表中 如何删除重复的节点
 例如 1 2 3 3 4 4 5 中重复的节点被删除后  1 2 5
```

## 思路

> 从前向后遍历这个链表 从头结点开始比较观察是否与下一个节点的值相同
> 如果相同那么从头结点开始遍历这个链表删掉所有和值头结点相同的节点
> 如果被删掉的是头结点需要注意将之前的pHeader指向被删除之后的下一个节点
> 如果跟下一个节点的值不相同 那么 继续向后遍历 如果 没有找到值相同的给以提示


## 图示

![](http://og0h689k8.bkt.clouddn.com/18-3-15/26052341.jpg)

## 代码实现

```c++
void deleteDuplication(ListNode **pHead) {
    if (pHead == nullptr || *pHead == nullptr) {
        return;
    }
    
    ListNode *pPreNode = nullptr;
    ListNode *pNode = *pHead;
    
    while (pNode != nullptr) {
        
        ListNode *pNext = pNode->m_pNext;
        bool needDelete = false;
        //判断是否可以被删除
        if (pNext != nullptr && pNext->m_nValue == pNode->m_nValue) {
            needDelete = true;
        }
        
        if (!needDelete) {
            //如果不需要被删除
            pPreNode = pNext;
            pNode = pNode->m_pNext;
        } else {
            //如果需要被删除 这里 因为相同的节点可能大于2个 因此这里需要重新遍历一下
            int value = pNode->m_nValue;
            ListNode *pToBeDelete = pNode;
            while (pToBeDelete != nullptr && pToBeDelete->m_nValue == value) {
                //删除这个节点
                pNext = pToBeDelete->m_pNext;
                delete pToBeDelete;
                pToBeDelete = nullptr;
                
                pToBeDelete = pNext;
            }
            
            //以上可以将要删除的节点删除 下面考虑 删除之后
            if (pPreNode == nullptr) {
                //被删除的是链表的首节点
                *pHead = pNext;
            } else {
                pPreNode->m_pNext = pNext;
            }
            
            pNode = pNext;
            
        }
        
        
    }
    
    
}
```


