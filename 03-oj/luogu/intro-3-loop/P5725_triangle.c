/*
 * P5725_triangle.c —— 求三角形：先打 n×n 方阵（01..n²），空一行，再打右对齐三角形
 * 来源：洛谷 P5725 【深基4.习8】求三角形
 * 题目：https://www.luogu.com.cn/problem/P5725
 * 日期：2026-10-31
 * 思路：1) 两个图形都是 n 行、数字顺次递增，所以不用数组，只要一个不归零的编号。
 *       2) 方阵：第 i 行（从 0 数）的第 j 个数字正好是 i * n + j，
 *          所以内层直接从 1 + i*n 数到 n + i*n，连编号变量都省了。
 *       3) 三角形：第 i 行前面要空出 (n - i) 个数位。每个数占两格（%02d），
 *          所以空格是 2 * (n - i) 个 —— 用 while 数够就停。
 *       4) 三角形的编号跨行连续，所以另开一个 count 往下加，不要在每行重置。
 *       5) 两个图形中间空一行：方阵打完再单独打一个换行就是。
 * 要点：%02d 是「至少两位、不够补 0」，正好让 1..81 宽度统一，对齐才不歪。
 * 坑：缩进要是按「n - i 个空格」算（而不是 2*(n-i)），三角形会整体往左挤；
 *     编号要是按行内下标算，就会出现 01 02 03 / 01 02 03 这种每行重置的错。
 * 建议：`{int k=i;` 把左花括号和声明挤在一行，clang-format 一下会自动分开；
 *       while 数空格也能写成 for (int k = i; k < n - 1; k++)，少一行、少一个变量。
 */
#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 1 + i * n; j <= n + i * n; j++)
        {
            printf("%02d", j);
        }
        printf("\n");
    }
    printf("\n");
    int count = 1;
    for (int i = 0; i < n; i++)
    {int k=i;
        while (k < n-1)
        {
            printf("  ");
            k = k + 1;
        }
        for (int j = 0; j < i + 1; j++)
        {
            printf("%02d", count);
            count++;
        }
        printf("\n");
    }
    return 0;
}
