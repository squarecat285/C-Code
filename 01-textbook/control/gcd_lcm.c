/*
 * gcd_lcm.c —— 求两个正整数的最大公约数和最小公倍数
 * 来源：《C程序设计》第五章 习题 3（原 01-textbook/3/3.c）
 * 日期：2026-10-27
 * 要点：辗转相除法求 gcd —— gcd(a,b) = gcd(b, a%b)，余数到 0 为止，此时的 a 就是答案。
 *       temp 那三行不能省：算出 a % b 之后 b 已经被覆盖了，得先把旧 b 存住。
 *       最小公倍数用 lcm = a / gcd * b，**先除后乘**。写成 a * b / gcd 在 a、b 大时
 *       会先溢出（比如 1000 × 1000 就超出 int 的一半了），先除能压到最小。
 * 坑：输入 0 和 0 会除零崩溃（gcd 返回 0，lcm 里 a / temp 就炸了）。
 *     题目说「两个正整数」，所以碰不到；真要稳一点，可以在 main 里先拦一下 m <= 0 || n <= 0。
 * 建议：gcd 用递归写只有三行 —— return b == 0 ? a : gcd(b, a % b);
 *       和这题一模一样的辗转相除法，之前 P1888 也用过，可以对照着看。
 */
#include <stdio.h>
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int lcm(int a, int b)
{
    int temp = gcd(a, b);
    a = a / temp * b;
    return a;
}
int main()
{
    int m, n;
    printf("请输入两个正整数:\n");
    scanf("%d %d", &m, &n);
    int gcd_ = gcd(m, n);
    int lcm_ = lcm(m, n);
    printf("最大公约数是:%d\n", gcd_);
    printf("最小公倍数是:%d", lcm_);
    return 0;
}
