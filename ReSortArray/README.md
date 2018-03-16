## 题目

```
 输入一个整数数组,实现一个函数来调整该数组中数字的顺序,是的所有奇数位于数组的前半部分 所有的偶数位于数组的后半部分

```

## 思路

### 思路一

最简单的方式就是 遍历这个数组。如果发现这个数是偶数那么将这个数后面的每一个数 向前移动一格,然后将这个数放在最后一个位置
算法的时间复杂度为O(n)


### 思路二 降低复杂度

设置两个指针pBegin和pEnd分别指向这个数组的第一个位置和最后一个位置。
>判断头部位置元素是否为偶数 如果是偶数 则尾部指针开始向前遍历 如果不是 则++ 判断下一个位置
>判断尾部元素是否为奇数 如果是则 首部指针开始向后遍历 如果不是则-- 判断前面一个位置
当头部遇到了偶数 尾部遇到了奇数 则得到一个可以互相交换的值 交换二者的值

循环结束的条件是 pBegin == pEnd;

### 思路三  抽象

本题目的判断条件 是根据奇数还是偶数来进行判断的,但是在实际的工作中，可能存在其他的判断条件，比如 正负数 来判断。

因此，我们可以做一个封装 将判断的条件单独拿出来 这样如果 判断的逻辑需要改变 我们只需要改变 拿出来的那个判断是否满足条件的函数就可以

## 图示

下面是思路二的图示

![](http://og0h689k8.bkt.clouddn.com/18-3-16/64443002.jpg)

## 代码实现

### 思路一

```c++
//基本的解法 O(n^2)

void resortArray(int *str,int length) {
    
    for (int i = 0 ; i < length; i++) {
        
        if (str[i]%2==0) {
            //如果是偶数 则将偶数后面的所有数据往前移动
            char elem = str[i];
            for (int j = i+1; j<length; j++) {
                str[j-1] = str[j];
            }
            str[length-1] = elem;
        }
        
    }
    
}
```

### 思路二

```c++
// 更进一步的解法
void resortArray1(int *str,int length) {
    //两个指针指向 这个数组的首尾
    int *pBegin = str;
    int *pEnd = str+length-1;
    
    
    while (pBegin < pEnd) {
       
        //从begin开始
        while ((*pBegin & 0x1) != 0) {
            //如果是奇数
            pBegin++;
        }
        
        while ((*pEnd & 0x1) == 0) {
            pEnd--;
        }
        
        //找到之后交换
        if (pBegin < pEnd) {
           int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
        }
        
    }
}
```

### 思路三

```c++

// 此类问题可能有很多种 这个问题是奇数跟偶数作为区分条件 也有可能是其他的条件 比如正数负数  被三整除不能被三整除

//是否为偶数
bool SatisfyTheCondition(int n) {
    return (n & 0x1)== 0;
}
```

```c++
void resortArray2(int *str,int length) {
    //两个指针指向 这个数组的首尾
    int *pBegin = str;
    int *pEnd = str+length-1;
    
    
    while (pBegin < pEnd) {
        
        //从begin开始
        while (!SatisfyTheCondition(*pBegin)) {
            //如果是奇数
            pBegin++;
            printf("%d\n",*pBegin);
        }
        
        while (SatisfyTheCondition(*pEnd)) {
            pEnd--;
            printf("%d\n",*pEnd);
        }
        
        //找到之后交换
        if (pBegin < pEnd) {
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
        }
        
    }
}
```

