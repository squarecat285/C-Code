/*
 * P5714_fat_problem.c —— 肥胖问题：按 BMI 判断体型，肥胖时还要先打出 BMI
 * 来源：洛谷 P5714 【深基3.例7】肥胖问题
 * 题目：https://www.luogu.com.cn/problem/P5714
 * 日期：2026-10-21
 * 要点：BMI = m / (h * h)。m、h 都用 double 读，五个区间是
 *       BMI < 18.5 → Underweight，18.5 ≤ BMI < 24 → Normal，否则先打 BMI 再打 Overweight。
 * 坑：题目说「不是保留六位小数」，要的是 6 位有效数字 → 用 %.6g，不是 %.6f。
 *     %.6g 还会自动抹掉尾随的 0，80 1.75 输出 26.1224，不是 26.122400。
 */
#include <stdio.h>
int main()
{
    double m, h;
    scanf("%lf %lf", &m, &h);
    double BMI = m / (h * h);
    if (BMI < 18.5)
    {
        printf("Underweight");
    }
    else if (BMI >= 18.5 && BMI < 24)
    {
        printf("Normal");
    }
    else
    {
        printf("%.6g\nOverweight", BMI);
    }
    return 0;
}
