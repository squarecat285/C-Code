/*
 * B2029_elephant_water.c —— 大象喝水：20 升水要喝几桶才够
 * 来源：洛谷 B2029 大象喝水
 * 题目：https://www.luogu.com.cn/problem/B2029
 * 日期：2026-10-17
 * 要点：桶的容积 v = 3.14 × r² × h（立方厘米），20 升 = 20000 立方厘米；
 *       除出来不是整数就得再喝一桶，所以是向上取整 ceil(20000.0 / v)；
 *       输入顺序是「先 h 后 r」，别按变量声明的顺序读。
 * 坑：1) 一开始写 (20000 + v - 1) / v，以为还是「向上取整」——
 *        那是整数除法的技巧，v 是 double 时就变成 floor(20000/v + 1 - 1/v)，
 *        只有小数部分 ≥ 1/v 才碰巧等于 ceil（如 v=9999.75，他算 2 应得 3）；
 *        题目范围内 50000 组刚好一个都没错，纯属运气。
 *     2) 这题最容易错的是 scanf 的顺序：先 h 后 r。
 */
#include <stdio.h>
#include <math.h>
int main()
{
    int r, h;
    scanf("%d %d", &h, &r);
    double v = 3.14 * r * r * h;
    int times = (int)ceil(20000.0 / v);
    printf("%d", times);
    return 0;
}
