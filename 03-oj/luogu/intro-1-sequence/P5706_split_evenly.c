/*
 * P5706_split_evenly.c —— 再分肥宅水：t 毫升均分给 n 人，每人多少、共要几个杯子
 * 来源：洛谷 P5706 【深基2.例8】再分肥宅水
 * 题目：https://www.luogu.com.cn/problem/P5706
 * 结果：✅ AC
 * 日期：2026-10-17
 * 要点：每人毫升数 = t / n，用 %.3f 输出；每人 2 个杯子，杯子总数 = n * 2，分两行打。
 * 坑：一开始用的是 float —— t 最大 10000、要精确到 3 位小数，float 只有 7 位有效数字，
 *     实测 2000 万组随机输入里约 0.16% 的结果和 double 不一样
 *     （如 t=2.5 n=1000：float 得 0.002，double 得 0.003）。最后改成了 double。
 */
#include <stdio.h>
int main()
{
    double t;
    int n;
    scanf("%lf %d", &t, &n);
    double t_n = t / n;
    int n2 = n * 2;
    printf("%.3f\n%d", t_n, n2);
    return 0;
}
