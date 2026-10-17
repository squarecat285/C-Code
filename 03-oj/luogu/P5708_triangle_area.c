/*
 * P5708_triangle_area.c —— 三角形面积：海伦公式，保留 1 位小数
 * 来源：洛谷 P5708 【深基2.习2】三角形面积
 * 题目：https://www.luogu.com.cn/problem/P5708
 * 结果：⬜ 待提交
 * 日期：2026-10-17
 * 要点：p = (a + b + c) / 2，面积 = sqrt(p * (p - a) * (p - b) * (p - c))，用 %.1f 输出。
 * 坑：1) 一开始用 float，精度不够 —— 边长最大 1000，面积能到 43 万，
 *        float 只有 7 位有效数字，换成 double 才对；
 *     2) 数学里 p(p-a)(p-b)(p-c) 可以连着写，C 里必须每个都补 *：
 *        p*(p-a)*(p-b)*(p-c)，只写相邻括号编译不过。
 */
#include <stdio.h>
#include <math.h>
int main()
{
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    double p = (a + b + c) / 2.0;
    double area = sqrt(p * (p - a) * (p - b) * (p - c));
    printf("%.1f", area);
    return 0;
}
