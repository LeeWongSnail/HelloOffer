
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

