/*
 * growth_rate.c —— 年增长率 7%，算 10 年后比现在增长多少百分比
 * 来源：《C程序设计》第三章 课后习题 · 国民生产总值的增长
 * 日期：2026-10-18
 * 要点：(1 + r)^n 算出来是「是原来的几倍」，题目问的是「增长了多少」，所以要减 1；
 *       比值再乘 100 才是百分比；printf 里打一个百分号要写成 %%
 */
#include <stdio.h>
#include <math.h>
int main()
{
    double r = 0.07;
    int n = 10;
    double p = pow(1 + r, n);
    printf("%.2f%%", (p-1)*100);
    return 0;
}
