/*
 * P5713_team_system.c —— 洛谷团队系统：本地每题 5 分钟 vs 团队 3 分钟 + 一次性 11 分钟
 * 来源：洛谷 P5713 【深基3.例5】洛谷团队系统
 * 题目：https://www.luogu.com.cn/problem/P5713
 * 日期：2026-10-20
 * 思路：1) 两种方案的时间都是 n 的一次式：本地 5n，团队 3n + 11。
 *       2) 谁更快就是比这两个数谁小 —— 相减得 2n − 11，n ≤ 5 本地赢，n ≥ 6 团队赢。
 *       3) 题目规定「本地短才输出 Local，否则 Luogu」，也就是平局归团队，
 *          所以判断是「本地 > 团队」而不是 >=。
 *       4) 比较结果本身只有 0/1，先存成变量再分支，读起来更直白。
 * 要点：本地 5n，团队 3n+11，两边相减得 2n-11：
 *       n = 5 时 25 < 26 本地省，n = 6 时 30 > 29 团队省。
 *       题目说「本地短输出 Local，否则输出 Luogu」——平局要归 Luogu。
 * 坑：if (min = 1) 少了一个 = 变成赋值，条件恒为真，永远输出 Luogu。
 *     gcc 其实警告过：suggest parentheses around assignment used as truth value。
 */
#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int min = ((5 * n) > (3 * n + 11)) ? 1 : 0;
    if (min == 1)
    {
        printf("Luogu");
    }
    else
    {
        printf("Local");
    }
    return 0;
}
