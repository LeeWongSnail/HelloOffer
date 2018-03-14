## 题目

```
 实现函数double Power(double base, int exponent)
 求 base的 exponent次方
 不得使用函数库 同时不需要考虑最大数问题
```

## 思路

这个问题 实现起来简单 但是其中存在很多问题以及可以优化的地方
> 考虑输入的边界问题 比如输入的exponent和base为0 或者为负数 以及对应的处理
> 如何提高计算的效率
> 如何让调用者知道调用的结果 错误提示

具体的比较放到下面代码中提现！

## 代码实现

### 最简单直接的方法

```c
double Power(double base,double exponent) {
    double result = 1;
    for (int i = 0; i < exponent; i++) {
        result *=base;
    }
    
    return result;
}
```

`存在的问题`:
exponent 小于0或者等于0的情况改如何处理？

### 特殊情况处理

```c
double PowerWithUnsignedExponent(double base,unsigned int exponent) {
    double result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}
```

```c

// 考虑到0 和负数
bool g_InvalidInput = false;
double Power2(double base, double exponent) {
    
    g_InvalidInput = false;
    //基数是0 切 指数是负数 因为要通过求倒数得到结果 避免 分母是0的情况
    if (base == 0.0 && exponent < 0.0) {
        g_InvalidInput = true;
        return 0.0;
    }
    
    if (base == 0.0) {
        printf("没有意义的输入");
    }
    if (base == 1) {
        return 1;
    }
    
    unsigned int absExponent = (unsigned int)exponent;
    if (exponent < 0) {
        absExponent = (unsigned int)-exponent;
    }
    
    double result = PowerWithUnsignedExponent2(base, absExponent);
    if (exponent < 0) {
        return 1.0/result;
    } else {
        return result;
    }
    
    return  result;
}
```

`处理方式`：

* 1、增加了一个全局变量来记录计算是否出错
* 2、对于输入为负数或者0的情况进行处理

那么，这个算法还有没有可以优化的地方呢? 

### 计算方式的优化

我们看到计算m^n时要计算n次 这个次数是否可以减少呢？

其实 我们只需判断n是奇数还是偶数
如果是偶数(8) 那么我们可以直接计算m^(n/2) * m^(n/2) 进而不断缩小n的值至1
如果是奇数(9) 我们在得到偶数的结果之后在最后乘以m一次即可

```c

// 进一步的优化 计算base的exponent次方
double PowerWithUnsignedExponent2(double base, unsigned int exponent) {
    if (exponent == 1) {
        return base;
    }
    if (exponent == 0) {
        return 1;
    }
    
    double result = PowerWithUnsignedExponent2(base, exponent>>1);
    result *= result;
    //判断exponent 这个是奇数还是偶数
    if ((exponent & 0x1) == 1) {
         result *=base;
    }
    return result;
}
```


