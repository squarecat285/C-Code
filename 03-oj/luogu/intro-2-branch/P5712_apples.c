/*
 * P5712_apples.c —— Apples：按苹果个数选单数 apple / 复数 apples 造句
 * 来源：洛谷 P5712 【深基3.例4】Apples
 * 题目：https://www.luogu.com.cn/problem/P5712
 * 结果：⬜ 待提交（本地 0~100 全对）
 * 日期：2026-10-20
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
