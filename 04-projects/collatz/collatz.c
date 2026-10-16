/*
 * collatz.c —— Collatz（3n+1）猜想：统计一个数要多少步才变回 1
 * 来源：自己想做的（Collatz 猜想，又叫 3n+1 问题 / 冰雹序列）
 * 日期：2026-10-15
 * 要点：偶数除 2、奇数乘 3 加 1，交替推进直到 1；大数用 long long 配 %lld；
 *       奇偶分支用 else 兜底（C 里负数取模跟着被除数走，不能写 a % 2 == 1）
 */

#include <stdio.h>
int main()
{
    long long a;
    int count = 0;

    if (scanf("%lld", &a) != 1)
    {
        printf("输入无效\n");
        return 1;
    }
    if (a < 1)
    {
        printf("输入无效\n");
        return 1;
    }
    while (a != 1)
    {
        if (a % 2 == 0)
        {
            a = a / 2;
        }
        else
        {
            a = a * 3 + 1;
        }
        count++;
    }
    printf("%d\n", count);
    return 0;
}
