/*
 * max_of_three.c —— 求三个整数中的最大值
 * 来源：《C程序设计》第 14 页 第 6 题（原 ONE/14P_6.c）
 * 日期：2026-10-11
 * 要点：if 依次比较；不能写成 a>b>c
 */

#include<stdio.h>
int main() {
    int a,b,c,max;
    printf("请输入三个整数 :\n");
    scanf("%d %d %d",&a,&b,&c);
    max=a;
    if(b>max) {
        max=b;
    }
    if(c>max) {
        max=c;
    }
    printf("最大值是:%d\n",max);
    return 0;
}
