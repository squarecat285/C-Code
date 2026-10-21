/*
 * P5716_month_days.c —— 月份天数：给年份和月份，输出那个月有几天
 * 来源：洛谷 P5716 【深基3.例9】月份天数
 * 题目：https://www.luogu.com.cn/problem/P5716
 * 日期：2026-10-21
 * 要点：switch 把「31 天的月份」和「30 天的月份」分成两组，同一组里 case 不写 break
 *       就会往下穿透、共用一段代码。2 月不在 switch 里，单独判断：闰年 29 天，平年 28 天，
 *       闰年判定和 P5711 完全一样。
 * 坑：case 后面写成 case (1): 带括号是合法的（case 后面只要是常量表达式就行），
 *     多余但无害；看不顺眼可以去掉括号。
 */
#include <stdio.h>
int main()
{
    int y, m;
    scanf("%d %d", &y, &m);
    switch (m)
    {
    case (1):
    case (3):
    case (5):
    case (7):
    case (8):
    case (10):
    case (12):
        printf("31");
        break;
    case (4):
    case (6):
    case (9):
    case (11):
        printf("30");
        break;
    }
    if (m == 2)
    {
        if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
        {
            printf("29");
        }
        else
        {
            printf("28");
        }
    }
    return 0;
}
