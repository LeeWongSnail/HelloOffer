# 替换字符串中的空格

## 题目

```
 请事先一个函数,把字符串中的每个空格替换成“%20”。例如 输入“We are happy.” 则输出"We%20are%20happy."
```

## 思路分析

> 先遍历一次字符串,这样就能统计出字符串中空格的总数,并可以计算替换之后的字符串的总长度
> 每替换一个空格，长度增加2，因此替换以后字符串的长度等于原来的长度加上空格的个数乘以2


## 示意图

![](http://og0h689k8.bkt.clouddn.com/18-3-6/62677303.jpg)


## 代码示意

### 方法一：

```c

/*从前向后遍历这个字符串 如果遇到空格 将后面的元素后移两个格 插入%20
 时间复杂度O(n²)
 */

void replaceStringBlank(char *a,int length)
{
    int len = length;
    for (int i = 0; i < len; i++) {
        char elem = a[i];
        printf("%c\n",elem);
        if (elem == ' ') {
            //如果是空格 将空格后面的元素后移
            for (int j = len; j > i; j--) {
                a[j+2] = a[j];
            }
            len += 2;
            a[i] = '%';
            a[i+1] = '2';
            a[i+2] = '0';
            i+=2;
            printf("%s\n",a);
        }
    }
}
```

### 方法二

```C
/时间复杂度 O（n）/
void replaceStringToBlank1(char *a,int length) {
    if (length <= 0) {
        return;
    }
    
    int originalLength = 0;
    int numberOfBlank = 0;
    int i = 0;
    while (a[i] != '\0') {
        ++originalLength;
        if (a[i] == ' ') {
            ++numberOfBlank;
        }
        ++i;
    }
    
    int newLength = originalLength + numberOfBlank * 2;
    
    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
    while (indexOfOriginal >=0 && indexOfNew > indexOfOriginal) {
        if (a[indexOfOriginal] == ' ') {
            a[indexOfNew--] = '0';
            a[indexOfNew--] = '2';
            a[indexOfNew--] = '%';
        } else {
            a[indexOfNew--] = a[indexOfOriginal];
        }
        
        --indexOfOriginal;
        
    }
    
    printf("%s",a);
}
```


