//
//  main.cpp
//  RobotPlayArea
//
//  Created by LeeWong on 2018/3/13.
//  Copyright © 2018年 LeeWong. All rights reserved.
//

/*
 地上有m行n列的方格。一个机器人从坐标(0,0)的格子开始移动,他每次可以向左、右、上、下移动一格，但不能进入行坐标和列坐标的数位之和大于k的格子
 例如 当k=18时 机器人能够进入方格(35,37) 因为 3+5+3+7=18 但不能进入方格(38,38) 因为3+5+3+8 = 19>18
 请问 该机器人能够到达多少个格子
 **/

#include <iostream>

//获取某个多位数的位数之和

int getSum(int number) {
    int sum = 0;
    while (number > 0) {
        sum += number %10;
        number = number/10;
    }
    return sum;
}

//判断某个位置能否进入
bool check(int threshold, int rows, int cols,int row,int col,bool *visited) {
    
    if (row >= 0 && row < rows && col >= 0 && col < cols &&
        getSum(row) + getSum(col) <= threshold &&
        !visited[row *cols + col]
        ) {
        return true;
    }
    
    return false;
}

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


int main(int argc, const char * argv[]) {
    // insert code here...
    int count = movingCount(3, 5, 4);
    printf(" 可以运动%d个格子\n",count);
    return 0;
}
