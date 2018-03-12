
## 题目

```
面试题10：斐波那契数列
题目：写一个函数，输入n，求斐波那契（Fibonacci）数列的第n项。
```

## 思路

### 一 递归的思想

> 鉴于Fibonacci函数的计算方式

```
            0  n = 0
    f(n) =  1  n = 1
            f(n-1) + f(n-2)  n >=2
```
我们可以使用递归的思想 简单粗暴 
> 不过这种方式 效率很低 存在大量重复计算 导致我们的计算时间 特别高

### 二、循环

> 我们可以采用自底向上的思路 将已经计算过的记录下来 避免重复计算 从而降低计算时间


## 图

### 递归

![递归](http://og0h689k8.bkt.clouddn.com/18-3-12/43700653.jpg)

### 循环

![循环](http://og0h689k8.bkt.clouddn.com/18-3-12/6953995.jpg)


## 代码实现

### 递归

```c
//获取斐波那契数列 第n项
// 直接使用递归的方法  这种方法效率太低 原因是进行了大量的重复计算
// n = 50 Use Time:94
long long fibonacci(int n) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    
    return fibonacci(n-1) + fibonacci(n-2);
}
```

### 循环

```c
// 为了避免大量的重复计算 我们只需要把上次计算过的内容保存起来就可以
// 因此 我们可以采用从下往上的计算方式
// n = 50 Use Time:0
long long fibonacii2(int n) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    
    long long fibNMinusOne = 1;
    long long fibNMinusTwo = 0;
    long long fibN = 0;
    for (unsigned int i = 2; i <= n; i++) {
        fibN = fibNMinusOne + fibNMinusTwo;
        
        fibNMinusTwo = fibNMinusOne;
        fibNMinusOne = fibN;
    }
    
    return fibN;
}
```


## 类似案例

```
青蛙跳台阶问题
一只青蛙一次可以跳上1级台阶,也可以跳上2级台阶，
求 改青蛙跳上一个n级台阶总共有多少种跳法
```

思路：
我们把n级台阶看成n的函数，记为f(n) 当n>2时 第一次跳的时候就有两种选择
一：第一次跳一级 此事跳法数目等于后面剩下的n-1级台阶跳法数目即为f(n-1)
二：第一次跳二级 此时跳法数目等于后面剩下n-2级台阶的跳法数目即为f(n-2)
因此 不难看出f(n) = f(n-1) + f(n-2)


```
我们可以用 2x1的小矩形横着或者竖着去覆盖更大的矩形，请问用8个2x1的小矩形无重叠覆盖一个2*8的大矩形，总共有多少种方法
```
![](http://og0h689k8.bkt.clouddn.com/18-3-12/95853050.jpg)

思路：

```
我们可以把2*8的方法记为f(8)，那么第一次我们又两种选择
一: 竖着放 右边还剩下7*2个小矩形 可以记为f(7)
二: 横着放 那么横着放的小矩形 下面也必须有一个横着放的 右边还剩下6*2个小矩形 记为f(6)

因此 我们也可以看出f(8) = f（7）+f(6);
```



