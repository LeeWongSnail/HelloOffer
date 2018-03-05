# 不修改数组 找出重复的数字

### 问题

```
 题目二：不修改数组找出重复的数字。在一个长度为n+1的数组里的所有数字都在1~n的范围内，
 所以数组中至少有一个数字是重复的。请找出数组中任意一个重复的数字，但不能修改输入的数组。
 例如，如果输入长度为8的数组{2，3，5，4，3，2，6，7}，那么对应的输出是重复的数字2或者3。
```

### 解法

我们把从1-n 的数字 从中间的数字((n-1)/2 + 1)m分成两部分,前面一部分1-m 后面一部分m-n，在数组中查找1-m中的数字个数是否大于m-1,m-n之间的数字是否大于m-n,如果超过那么久证明这个区间内肯定存在重复的数字 那么 进一步缩小空间(通过就该m的值),在后再拆分的小区间内 递归的用这种判断,知道最终找到重复的数字

### 代码实现

```C
/**
 数组list 长度为length 在start到end区间内的值的个数
 */
int countInRange(int list[],int length,int start , int end) {

    if (sizeof(*list) == 0) {
        return -1;
    }
    
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (list[i] >= start && list[i] <= end) {
            count++;
        }
    }
    
    return count;
}


int getDuplicateWithoutModify(int list[],int length) {
    
    //先判断数组是否为空 length是否合法
    if (sizeof(*list) == 0 || length <= 0) {
        return -1;
    }
    
    int start = 1;
    int end = length -1;
    
    while (end >= start) {
        int middle = (end-start)/2 +start;
        //计算start到middle之间的数字的个数
        int count = countInRange(list, length, start, middle);
        
        if (start == end) {
            if (count > 1) {
                return start;
            } else {
                break;
            }
        }
        
        if (count > middle-start + 1) {
            end = middle;
        } else {
            start = middle+1;
        }
    }
    
    return -1;
}
```

### 图片示意

![](http://og0h689k8.bkt.clouddn.com/18-3-5/77250516.jpg)

