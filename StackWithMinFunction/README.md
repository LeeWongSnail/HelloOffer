## 题目

```
 定义栈的数据结构 请在该类型中实现一个能够得到站的最小元素的min函数
 在改栈中 调用min push pop 的时间复杂度都是O(1)
```

## 思路

### 正常思路 

如果要在O(1)的时间内找到最小的元素 那么我们可以对栈内的元素进行排序 将最小的元素放到栈顶
但是这样存在一个问题: 那么这个栈就不是后进先出的了 这根栈的最基本特性违背 因此这种做法是错误的
 
### 其他方法

 我们可以 记住栈中的最小元素 每次push的时候都进行比较 然后记录最小值
 但是这样也存在一个问题： 最小值出栈之后 次小值是多少
 
### 可用方法
 
 鉴于上面两种方法都不行 因此我们需要记录 栈中每个结点被push入栈的时候栈中所有元素的最小值 即便是最小值出栈了 我们仍然可以获取到剩余栈中的元素的最小值


## 图示

![stackwithmin](http://og0h689k8.bkt.clouddn.com/18-3-21/58764785.jpg)

## 代码实现

```c++
template <typename T> void StackWithMin<T>::push(const T& value)
{
    // 把新元素添加到辅助栈
    m_data.push(value);
    
    // 当新元素比之前的最小元素小时，把新元素插入辅助栈里；
    // 否则把之前的最小元素重复插入辅助栈里
    if(m_min.size() == 0 || value < m_min.top())
        m_min.push(value);
    else
        m_min.push(m_min.top());
}

```

```c++
template <typename T> void StackWithMin<T>::pop()
{
    assert(m_data.size() > 0 && m_min.size() > 0);
    
    m_data.pop();
    m_min.pop();
}
```


