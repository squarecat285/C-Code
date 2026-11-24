/*
 * 3.16_day_of_year.c —— 输入日期，输出这一天是这一年的第几天
 * 来源：PTA 实验3 第 16 题
 * 日期：2026-11-24
 * 思路：1) 「是第几天」= 前面整月的天数之和 + 当月已经过的天数。
 *       2) 每月天数几乎固定，只有 2 月要看闰年 —— 所以先把 12 个数字打表，
 *          再按闰年把 m[2] 改成 29 或 28。
 *       3) 求和就是一次前缀累加，循环到 month - 1 为止。
 * 要点：用数组下标当月数，`scanf("%d/%d/%d")` 里的 `/` 会原样匹配输入中的斜杠。
 * 坑：把 m[2] 写对了，但很容易顺手把 12 个月手打一遍 —— 那样改一次闰年规则要动两处。
 */
#include <stdio.h>
int main()
{
    int year, month, day;
    if (scanf("%d/%d/%d", &year, &month, &day) != 3)
        return 1;
    int m[13] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        m[2] = 29;
    else
        m[2] = 28;
    int day_all = 0;
    for (int i = 1; i < month; i++)
    {
        day_all += m[i];
    }
    day_all += day;
    printf("%d", day_all);
    return 0;
}
