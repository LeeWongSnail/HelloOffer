//
//  main.cpp
//  IsPopOrderStack
//
//  Created by LeeWong on 2018/3/22.
//  Copyright © 2018年 LeeWong. All rights reserved.
//

/*
 输入两个证书序列，第一个序列用来表示栈的压入顺序，请判断第二个序列是否为该栈的弹出序列。
 假设 压入栈的所有数字均不相等。
 例如 序列{1,2,3,4,5} 是某栈的压栈序列，序列{4,5,3,2,1} 是该压栈序列对应的一个弹出序列
 但 {4,3,5,1,2} 就不是该压栈序列的弹出序列
 **/

#include <iostream>
#include <stack>


bool IsPopOrderStack(const int *pPush,const int *pPop, int nLength) {
    
    bool bPossible = false;
    //边界条件的判断
    if (pPush != nullptr && pPop != nullptr && nLength > 0) {
        // 一个是压栈的顺序 一个是出栈的顺序
        const int *pNextPush = pPush;
        const int *pNextPop = pPop;
        
        //初始化一个空的数据栈
        std::stack<int> stackData;
        
        //一直到所有要pop的数据全部pop出来 如果是正确的序列 那么最终pNextPop 为空
        while (pNextPop - pPop < nLength) {
            //默认是开始压栈 一直到 处于第一个要出栈的元素 入栈
            while (stackData.empty() || stackData.top()!= *pNextPop) {
                
                if (pNextPush - pPush == nLength) {
                    break;
                }
                
                stackData.push(*pNextPush);
                
                pNextPush++;
            }
            
            //如果当前数据栈的栈顶元素不等于要pNextPop的
            if (stackData.top() != *pNextPop) {
                break;
            }
            
            //如果遇到值相同的 立即出栈 并 开始判断下一个要出栈的元素
            stackData.pop();
            pNextPop++;
            
        }
        
        //到最后 如果数据栈为空 切出栈序列也已经遍历完了 就说明是一个正确的出栈序列
        if (stackData.empty() && pNextPop-pPop == nLength) {
            bPossible = true;
        }
    }
    
    return bPossible;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {3, 5, 4, 2, 1};
    
    if (IsPopOrderStack(push, pop, nLength)) {
        printf("是一个合理的顺序");
    } else {
        printf("这不是一个合理的顺序");
    }
    return 0;
}
