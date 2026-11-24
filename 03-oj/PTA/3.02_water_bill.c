/*
 * 3.02_water_bill.c —— 阶梯水费：50 吨以内 0.53 元/吨，超出部分 0.58 元/吨
 * 来源：PTA 实验3 第 2 题
 * 日期：2026-11-24
 * 思路：1) 先把「不合理输入」挡掉：用水量不能为负，为负直接报 Invalid Value! 并结束。
 *       2) 然后按 50 分两段。关键是 n == 50 属于第一段，所以判断写成 n - 50 > 0 而不是 >= 0。
 * 要点：分段计费先把「临界点属于哪一段」定清楚，再写不等式。
 *       校验放在最前面 return，后面的代码就不用再操心非法输入。
 */
#include <stdio.h>
int main()
{
    double n;
    if (scanf("%lf", &n) != 1)
        return 1;
    if (n < 0)
    {
        printf("Invalid Value!");
        return 0;
    }
    double cost = 0;
    if (n - 50 > 0)
    {
        cost = cost + 50 * 0.53;
        n = n - 50;
        cost = cost + n * 0.58;
    }
    else
    {
        cost = n * 0.53;
    }
    printf("cost = %.2f", cost);
    return 0;
}
