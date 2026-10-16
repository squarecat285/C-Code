/*
 * trailing_zeros.c —— 求 n! 末尾有多少个连续的 0
 * 来源：自己想做的（n! 末尾零的个数）
 * 日期：2026-10-15
 * 要点：末尾每个 0 都要消耗一个因子 10 = 2×5，而 1~n 里 2 远比 5 多，
 *       所以只需数 5 的个数：把每个 i 反复 / 5 剥干净再累加；
 *       循环必须从 i = 1 开始——i = 0 时 0 % 5 == 0 永远成立，
 *       而 0 / 5 还是 0，内层 while 会永远转下去（就是当时卡死的原因）
 */

#include <stdio.h>
int main()
{
    int n, count = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int t = i;
        while (t % 5 == 0)
        {
            count++;
            t = t / 5;
        }
    }
    printf("%d", count);
    return 0;
}
