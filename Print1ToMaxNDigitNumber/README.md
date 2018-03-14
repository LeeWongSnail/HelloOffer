## 题目

```
 输入数字m 按顺序打印出从1到最大的n为十进制数
 比如 输入3 则打印出 1，2，3，...999
```

## 思路

### 最简单的方法

求出10^n 然后直接循环输出到10^n

`存在的问题`：

如果输入的n比较大 有可能数值会超过int的表示范围 甚至longlong的表示范围也有可能

### 使用字符串表示数字

第一种方法可以看出 不论使用何种数字类型 都可能无法满足这个情况 因此我们决定使用字符串代替数字

但是 使用字符串代替数字存在两个问题

>需要模仿数字的自加操作
>需要以输出数字的方式输出字符串

### 实现方式进一步优化

第二种方式其实已经达到了想要的效果,但是代码比较复杂。

我们换一种思路 将这个问题转换成数字排列的解法 使用递归的方法让代码更加简洁


## 代码实现

### 方法一

```c
/*最简单直观的方法
 存在的问题 如果n的位数很大 有可能超过int类型的表示范围 甚至超过longlong的表示范围
 **/
void print1ToMaxNDigit(int n) {
    
    int number = 1;
    int i = 0;
    while (i < n) {
        number *= 10;
        i++;
    }
    for (int j = 1; j < number ; j++) {
        printf("%d\n",j);
    }
}
```

### 方法二

```c

/*
 优化使用字符串表示数字 字符串不需要考虑越界的情况
 但是字符串没有 ++ 操作 而且打印的时候也需要将字符串以数字的形式打印
 **/

//实现字符串的递增操作
//返回值bool表示是否达到了n为数的最大值
bool Increment(char *number) {
    //是否达到了最大值
    bool isOverflow = false;
    //是否有进位
    int nTakeOver = 0;
    
    int nLength = strlen(number);
    for (int i = nLength -1; i >=0; i--) {
        //因为 最低位在最后面 所以从最右面开始
        int nSum = number[i]-'0' + nTakeOver; //number[i]-'0' ASCII 相减得到数字 于是否需要进位相加 尽心个判断
        //初始的时候nSum全为0 需要从1开始
        if (i == nLength -1) {
            nSum++;
        }
        
        if (nSum >=10) {
            
            if (i == 0) {
                //已经到了最高位
                isOverflow = true;
            } else {
                
                nSum -= 10;
                nTakeOver = 1;
                number[i] = nSum + '0';
            }
            
        } else {
            number[i] = nSum + '0';
            break;
        }
    }
    
    
    return isOverflow;
}
```

```c

void print1ToMaxNDigit2(int n) {
    
    if (n <= 0) {
        return;
    }
    
    char *number = new  char[n+1];
    memset(number, '0', n);
    number[n] = '\0';
    
    while (!Increment(number)) {
        printNum(number);
    }
    
    delete []number;
}
```

### 方法三

```c
// 换种思路
// 如果 我们在数字前面补0 就会发现n位所有十进制数其实就是n个从0-9的全排列 也就是说我们可以把数字的每一位都从0-9排列一遍
// 这样就得到了所有的十进制数
// 这种情况 从代码上看 因为运用了递归的思想 代码简洁了
void print1ToMaxNDigit3Recursively(char *number,int length,int index) {
    //如果已经递归到了最内层 也就是数字的最低位 直接打印
    if (index == length -1) {
        printNum(number);
        return;
    }
    
    //每一位都是0-9
    for (int i = 0; i < 10; i++) {
        number[index +1] = '0' + i; //现将index+1位置为0 再去将第index+1位递增
        print1ToMaxNDigit3Recursively(number, length, index+1);
    }
}

```

```c
void print1ToMaxNDigit3(int n) {
    
    if (n < 0) {
        return;
    }
    
    //对比第二种方法这里没有将每一位都置为0
    char *number = new char[n+1];
    number[n]='\0';
    
    //最高位开始
    for (int i = 0; i < 10; i++) {
        number[0] = '0'+i; //现将这一位置为0
        print1ToMaxNDigit3Recursively(number, n, 0);
    }
    
    delete [] number;
}
```


### 公共方法 打印字符串

```c
//实现打印字符串的功能 位数不够时 前面0的补位 不要输出
//这种输出方式实际上是按位打印的 打印的结果是这样的
void printNum(char *num) {
    
    bool isBeginWithZero = true;
    int nLength = strlen(num);
    
    for (int i = 0; i <nLength; i++) {
        
        if (isBeginWithZero && num[i] != '0') {
            isBeginWithZero = false;
        }
        
        if (!isBeginWithZero) {
            printf("%c",num[i]);
        }
        //这里加一个换行是为了 将输出更美观
        if (i == nLength -1) {
            printf("\n");
        }
        
    }
    
}
```

