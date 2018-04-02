## 题目

```
 题目: 字符串的排列
 输入一个字符串,打印出该字符串中字符的所有排列。例如,输入字符串abc，则打印出由字符abc所能排列出来的所有字符串
 abc acb bca bac cab cba
```

## 思路


* 将这个字符串看成两部分,第一个字符和除了第一个之后的所有字符
* 那么第一个字符不变的情况下的组合就是 除了第一个字符之外所有字符排列之后的结果
* 每个字符都有放到第一个字符的机会 那么 将后面的每个字符与第一个字符交换 然后求 每次后面剩余字符的排列 最后汇总起来


## 图示

![](http://og0h689k8.bkt.clouddn.com/18-4-2/89362403.jpg)

## 代码实现

```c++

void Permutation(char *pStr, char *pBegin) {
    if (*pBegin == '\0') {
        printf("%s\n",pStr);
    } else {
        
        for (char *pCh = pBegin; *pCh != '\0'; pCh++) {
            
            char temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;
            
            
            Permutation(pStr, pBegin+1);
            
            temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;
            
            
        }
        
    }
    
    
}

```


```c++
void Permutation(char *pStr) {
    if (pStr == nullptr) {
        return;
    }
    Permutation(pStr, pStr);
}
```


