## 题目

```
 如果一个链表中包含环 如何找出换的入口节点
```

## 思路

### 1、先确认这是一个包含环的链表 并获取到一个环中的节点

> pslow在第一个节点 pfast在第二个节点 pslow一次走一步 pfast一次走两步
> 直到最后相遇 那么可以确定这个链表包含一个环 且相遇的这个节点是环中的节点


### 2、根据环中的节点找到环中节点个数

从已知的环中的节点开始，一次遍历这个链表 知道再次回到这个节点的时候 即可计算出
环中的节点的数目

### 根据环中的节点数m 得到入口节点

> 1、p1指向第一个节点 p2指向 第n个节点
> 2、p1 p2一次向后走 如果p1==p2了 就说明这个节点是入口节点！

```
步骤2 的原因
链表的长度是n 环中的节点数是m 那么入口就在 n-m的地方
p1走了n-m步之后到了环的入口 p2走了n-m步之后到了链表末尾元素的下一个元素也就是环的第一个元素
```

## 图示

![](http://og0h689k8.bkt.clouddn.com/18-3-16/79231678.jpg)

## 代码实现

### 确认链表中有环 并返回环中的一个节点

```c++
//要查找到入口节点 首先确认这是一个有环的链表 然后找到一个在环中的节点
// pslow在第一个节点 pfast在第二个节点 pslow一次走一步 pfast一次走两步
// 直到最后相遇
ListNode *meetNode(ListNode *pHead) {
    
    if (pHead == nullptr) {
        return nullptr;
    }
    
    ListNode *pSlow = pHead->m_pNext;
    //一定要有这种判断
    if (pSlow->m_pNext == nullptr) {
        return nullptr;
    }
    
    ListNode *pFast = pSlow->m_pNext;
    while (pFast != nullptr && pSlow != nullptr) {
        
        if (pFast == pSlow) {
            return pFast;
        }
        
        pSlow = pSlow->m_pNext;
        
        pFast = pFast->m_pNext;
        if (pFast != nullptr) {
            pFast = pFast->m_pNext;
        }
    }
    
    //没有环
    return nullptr;
}
```

### 根据环中节点的个数 获取到环入口节点

```c++

// 在已知这个链表有环的情况下 如何找到这个环的入口
// 1、先获取这个环中节点的数目n
// 2、p1指向第一个节点 p2指向 第n个节点
// 3、p1 p2一次向后走 如果p1==p2了 就说明这个节点是入口节点！
// 步骤3 的原因
// 链表的长度是n 环中的节点数是m 那么入口就在 n-m的地方
// p1走了n-m步之后到了环的入口 p2走了n-m不之后到了链表末尾元素的下一个元素也就是环的第一个元素
ListNode * EntryNodeOfLoop(ListNode *pHead) {
    
    ListNode *meettingNode = meetNode(pHead);
    if (meettingNode == nullptr) {
        //说明 链表中没有环
        return nullptr;
    }
    
    //计算环中节点的个数
    int nodeInLoop = 1;
    //meetingnode是环中的某个节点
    ListNode *pNode1 = meettingNode;
    while (pNode1->m_pNext != meettingNode) {
        pNode1 = pNode1->m_pNext;
        nodeInLoop ++;
    }
    
    //拿到环中的节点数
    // pNode 指向第nodeInLoop个节点
    pNode1 = pHead;
    for (int i = 0; i < nodeInLoop; i++) {
        pNode1 = pNode1->m_pNext;
    }
    
    //pNode2指向队首的元素
    ListNode *pNode2 = pHead;
    
    //一次往后走 直到这两个指针指向同一个节点
    while (pNode1 != pNode2) {
        pNode2 = pNode2->m_pNext;
        pNode1 = pNode1->m_pNext;
    }
    
    return pNode1;
    
}
```

