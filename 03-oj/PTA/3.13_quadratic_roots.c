/*
 * 3.13_quadratic_roots.c —— 求一元二次方程的根，含退化情况
 * 来源：PTA 实验3 第 13 题
 * 日期：2026-11-24
 * 思路：1) 别一上来就套求根公式 —— 方程的「次数」是不确定的，必须按次数先分类：
 *          a == 0 && b == 0：c 也是 0 就是 Zero Equation，否则 Not An Equation；
 *          a == 0 && b != 0：退化成一元一次方程 x = -c / b；
 *          否则才是一元二次，再按 delta 分三支。
 *       2) delta > 0 时两个根要先大后小，而 a < 0 时除以 2a 会把顺序翻过来，
 *          所以算完必须比一次、必要时交换。
 *       3) delta < 0 时虚部取绝对值，保证先打「+」后打「-」。
 *       4) gcc 会把 -0.002 打印成 -0.00，所以每个根本打出去之前都用 fabs(x) < 0.005 归零。
 * 要点：分类要穷尽、要按「次数」先分，别把 a == 0 和 a == 0 && b == 0 当同一件事。
 * 坑：1) 归零那段写成了 `if (fabs(x2) < 0.005) x1 = 0.00;` —— 判的是 x2、改的是 x1。
 *          输入 `1 -3 0`（两个根是 3 和 0）时输出 `0.00 / 0.00`，把 3 给吃掉了。
 *       2) `printf(c == 0 ? "Zero Equation" : "Not An Equation")` —— 拿变量当格式串，
 *          这次没有 % 所以碰巧没事，但格式串应该写死、内容当参数传。
 */
#include <stdio.h>
#include <math.h>
int main()
{
    double a, b, c;
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3)
    {
        return 1;
    }

    if (a == 0 && b == 0)
    {
        printf("%s", c == 0 ? "Zero Equation" : "Not An Equation");
        return 0;
    }
    if (a == 0)
    {
        printf("%.2f", -c / b);
        return 0;
    }
    double delta = b * b - 4 * a * c;
    if (delta > 0)
    {
        double x1 = (-b + pow(delta, 0.5)) / (2 * a);

        double x2 = (-b - pow(delta, 0.5)) / (2 * a);
        if (x1 < x2)
        {
            double t = x1;
            x1 = x2;
            x2 = t;
        }
        if (fabs(x1) < 0.005)
            x1 = 0.00;
        if (fabs(x2) < 0.005)
            x2 = 0.00;

        printf("%.2f\n%.2f", x1, x2);
    }
    else if (delta == 0)
    {
        double x = -b / (2 * a);
        if (fabs(x) < 0.005)
            x = 0.00;
        printf("%.2f", x);
    }
    else
    {
        double real = -b / (2 * a);
        double imaginary = pow(-delta, 0.5) / (2 * a);
        if (imaginary < 0)
            imaginary = -imaginary;
        if (fabs(real) < 0.005)
            real = 0.00;
        printf("%.2f+%.2fi\n%.2f-%.2fi", real, imaginary, real, imaginary);
    }
    return 0;
}
