## 题目

```
 地上有m行n列的方格。一个机器人从坐标(0,0)的格子开始移动,他每次可以向左、右、上、下移动一格，但不能进入行坐标和列坐标的数位之和大于k的格子
 例如 当k=18时 机器人能够进入方格(35,37) 因为 3+5+3+7=18 但不能进入方格(38,38) 因为3+5+3+8 = 19>18
 请问 该机器人能够到达多少个格子
```

## 思路

这个题目跟前面的[矩阵中的路径](https://github.com/LeeWongSnail/HelloOffer/tree/master/PathInMatrix)问题相似，都是回溯法的应用。

机器人从(0,0)开始移动.当他准备进入坐标为(i,j)的格子时,通过检查坐标的数位和来判断机器人能否进入。如果机器人能够进入坐标为(i,j)的格子，则在判断他能否进入相邻的四个格子(i-1,j)(i+1,j)(i,j-1) (i,j+1).

## 代码实现

```c
//利用回溯思想 采取递归的方法 计算个数
int movingCountCore(int threshold,int rows, int cols,int row,int col,bool *visited) {
    
    int count = 0;
    //先检查是否可以进入这个格子
    if (check(threshold, rows, cols, row, col, visited)) {
        
        visited[row *cols + col] = true;
        
        //上左下右
        count = 1 + movingCountCore(threshold, rows, cols, row-1, col, visited) +
                    movingCountCore(threshold, rows, cols, row+1, col, visited) +
                    movingCountCore(threshold, rows, cols, row, col+1, visited) +
        movingCountCore(threshold, rows, cols, row, col-1, visited);
        
    }
    
    
    
    return count;
}
```


```c

//计算个数
int movingCount(int threshold, int rows, int cols) {
    if (threshold < 0 || rows < 0 || cols < 0) {
        return 0;
    }
    
    bool *visited = new bool[rows *cols];
    memset(visited, 0, rows*cols);
    
    int count = movingCountCore(threshold, rows, cols, 0, 0, visited);
    
    delete[] visited;
    
    return count;
}
```



