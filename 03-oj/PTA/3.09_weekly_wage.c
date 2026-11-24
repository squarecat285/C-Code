/*
 * 3.09_weekly_wage.c —— 按时薪和一周工时算周工资，超过 40 小时的部分按 1.5 倍
 * 来源：PTA 实验3 第 9 题
 * 日期：2026-11-24
 * 思路：1) 先定时薪：工龄满 5 年 50 元/小时，否则 30。
 *       2) 再定结构：前 40 小时按原价，超出的部分乘 1.5 ——
 *          所以是 `小时数 + 0.5 × 超出部分`，不必把两段分开算再相加。
 * 要点：加班费的写法 `40 + 1.5 * (week_time - 40)` 只对超出部分加价，别把 1.5 乘到全部工时上。
 * 建议：`hour_wage * week_time * 1.0` 里的 `* 1.0` 是为了转 double，写成 `(double)hour_wage * week_time` 意图更明确。
 */
#include <stdio.h>
int main()
{
    int work, week_time;
    if (scanf("%d %d", &work, &week_time) != 2)
        return 1;
    int hour_wage;
    if (work - 5 >= 0)
        hour_wage = 50;
    else
        hour_wage = 30;
    double week_wage;
    if (week_time > 40)
        week_wage = hour_wage * (40 + 1.5 * (week_time - 40));
    else
        week_wage = hour_wage * week_time * 1.0;
    printf("%.2f", week_wage);
    return 0;
}
