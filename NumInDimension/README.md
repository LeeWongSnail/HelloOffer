# 二维数组中的查找

```
 题目：
 在一个二维数组中,每一行周按照从左到右递增的顺序排序,每一列都按照从上到下递增的顺序排序
 请完成一个函数 输入这样的一个二维数组和一个整数 判断数组中是否含有这个整数
```

示例：

```
1   2   6   8
2   4   9   12
4   7   10  13
6   8   11  15

```

## 解题思路

首先选取数组的右上角的数字。如果该数字等于要查找的数字，则查找过程结束。
如果该数字大于要查找的数字，则剔除这个数字所在的列；
如果该数字小于要查找的数字，则剔除这个数字所在的行。

## 图解

![](http://og0h689k8.bkt.clouddn.com/18-3-6/37060588.jpg)

## 代码

```c
bool getNumInDimension(int list[4][4],int column,int row,int findNum)
{
    if (column <= 0 || row <= 0) {
        return false;
    }
    
    int col = column - 1;
    int r = 0;
    while (col >= 1 && r < row-1 && sizeof(*list) > 0) {
        //获取二维数组右上角的数值
        int num = list[r][col];
        if (num == findNum) {
            return true;
        } else if (num > findNum) {
            //num 比要找到数字大 那么往矩阵的左下角找 去掉num所在的列
            col--;
        } else if (num < findNum) {
            //num 比要找到数字小 那么往矩阵的右上角找 去掉num所在的行
            r++;
        }
        printf("column = %d  row= %d \n",col,r);
    }
    return false;
}
```


