## 题目

```
 请实现一个函数用来匹配包含 '.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符,而'*'表示他前面的字符可以出现任意次数(包含0次)
 在本题中，匹配是指字符串的所有字符匹配整个模式
 例如 字符串‘aaa’与模式'a.a'和‘ab*ac*a’匹配 但与‘aa.a’和‘ab*a’均不匹配
```

## 思路

![](http://og0h689k8.bkt.clouddn.com/18-3-15/19012740.jpg)

## 代码实现

```c++

bool matchCore(char *str , char *pattern) {
    
    if (*str == '\0' && *pattern == '\0') {
        return true;
    }
    
    if (*str != '\0' && *pattern == '\0') {
        return false;
    }
    
    
    //先判断 正则字符的第二个位置的元素是否为'*'
    if (*(pattern + 1) == '*') {
        //如果第二个位置的字符是'*'
        //那么第一个位置的元素是可以省略不看的
        
        if (*pattern == *str || (*(pattern + 1) == '.' && *str != '\0')) {
            //如果第一个字符相同 或者正则第一个字符是'.'(即使不相同也可以忽略)
            
            // 如果第一个字符相同 那么可以直接跳过正则的前两个字符 进行下面的匹配
            return matchCore(str+1, pattern+2) ||
                   matchCore(str+1, pattern) ||
                   matchCore(str, pattern+2);
            
        } else {
            //如果第一个字符 不同 且 正则的第一个字符不是'.'
            //因为第二个字符是‘*’ 因此可以将第一个字符忽略
            return matchCore(str+1, pattern+1);
        }
        
        
    } else {
        //如果第二个位置的字符不是'*'
        //则只需要保证第一个字符必须相同才能够匹配 如果第一个字符相同那么再去考虑剩下的字符
        if (*pattern == *str ||(*pattern == '.' && *str != '\0')) {
            return matchCore((str +1), (pattern+1));
        }
        
    }
    
    return false;
}

```

```c++
bool match(char *str , char *pattern) {
    
    if (str == nullptr || pattern == nullptr) {
        return false;
    }
    return matchCore(str, pattern);
}

```

