/*
 * 3.01_divisible_by_357.c —— 输出 n 能被 3、5、7 中的哪几个整除，都不能就输出 n
 * 来源：PTA 实验3 第 1 题
 * 日期：2026-11-24
 * 思路：1) 三个条件互不影响（105 同时被 3、5、7 整除），所以不能用 if / else if 串起来，
 *          必须是三个独立的 if，各自判断、各自输出。
 *       2) 输出要求「数字之间一个空格、末尾不能多空格」，所以需要一个 first 标记：
 *          第一次输出前不加空格，之后的都在前面补一个空格。
 * 要点：多条件全部可能成立时用「并列 if」，互斥时才用 else if。
 *       分隔符的通用写法：先判断「是不是第一个」，而不是「是不是最后一个」。
 * 坑：字符串末尾多一个空格在 PTA 上是 WA，肉眼又完全看不出来。
 */
#include <stdio.h>
int main()
{

    int n;
    if (scanf("%d", &n) != 1)
        return 1;
    int first = 1;
    if (n % 3 == 0)
    {
        printf("3");
        first = 0;
    }
    if (n % 5 == 0)
    {
        if (!first)
            printf(" ");
        printf("5");
        first = 0;
    }
    if (n % 7 == 0)
    {
        if (!first)
            printf(" ");
        printf("7");
        first = 0;
    }
    if (first == 1)
        printf("n");
    return 0;
}
