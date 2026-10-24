/*
 * L1-002_print_hourglass.c —— 打印沙漏：用 n 个符号摆最大的沙漏，最后输出剩几个
 * 来源：PTA 团体程序设计天梯赛-练习集 L1-002 打印沙漏
 * 题目：pintia.cn → 题目集「团体程序设计天梯赛-练习集」→ L1-002
 * 日期：2026-10-24
 * 要点：沙漏用掉的符号总数是 2k²-1，所以先由 n 反推层数 k = (int)sqrt((n + 1) / 2.0)，
 *       再算 used = 2 * k * k - 1、remaining = n - used。
 *       上半 k-1 行：第 i 行前面 i 个空格、2(k-i)-1 个符号；
 *       下半 k 行：第 i 行前面 k-1-i 个空格、2i+1 个符号（中间那一个符号归下半第一行）。
 * 坑：原来写成 if (remaining != 0) { printf("%d", remaining); }，
 *     但题目「最后在一行中输出剩下没用掉的符号数」是无条件的，剩余为 0 也要打 0。
 *     符号刚好用完的 n 是 2k²-1 这一串：1 7 17 31 49 71 97 127 161 199 241 287
 *     337 391 449 511 577 647 721 799 881 967，一共 22 个，只有这些会挂。
 *     自己脑补的「0 没什么好输出」不成立 —— 题目说要输出就得输出。
 */
#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    char c;
    if (scanf("%d %c", &n, &c) != 2)
        return 0;
    int k = (int)sqrt((n + 1) / 2.0);
    int used = 2 * k * k - 1;
    int remaining = n - used;
    for (int i = 0; i < k - 1; i++)
    {
        for (int m = 0; m < i; m++)
        {
            printf(" ");
        }
        for (int j = 0; j < 2 * (k - i) - 1; j++)
        {
            printf("%c", c);
        }
        printf("\n");
    }
    for (int i = 0; i < k; i++)
    {
        for (int m = 0; m < k - 1 - i; m++)
        {
            printf(" ");
        }
        for (int j = 0; j < 2 * i + 1; j++)
        {
            printf("%c", c);
        }
        printf("\n");
    }

    printf("%d", remaining);
    return 0;
}
