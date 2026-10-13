/*
 * prime_check.c —— 判断一个数是否为素数
 * 来源：《C程序设计》第 21 页 第 5 题（原 TWO/21P_E5.c）
 * 日期：2026-10-13
 * 要点：用 i*i<=n 代替 i<=n 减少循环次数；注意 n<=1 的边界（已修正）
 */

#include<stdio.h>
int main() {
    int n,i;
    int isPrime=1;
     printf("请输入n的值:");
     scanf("%d",&n);

     if(n<=1) {
        isPrime=0;
     } else {
        for(i=2;i*i<=n;i++) {
            if(n%i==0) {
                isPrime=0;
                break;
            }
        }
     } if(isPrime==1) {
        printf("%d是素数",n);
     } else {
        printf("%d不是素数",n);
     }
     return 0;

}
