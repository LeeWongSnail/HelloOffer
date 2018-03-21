//
//  main.cpp
//  PrintMatrixClockwisely
//
//  Created by LeeWong on 2018/3/21.
//  Copyright © 2018年 LeeWong. All rights reserved.
//

/*
 输入一个矩阵 按照从外向里以顺时针的顺序依次打印出每个数字 例如
 
 1  2   3   4
 5  6   7   8
 9  10  11  12
 13 14  15  16
 
 **/

#include <iostream>

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

int main(int argc, const char * argv[]) {
    // insert code here...
    int rows = 4;
    int columns = 4;
    int** numbers = new int*[rows];
    for(int i = 0; i < rows; ++i)
    {
        numbers[i] = new int[columns];
        for(int j = 0; j < columns; ++j)
        {
            numbers[i][j] = i * columns + j + 1;
        }
    }
    
    printMatrix(numbers, columns, rows);
    return 0;
    
    
    
    
}
