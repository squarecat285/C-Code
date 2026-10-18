/*
 * circle.c —— 输入半径 r 和圆柱高 h，算圆周长、圆面积、球面积、球体积、圆柱体积
 * 来源：《C程序设计》第三章 课后习题 · 圆和圆柱的计算
 * 日期：2026-10-18
 * 要点：球体积是 4/3 · π · r³，必须写成 4.0 * pi * r * r * r / 3.0 ——
 *       写成 4/3 会被当成整数除法，结果是 1；输出用 %.2f 保两位小数
 * 坑：提示语要单独用 printf 打，scanf 的格式串里只放 %lf。
 *     把「请输入…」写进 scanf 的引号里，程序会拿它去和输入比对，就读不到数了
 */
#include <stdio.h>
int main()
{
    double r, h;
    double pi = 3.1415926;
    double c, s, bs, bv, cv;
    printf("请输入圆的半径r和圆柱的高h:");
    scanf("%lf %lf", &r, &h);
    c = 2.0 * pi * r;
    s = pi * r * r;
    bs = 4.0 * pi * r * r;
    bv = 4.0 * pi * r * r * r / 3.0;
    cv = pi * r * r * h;
    printf("\n=====计算结果=====\n");
    printf("圆周长  : %.2f\n", c);
    printf("圆面积  : %.2f\n", s);
    printf("球面积  : %.2f\n", bs);
    printf("球体积  : %.2f\n", bv);
    printf("圆柱体积: %.2f\n", cv);
    return 0;
}
