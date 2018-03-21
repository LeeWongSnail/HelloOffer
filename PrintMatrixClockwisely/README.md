## 题目

 输入一个矩阵 按照从外向里以顺时针的顺序依次打印出每个数字 例如
 
 ```
 1  2   3   4
 5  6   7   8
 9  10  11  12
 13 14  15  16
 ```
 
## 思路

### 首先判断一个m行n列的矩阵需要遍历多少次才可以完成全部元素的遍历

一次循环正常情况下,可以遍历最外层的一行和一列。那么一次会减少矩阵的两行两列,那么正常情况下只需要少于min(m/2,n/2)+1次循环既可以将所有的元素都遍历完成

### 在思考如何完成一整个环的遍历

 对于一个矩阵的遍历我们可以分为四步
> 从左到右 遍历完成之后 下一个元素从 strart+1 行开始
> 从上到下 遍历完成后  下一个元素从 endY-1列开始
> 从右到左  遍历完成后  下一个元素  endX-1行开始
> 从下到上  遍历到底start+1行停止


## 代码实现

```objc
void printMatrix(int **matrix,int cols, int rows) {
    if (matrix == nullptr || cols <= 0 || rows<=0) {
        return;
    }
    
    int start = 0;
    // 这个地方的判断条件是 依据
    // 没输出一次最外层 row -2 col-2  有次可以得出 如果要完整遍历出 这个矩阵
    // 最多需要遍历多少次
    while (cols > start * 2 && rows > start * 2) {
        printSingleCircleMatrix(matrix, cols, rows, start);
        start ++;
    }
    
}
```

```objc
//打印 矩阵中的一个环
void printSingleCircleMatrix(int **matrix,int cols, int rows,int start) {
    
    int endX = cols - 1 - start;
    int endY = rows - 1 - start;
    
    //开始循环打印
    
    //1、从左到右打印一行 这一步是肯定有的哪怕最后一个环只有一个数字
    for (int i = start; i <= endX; i++) {
        printf("%d",matrix[start][i]);
    }
    
    printf("\n");
    
    //2、从上到下打印一列
    if (start < endY) {
        for (int i = start+1; i <= endY; i++) {
            printf("%d",matrix[i][endY]);
        }
    }
    
    printf("\n");

    // 3、从右往左打印一行
    if (start < endX && start < endY) {
        for (int i = endX-1; i >= start; i--) {
            printf("%d",matrix[endX][i]);
        }
    }
    printf("\n");
    // 4、从下往上打印一列
    if (start < endX && start < endY-1) {
        for (int i = endX-1; i > start; i--) {
            printf("%d",matrix[i][start]);
        }
    }
    printf("\n");

}
```

