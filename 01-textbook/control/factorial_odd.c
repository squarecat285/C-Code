/*
 * factorial_odd.c —— 求 1×3×5×7×9×11
 * 来源：《C程序设计》第 18 页 第 2 题（原 TWO/18P_E2.c）
 * 日期：2026-10-11
 * 要点：while(1) 配合 break 的写法
 */

#include<stdio.h>
int main() {
    int i,t;

    i=1;
    t=i;
    while (1) {
        i=i+2;
        t=t*i;
        if(i>=11) {
            break;
        }
    }
    printf("%d\n",t);
    return 0;
}
