## 题目

```
 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一格开始，每一步都可以在
 矩阵的上下左右移动一格，如果一条路径经过矩阵的某一格，那么该路径不能再次经过改格子。
 例如 在下面3*4的矩阵中包含一条字符串“bfce”的路径(路径中的字母用下划线标出)。但矩阵中不包含字符串“abfb”的路径，
 因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，不经不能再次进入这个格子
```

## 思路

这其实是一个回溯法的经典案例。

回溯法：从解决问题每一步的所有可能选项里系统的选择一个可行的解决方案。回溯法非常适合由多个步骤组成的问题，并且每个步骤都有多个选项，当我们在某一步选择了其中一个选项时，就进入下一步，然后又面临新的选项。我们就这样重复选择直至到达最终的状态。

通常回溯法算法适合用递归实现代码。当我们到达某一节点时，尝试所有可能的选项并在满足条件的前提下递归的抵达下一个节点。


## 图示

![](http://og0h689k8.bkt.clouddn.com/18-3-13/13780558.jpg)

## 代码

```c
/*这个是查找的核心方法
 matrix: 给出的矩阵
 rows: 矩阵的行数
 cols: 矩阵的列数
 row: 第几行
 col: 第几列
 str: 要查找的字符串
 pathLength:查找到的字符的长度
 visited:目前已经找到的字符的位置
 
 **/
bool hasPathCore(const char *matrix,int rows,int cols,int row,int col,const char *str, int &pathLength,bool * visited) {
    
    //判断是否已经查找到字符末尾
    if (str[pathLength] == '\0') {
        return true;
    }
    
    bool hasPath = false;
    
    //行和列范围合理
    //这一行这一列的值等于要查找的值
    //这一行这一列的值没有在已存在的路径中
    if (row >=0 && row < rows && col >=0 && col<cols
        && matrix[row *cols + col] == str[pathLength]
        && !visited[row *cols + col]) {
        
        //找到这个字符之后
        
        // 1已找到的字符路径长度+1
        ++pathLength;
        
        //2 将这个位置的visited置为true
        visited[row *cols + col] = true;
        
        //查找下一个字符
        //方向为 上下左右
        hasPath =
        hasPathCore(matrix, rows, cols, row-1, col, str, pathLength, visited) ||
        hasPathCore(matrix, rows, cols, row+1, col, str, pathLength, visited)  ||
        hasPathCore(matrix, rows, cols, row, col-1, str, pathLength, visited) ||
        hasPathCore(matrix, rows, cols, rows, col+1, str, pathLength, visited);
        
        if (!hasPath) {
            --pathLength;
            visited[row *col + col] = false;
        }
    }
    
    
    
    return hasPath;
}
```

```c

bool hasPath(char *matrix, int rows,int cols,char *str)
{
    if (matrix == nullptr || rows < 1 || cols < 1 || str == nullptr) {
        return false;
    }
    
    //定义一个bool类型的矩阵用于记录 某个点是否已经在路径中了
    bool *visited = new bool[rows*cols];
    //设置这个矩阵的初始值为false
    memset(visited, 0, rows*cols);
    
    int pathLength = 0;
    
    //遍历这个二维矩阵 从左上角开始
    for (int i = 0; i < rows; i++) {
        
        for (int j = 0; j < cols; j++) {
            //如果能找到就返回true
            if (hasPathCore(matrix, rows, cols, i, j, str, pathLength, visited)) {
                return true;
            }
        }
    }
    
    delete []visited;
    
    return false;
}
```

