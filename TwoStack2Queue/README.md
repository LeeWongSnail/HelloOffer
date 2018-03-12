## 题目

```
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数appendTail
和deleteHead，分别完成在队列尾部插入结点和在队列头部删除结点的功能。
```

## 解题思路

栈的特性为后进先出 而队列则是先进先出 ，我们可以利用这个特性来对两个栈 分别做入栈和出站的操作

## 图例

![](http://og0h689k8.bkt.clouddn.com/18-3-12/92875802.jpg)

## 代码实现

```c
//在队列尾部插入节点
template <typename T>
void CQueue<T>::appendTail(const T & element) {
    stack1.push(element);
}

```

```c
//在队列头部删除节点
template <typename T>
T CQueue<T>::deleteHead() {
    if (stack2.size() > 0) {
        //如果stack2中有值则直接top这个值
        T head = stack2.top();
        stack2.pop();
        return head;
    } else if (stack2.size() == 0 && stack1.size() > 0) {
        //stack2为空 stack1 不为空
        //将stack1中的内容 转移到stack2中
        int size = stack1.size();
        for (int i =0; i < size; i++) {
            T head = stack1.top();
            stack2.push(head);
            stack1.pop();
        }
        
        //此时 stack1为空 stack2不为空
        T head  =stack2.top();
        stack2.pop();
        return head;
    } else {
        printf("queue is empty");
    }
    return 0;
}
```

```c
//打印队列中的内容
void CQueue<T>::printQueue() {
    std::stack<T> tempStack;
//    printf("%d\n",stack2.size());
    if (stack2.size() > 0) {
        int size = stack2.size();
        for (int i = 0; i < size; i++) {
            T head = stack2.top();
            stack2.pop();
            tempStack.push(head);
        }
        //还原stack2
        for (int j = 0; j < size; j++) {
            T head = tempStack.top();
            tempStack.pop();
            stack2.push(head);
            printf("%d\n",head);
        }
    }
//    printf("%d\n",stack1.size());
    if (stack1.size() > 0)
    {
        for (int j = 0; j < tempStack.size(); j++) {
            tempStack.pop();
        }
        int size = stack1.size();
        for (int i = 0; i < size; i++) {
            T head = stack1.top();
            stack1.pop();
            tempStack.push(head);
        }
        //还原stack1
        for (int j = 0; j < size; j++) {
            T head = tempStack.top();
            tempStack.pop();
            stack1.push(head);
            printf("%d\n",head);
        }
        
    }
}
```


