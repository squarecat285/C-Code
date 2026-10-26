/*
 * P1009_factorial_sum.c —— 阶乘之和：S = 1! + 2! + ... + n!
 * 来源：洛谷 P1009 [NOIP 1998 普及组] 阶乘之和
 * 题目：https://www.luogu.com.cn/problem/P1009
 * 日期：2026-10-26
 * 要点：50! 有 65 位，long long 只有 19 位装不下，所以把「一个数」拆成一排 int，
 *       每格存一位，个位放 a[0]（低位在前），输出时倒着打印。
 *       mul：逐位乘 k，t % 10 留在这一格、t / 10 是进位；for 走完后还要用 while
 *            继续吐进位，因为进位可能不止一位（99 × 9 = 891，只写 if 就只剩 91）。
 *       add：按两者较长的位数走，短的那个高位当 0（三元运算符判 j < len）。
 *            carry 最多是 1（9 + 9 + 1 = 19），所以收尾用 if 就够，不用 while。
 *       数组作参数是「指针」，函数里改外面看得见；len 是「值拷贝」，改了外面看不见
 *       —— 所以数组不用返回，长度必须 return，lenF / lenA 每次都要接住返回值。
 * 坑：1) 忘了接返回值 lenF = mul(...)，长度永远停在 1，后面的数被截断
 *     2) mul 收尾写成 if 而不是 while，进位多于一位时丢最高位
 *     3) 数组开小了。n = 50 时 fact 最多 65 位、ans 最多 66 位，现在开 100 够用
 * 建议：先用 n = 20 验证（2561327494111820313，19 位，long long 刚好装得下），
 *       再去对 n = 50 的 65 位结果，一次就能看出高位有没有丢。
 */
#include <stdio.h>
int mul(int fact[], int len, int k)
{
    int carry = 0;

    for (int j = 0; j < len; j++)
    {
        int t = fact[j] * k + carry;
        fact[j] = t % 10;
        carry = t / 10;
    }

    while (carry > 0)
    {
        fact[len] = carry % 10;
        len++;
        carry = carry / 10;
    }
    return len;
}
int add(int ans[], int lenA, int fact[], int lenF)
{
    int carry = 0;
    int len = lenA > lenF ? lenA : lenF;

    for (int j = 0; j < len; j++)
    {
        int t = (j < lenA ? ans[j] : 0) + (j < lenF ? fact[j] : 0) + carry;
        ans[j] = t % 10;
        carry = t / 10;
    }

    if (carry > 0)
    {
        ans[len] = carry;
        len++;
    }
    return len;
}
int main()
{
    int n;

    scanf("%d", &n);

    int fact[100] = {0};
    int lenF = 1;
    fact[0] = 1;

    int ans[100] = {0};
    int lenA = 1;

    for (int i = 1; i <= n; i++)
    {
        lenF = mul(fact, lenF, i);
        lenA = add(ans, lenA, fact, lenF);
    }

    for (int j = lenA - 1; j >= 0; j--)
    {
        printf("%d", ans[j]);
    }
    printf("\n");

    return 0;
}
