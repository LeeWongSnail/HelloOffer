//
//  main.cpp
//  CutRope
//
//  Created by LeeWong on 2018/3/13.
//  Copyright © 2018年 LeeWong. All rights reserved.
//


/*
 给你一根长度为n的绳子，请把绳子剪成m段(m,n都是整数,并且 n>1 并且 m>1),每段身子的长度记为 k[0],k[1],....k[m].
 请问 k[0] * k[1]*....*k[m] 可能的最大乘积是多少？
 例如当身子的长度为8时 我们要把它剪成铲毒分别为2 3 3 的三段此事得到最大乘积18
 **/

#include <iostream>
#include <cmath>

/*
 使用动态规划的方式解决这个问题
 */
int maxResultAfterCutting(int length) {
    if (length < 2) {
        return 0;
    }
    if (length == 2) {
        return 1;
    }
    if (length == 3) {
        return 2;
    }
    
    //这个数组是为了记录 长度为i的绳子被切之后的最大乘积
    int *product = new int[length +1];
    
    /*
     这里面的这几个固定值 需要好好理解以下
     当length<=3的时候 我们直接通过上面代码的判断 直接返回了 因此 下面product中的值并不是表示 长度为i的绳子被切之后的最大乘积
     而是表示 length>3的时候 绳子被切的时候可能存在长度为1 2 3的情况
     比如 长度为 6的绳子可以切成 长度为 1 2 3 的三段 那么这三段都属于不切的情况下 才是最大值
     比如 3 如果可以不切 最大值就是3 而如果继续切那么最大值为2
     注意 此时 3 只是作为一个 乘数 计算最大乘积
    **/
    product[0] = 0;
    product[1] = 0;
    product[2] = 1;
    product[3] = 2;
    
    int max = 0;
    //计算长度为i-lenght中所有长度的最大值的乘积 让后缓存起来供后面计算的时候使用
    for (int i = 4; i <= length; i++) {
        
        
        max = 0;
        for(int j = 1; j <= i/2;j++) {
            int result = product[j] * product[i-j];
            if (max < result) {
                max = result;
            }
            product[i] = max;
        }
    }
    
    max = product[length];
    
    delete[] product;
    return max;
}

/*
 使用贪婪算法的方式解决这个问题
 思路：
 当n>=5时，我们尽可能多地剪长度为3的绳子,当剩下的绳子长度为4时，把绳子剪成两段长度为2的绳子
 
 //解释一下 为什么要尽可能的将身子剪成长度为3
 根据 动态规划的思路我们可以思考 如果当前有一个绳子的长度为5 那么怎么剪才能得到最大值
 如果长度5作为一个长度更长的绳子的子集那么可以不用剪那么长度为5 但是如果剪 可以剪成 2 3 的两段 乘积为6 > 5
 这就证明剪了要比 不减得到的乘积更大 因此 大于5的绳子都应该继续剪 而不是 保持这个长度
 这里有个特殊的情况 长度为4的时候 可以有两种剪法 2 2 ，1 3 很明显 2*2 > 1*3
 那么这里在对一个一个很长的绳子进行切割的时候 尽量剪成长度为3的 但是如果剩余的身子长度为4的时候则应该剪成 2*2的两段
 **/

int maxProductAfterCutting2(int length) {
    
    if (length < 2) {
        return 0;
    }
    if (length == 2) {
        return 1;
    }
    if (length == 3) {
        return 2;
    }
    
    //尽可能去剪长度为3的绳子
    int timesOf3 = length/3;
    
    // 当绳子最后剩下的长度为4时，不能再去剪长度为3的绳子短
    // 此时 更好的方法是将绳子剪成长度为2的两段 因为2*2>3*1
    if (length-timesOf3*3 == 1) {
        timesOf3 -=1;
    }
    
    int timeOf2 = (length - timesOf3 *3)/2;
    
    //3的timeOf3次方 + 2的timeOf2次方
    return (int)(pow(3, timesOf3)) * (int)(pow(2, timeOf2));
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int max = maxProductAfterCutting2(8);
    printf("%d\n",max);
    return 0;
}
