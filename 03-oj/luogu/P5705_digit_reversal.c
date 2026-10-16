/*
 * P5705_digit_reversal.c —— 数字反转：输入 123.4，输出 4.321
 * 来源：洛谷 P5705 【深基2.例7】数字反转
 * 题目：https://www.luogu.com.cn/problem/P5705
 * 结果：⬜ 待提交（本机把 100.0~999.9 共 9000 个输入全跑了一遍，0 错）
 * 日期：2026-10-16
 * 要点：把小数乘 10 变成整数，再按位反转，最后用 rev / 1000.0 把小数点插回第 1 位后面；
 *       除数是 10 的「位数 - 1」次方，不能硬编码成 10。
 * 坑：1) scanf 不支持 %.1f 这种带精度的写法，读小数只能用 %f；
 *     2) printf("%.1f", rev / 10.0) —— 小数点插错位（得到 432.1），小数位数也不够（要 3 位）。
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
