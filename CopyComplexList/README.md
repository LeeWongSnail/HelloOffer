## 题目

复杂的链表复制

```
请实现函数ComplexListNode *Clone(ComplexListNode *pHead) 复制一个复杂链表。
在复杂链表中 每个节点除了有一个m_pNext指针指向下一个节点，还有一个m_pSibling 指针指向链表中的任一节点或者 nullptr
```


## 思路 

### 简单粗暴

> 复制这个复杂的链表 最直观的方法是直接遍历一遍这个链表 将m_pNext指针指向正确的位置
> 循环一次为每一个节点设置对应的m_pSibling

时间复杂度O(n^2)

### 空间换时间

>第一次循环的时候利用哈希表保存sibling节点的对应关系
>第二次节点设置每个节点指向的时候直接通过在哈希表中对应的sibling节点

时间复杂度O(n)


### 直接在一个链表内实现复制

> 将原链表中的每一个元素指向将他复制之后的那个元素 然后复制出来的元素在指向原链表
  节点中m_pNext指向的节点
> 然后通过一次遍历 将新复制出来的节点的m_pSibling节点的指向 之前指向节点的副本
> 最后将现有的节点拆开 将奇数节点和偶数节点 分别组成一个新的链表 那么这两个链表是一样的

## 图示

![](http://og0h689k8.bkt.clouddn.com/18-3-26/27928629.jpg)

## 代码实现

### 最复杂的方法

```c++

ComplexListNode *CloneList(ComplexListNode *pHead) {
    if (pHead == nullptr) {
        return nullptr;
    }
    
    ComplexListNode *pNode = pHead;
    ComplexListNode *pNewHead = nullptr;
    ComplexListNode *pNext = nullptr;
    while (pNode != nullptr) {
        ComplexListNode *node = CreateListNode(pNode->m_nValue);
        if (pNewHead == nullptr) {
            pNext = node;
            pNewHead = pNext;
        } else {
           pNext ->p_Next = node;
           pNext = node;
        }
        pNode= pNode->p_Next;
    }
    
    //下面开始设置 m_Silibing
    pNext = pNewHead;
    ComplexListNode *pHead1 = pHead;
    while (pHead1 != nullptr) {
       
        //遍历原来的链表 如果Sibling不为空那么设置新复制的链表的节点的Sibling
        if (pHead1->p_Sibling != nullptr) {
             pNode = pNewHead;
            while (pNode != nullptr) {
                if (pNode->m_nValue == pHead1->p_Sibling->m_nValue) {
                    pNext->p_Sibling = pNode;
                    break;
                }
                pNode = pNode->p_Next;
            }
            if (pNode == nullptr) {
                //找到最后都没有找到这个节点 那么这说明上一步的复制就出了问题
                printf("复制过程中复现了问题");
                return nullptr;
            } else {
                //找到了对应的节点
                pNext = pNext->p_Next;
            }
            
            
        } else {
            //如果这个节点的sibling节点没有值 那么直接跳过
            pNext = pNext->p_Next;
        }
        
        pHead1 = pHead1->p_Next;
        
    }
    
    
    return pNewHead;
}
```

### 方法二 空间换时间

 因为哈希表不太会用,所以这里代码暂时省略


### 方法三

```c++
//第一步 先复制一遍
void CloneNodes(ComplexListNode *pHead) {
    ComplexListNode *pNode = pHead;
    
    while (pNode != nullptr) {
        
        ComplexListNode *pCloned = CreateListNode(pNode->m_nValue);
        pCloned->p_Next = pNode->p_Next;
        pCloned->p_Sibling = nullptr;
        
        pNode->p_Next = pCloned;
        pNode = pCloned->p_Next;
    }
    
}

// 第二步 设置新复制节点的sibling指向
void ConnectSiblingNodes(ComplexListNode *pHead) {
    ComplexListNode *pNode = pHead;
    
    while (pNode != nullptr) {
        ComplexListNode *pCloneD = pNode->p_Next;
        if (pNode->p_Sibling != nullptr) {
            pCloneD->p_Sibling = pNode->p_Sibling->p_Next;
        }
        
        pNode = pCloneD->p_Next;
    }
}



// 第三部 将原来的一个链表 拆分为两个链表 奇数节点链接成一个链表 偶数节点链接成一个链表
ComplexListNode *ReConnectNodes(ComplexListNode *pHead) {
    
    ComplexListNode *pNode = pHead;
    ComplexListNode *pClonedHead = nullptr;
    ComplexListNode *pClonedNode = nullptr;
    
    //找到一个头结点
    if (pNode != nullptr) {
        pClonedHead = pClonedNode = pNode->p_Next;
        pNode->p_Next = pClonedNode->p_Next;
        pNode = pNode->p_Next;
    }
    
    
    while (pNode != nullptr) {
        pClonedNode->p_Next = pNode->p_Next;
        pClonedNode = pClonedNode->p_Next;
        pNode->p_Next = pClonedNode->p_Next;
        pNode = pNode->p_Next;
    }
    return pClonedHead;
}

// 总的方法
ComplexListNode *Clone(ComplexListNode *pHead) {
    // 现将整体复制一遍 并将复制的节点链接在原来的节点后面
    CloneNodes(pHead);
    // 依次设置新复制节点的sibling节点
    ConnectSiblingNodes(pHead);
    //将奇数位置的节点和偶数节点分辨连城一个新的链表
    return ReConnectNodes(pHead);
}
```


