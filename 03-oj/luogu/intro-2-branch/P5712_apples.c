/*
 * P5712_apples.c —— Apples：按苹果个数选单数 apple / 复数 apples 造句
 * 来源：洛谷 P5712 【深基3.例4】Apples
 * 题目：https://www.luogu.com.cn/problem/P5712
 * 日期：2026-10-20
 * 思路：1) 这是道「造句」题，难点全在格式：逗号、句号、单复数一个都不能错。
 *       2) 单复数规则：0 和 1 都用 apple，2 及以上才加 s ——
 *          注意 0 也是单数，这是最容易写错的一处。
 *       3) 「0/1 特殊、其余通用」用 switch 把两个特例挑出来，
 *          剩下的 if (a > 1) 统一处理，比一长串 if-else 清楚。
 * 要点：0 和 1 都用单数 apple，2 及以上才加 s。句式固定：
 *       "Today, I ate %d apple(s)." 注意 Today 后面有逗号、句末有句号。
 * 坑：0 个苹果容易顺手写成 apples —— 题目原文是「把 1 换成 0」，
 *     所以标准答案是 "Today, I ate 0 apple."（单数）。
 */
#include <stdio.h>
int main()
{
    int a;
    scanf("%d", &a);
    switch (a)
    {
    case 1:

        printf("Today, I ate 1 apple.");
        break;
    case 0:
        printf("Today, I ate 0 apple.");
        break;
    }
    if (a > 1)
    {
        printf("Today, I ate %d apples.", a);
    }
    return 0;
}
