/*
 * P5705_digit_reversal.c —— 数字反转：输入 123.4，输出 4.321
 * 来源：洛谷 P5705 【深基2.例7】数字反转
 * 题目：https://www.luogu.com.cn/problem/P5705
 * 结果：⬜ 待提交（本机把 100.0~999.9 共 9000 个输入全跑了一遍，0 错）
 * 日期：2026-10-16
 * 要点：scanf 不支持 %.1f 这种带精度的写法，读小数只能用 %f；
 *       先把 float 乘 10 变成整数 n，再按位反转得到 rev；
 *       最后用 rev / 1000.0 把小数点插回第 1 位后面 ——
 *       除数是 10 的「位数 - 1」次方，不能硬编码成 10（那样 4321/10 会得到 432.1）。
 */
#include <stdio.h>
int main()
{
    float a;
    scanf("%f", &a);
    int n = (int)(a * 10);
    int rev = 0;
    while (n != 0)
    {
        int digit = n % 10;
        rev = rev * 10 + digit;
        n /= 10;
    }
    printf("%.3f", rev / 1000.0);
    return 0;
}
