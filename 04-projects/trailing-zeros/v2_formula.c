/*
 * v2_formula.c —— 求 n! 末尾有多少个连续的 0（公式版：直接累加 n/5 + n/25 + …）
 * 来源：自己想做的（n! 末尾零的个数）
 * 日期：2026-10-16
 * 要点：至少含 1 个 5 的数有 n/5 个，至少含 2 个 5 的有 n/25 个……
 *       逐层累加，正好把每个数的 5 因子个数数全，不用真的遍历 1~n；
 *       n /= 5 让 n 一步步缩到 0，循环自然结束，只要 O(log₅ n) 次；
 *       和 v1_loop.c 的结果逐个对拍完全一致
 */

#include <stdio.h>
int main()
{
    int n, count = 0;
    if (scanf("%d", &n) != 1)
    {
        printf("输入无效\n");
        return 1;
    }

    while (n > 0)
    {
        count += n / 5;
        n /= 5;
    }
    printf("末尾连续 0 的个数:%d\n", count);
    return 0;
}
