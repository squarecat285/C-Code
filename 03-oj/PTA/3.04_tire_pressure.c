/*
 * 3.04_tire_pressure.c —— 胎压监测：4 个胎压 + 最低胎压 + 差值阈值，判断要不要报警
 * 来源：PTA 实验3 第 4 题
 * 日期：2026-11-24
 * 思路：1) 一个轮胎「有问题」有两个来源：本身低于最低胎压，或者比最高的那个低太多。
 *          第二种要先知道谁最高，所以得先扫一遍求 max，再扫一遍比差值。
 *       2) 题目要的三种结论（正常 / 恰好一个 / 两个以上）取决于「有问题」的个数，
 *          所以用 y[] 做标记、用 first 计数，数到 2 就可以直接给「全都要检查」。
 * 要点：两轮扫描 —— 第一轮定基准（max），第二轮比较。和 P1047、P2550 的「先标记再统计」同一套路。
 * 坑：`first` 实际是「坏轮胎个数」，名字读不出来；两个「全部检查」分支的代码一模一样，可以合并。
 * 建议：把两轮判断合并成「先标记，循环结束后统一按个数分三支输出」，代码能短一半。
 */
#include <stdio.h>
int main()
{
    int x[5] = {0};
    int min_limit, range;
    int y[5] = {0};
    if (scanf("%d %d %d %d %d %d", &x[1], &x[2], &x[3], &x[4], &min_limit, &range) != 6)
        return 1;
    int first = 0;
    for (int i = 1; i <= 4; i++)
    {
        if (x[i] - min_limit < 0)
        {
            first++;
            y[i] = 1;
        }
        if (first == 2)
        {
            printf("Warning: please check all the tires!");
            return 0;
        }
    }
    int max_ = x[1];
    for (int j = 2; j <= 4; j++)
    {
        if (max_ < x[j])
            max_ = x[j];
    }

    for (int i = 1; i <= 4; i++)
    {
        if (max_ - x[i] > range)
        {
            if (y[i] == 1)
                continue;

            first++;
            y[i] = 1;
        }
        if (first == 2)
        {
            printf("Warning: please check all the tires!");
            return 0;
        }
    }

    for (int j = 1; j <= 4; j++)
    {
        if (y[j] == 1)
        {
            printf("Warning: please check #%d!", j);
            return 0;
        }
    }
    printf("Normal");
    return 0;
}
