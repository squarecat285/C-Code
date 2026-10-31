/*
 * P1420_longest_run.c —— 最长连号：序列里最长的「连续自然数」子串有多长
 * 来源：洛谷 P1420 最长连号
 * 题目：https://www.luogu.com.cn/problem/P1420
 * 日期：2026-10-31
 * 思路：1) 连号只看相邻两个数差是不是 1，所以只要记住上一个数，用不着数组。
 *       2) 边读边判：s - a == 1 说明接得上，当前连号长度 +1；否则断了，长度回到 1。
 *       3) 边走边记最好成绩：每轮更新完 count，就和 count_max 比一次。
 *       4) 最短的连号是「一个数自己」，所以 count 和 count_max 的初值都是 1 ——
 *          n = 1 时循环一次不进，直接输出 1，正好对。
 * 要点：「断没断」和「破没破纪录」是两件独立的事，各写一个 if。
 *       千万别用一个 if/else 把它们串起来 —— 那等于说「没破纪录就清零」。
 * 坑：第一版把 count = 0 写进了「破纪录」那个 if 的 else 里，
 *     于是只要当前长度没超过历史最好，连号就被抹掉，第二个连号永远长不起来：
 *     `1 2 3 4 10 11 12` 输出 3（应 4）。另外 count 初值写成 0 还会让整体少 1，
 *     `1 2 3` 输出 2（应 3）、n = 1 输出 0（应 1）。
 * 建议：「最长连续段」是个通用套路：一个 cur 记当前长度、一个 best 记历史最好，
 *       cur 要么 +1 要么回到 1，每步 best = max(best, cur)。
 *       以后数最长同色段、最长递增段、最长连续相同字符，都是这个骨架。
 */
#include <stdio.h>
int main()
{
    int n;

    scanf("%d", &n);
    int a;
    scanf("%d", &a);
    int count = 1;
    int count_max = 1;
    for (int i = 1; i < n; i++)
    {
        int s;
        scanf("%d", &s);
        if (s - a == 1)
        {
            count++;
        }
        else
        {
            count = 1;
        }
        a = s;
        if (count > count_max)
        {
            count_max = count;
        }
    }
    printf("%d", count_max);
    return 0;
}
