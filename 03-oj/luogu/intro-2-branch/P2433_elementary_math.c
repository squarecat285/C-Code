/*
 * P2433_elementary_math.c —— 小学数学 N 合一：读入题号 T，输出那一小题的答案
 * 来源：洛谷 P2433 【深基1-2】小学数学 N 合一
 * 题目：https://www.luogu.com.cn/problem/P2433
 * 日期：2026-10-19
 * 思路：1) 这是一张卷子，不是一道题：读题号 T，只答那一小题。
 *          「按题号分支」最贴切的结构就是 switch。
 *       2) 每个 case 里都要声明变量 —— 而整个 switch 的大括号只算一个作用域，
 *          不额外加括号的话 14 个分支的变量会挤在同一层、互相重定义，编译直接失败。
 *          所以每个 case 都用 { } 自己围一圈。
 *       3) 不会的几题先「降级」处理：能算就算（面积、追及、倒推），
 *          算不了的就用公式硬解（评测机解方程、最大正方体开三次方）。
 *       4) 输出要求「6 位有效数字」= C++ 的 cout 默认 = C 的 %g。
 * 要点：这不是一道题，是 14 道小题装进一个程序。读入 T，只回答第 T 小题。
 *       输出格式一律用 %g —— 它和 C++ 的 cout 默认一样，都是 6 位有效数字，
 *       题目说「保留 6 位有效数字」「直接使用 cout 输出」的，C 里就是 %g。
 *       每个 case 用 { } 包起来：switch 的大括号是一整个作用域，
 *       不包的话 14 个分支里的变量会互相撞名。
 * 坑：1) 没给 case 加大括号，14 个分支共用一个作用域，
 *       a / b / r / pi 全部重定义，编译直接过不去。
 *    2) 第 6 题写 int c = sqrt(...)，10.8166 被砍成 10 —— 算出来是小数就别用 int 接。
 *    3) 第 11 题是追及不是相遇，用了速度和 100/(5+8)，应 100/(8-5)。
 *    4) 第 12 题写 char 'A', 'M'; —— char 后面只能跟变量名，'A' 是常量；
 *       而且 A、M 没赋值就用，读到内存垃圾。
 *    5) 第 14 题写 110.0 - (p1 < p2) ? p1 : p2：?: 优先级比 - 低，
 *       被算成 (110.0-(p1<p2)) ? p1 : p2；而且 p1、p2 是「降了多少」不是定价，
 *       要取降得多的那个再 110 - x。嵌套 ?: 一律拆成两句。
 */
#include <stdio.h>
#include <math.h>

int main()
{
    int T;
    scanf("%d", &T);
    switch (T)
    {
    case 1:
    {
        printf("I love Luogu!");
        break;
    }
    case 2:
    {
        printf("%d %d", 6, 4);
        /* 两个数，用空格隔开：一共拿走几个 / 小B拿走几个 */
        break;
    }
    case 3:
    {
        int a = 14, b = 4;
        int e = a / b;
        printf("%d\n%d\n%d", e, 4 * e, 14 - 4 * e);
        /* 三个数，每个一行：每人分几个 / 一共分出去几个 / 放回冰箱几个 */
        break;
    }
    case 4:
    {
        double a = 500.0;
        printf("%g", a / 3.0);
        /* 一个数，保留 6 位有效数字，不要科学计数法 */
        break;
    }
    case 5:
    {
        int s = 260 + 220, v = 12 + 20;
        printf("%d", s / v);
        /* 一个整数（秒）。相对速度 + 车身要全部错开 */
        break;
    }
    case 6:
    {
        double c = sqrt(6 * 6 + 9 * 9);
        printf("%g", c);
        /* 一个数，6 位有效数字（C++ 用 cout，C 用 %g） */
        break;
    }
    case 7:
    {
        printf("%d\n%d\n%d", 100 + 10, 100 + 10 - 20, 0);
        /* 三个数，每个一行：每次操作后的余额 */
        break;
    }
    case 8:
    {
        int r = 5;
        double pi = 3.141593;
        printf("%g\n%g\n%g", 2 * pi * r, pi * r * r, 4 * pi * r * r * r / 3.0);
        /* 三个数，每个一行：周长 / 面积 / 球体积，pi 取 3.141593，%g */
        break;
    }
    case 9:
    {
        int a = 1;
        for (int i = 0; i < 3; i++)
        {
            a = (a + 1) * 2;
        }
        printf("%d\n", a);
        /* 整数：猴子买来时的桃子数。从第四天倒着推 */
        break;
    }
    case 10:
    {
        double n1 = 8.0, t1 = 30.0;
        double n2 = 10.0, t2 = 6.0;
        double r = (n1 * t1 - n2 * t2) / (t1 - t2);
        double a = n1 * t1 - t1 * r;
        double t3 = 10.0;
        double n3 = a / t3 + r;
        printf("%g", n3);
        /* 一个整数：几台评测机。这是道「牛吃草」 */
        break;
    }
    case 11:
    {
        double v1 = 5.0, v2 = 8.0;
        double t = 100.0 / (v2 - v1);   /* 追及用速度差，不是速度和 */
        printf("%g", t);
        /* 一个数：追上要几秒，6 位有效数字 */
        break;
    }
    case 12:
    {
        char a = 'M' - 'A' + 1, b = 'A' + 18 - 1;
        printf("%d\n%c", a, b);
        /* 一个数字，换行，一个大写字母 */
        break;
    }
    case 13:
    {
        double pi = 3.141593, r1 = 4.0, r2 = 10.0;
        double v = 4 * pi * (pow(r1, 3) + pow(r2, 3)) / 3;
        int l = (int)(pow(v, 1.0 / 3.0) + 1e-9);
        printf("%d", l);
        /* 一个整数：正方体棱长，结果不是整数就舍掉小数 */
        break;
    }
    case 14:
    {
        double d = (-100.0) * (-100.0) - 4 * 1 * 2400.0;
        double s_d = sqrt(d);
        double p1 = (100.0 + s_d) / 2.0;
        double p2 = (100.0 - s_d) / 2.0;
        double x_big = (p1 > p2) ? p1 : p2;
        double p_m = 110.0 - x_big;
        printf("%.0f",p_m);
        break;
    }
    }
    return 0;
}
