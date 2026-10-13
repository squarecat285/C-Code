/*
 * factorial.c —— 用 while 求 1×2×3×4×5
 * 来源：《C程序设计》第 18 页 第 1 题（原 TWO/18P_E1.c）
 * 日期：2026-10-11
 * 要点：累乘变量必须初始化为 1（累加才是 0）
 */

#include<stdio.h>
int main() {
    int i,t;

    i=1;
    t=i;
    while(i<5) {
        i=i+1;
        t=t*i;
    }
    printf("%d\n",t);
    return 0;
}
