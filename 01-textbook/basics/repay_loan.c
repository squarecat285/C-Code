/*
 * repay_loan.c —— 贷款 d 元、每月还 p 元、月利率 r，算多少个月还清
 * 来源：《C程序设计》第三章 课后习题 · 购房贷款
 * 日期：2026-10-18
 * 要点：m = log(p / (p - d * r)) / log(1 + r)，C 没有「以几为底」的 log，
 *       只能换底；算式里只要有一个 double，整条式子就按 double 算，
 *       所以 int 型的 p、d 不用特意强转
 * 坑：算完又套了一层 round(m * 10) / 10 想手动保一位 —— 多余，
 *     printf 的 %.1f 本身就会四舍五入，直接打 m 就行
 */
#include <stdio.h>
#include <math.h>
int main()
{
    int d = 300000, p = 6000;
    double r = 0.01;
    double m = log(p / (p - d * r)) / log(1 + r);
    double m_1 = round(m * 10.0) / 10.0;
    printf("%.1f", m_1);
    return 0;
}
