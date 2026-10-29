/*
 * P1217_palindrome_prime.c —— 回文质数：输出 a..b 之间所有既是回文又是质数的数
 * 来源：洛谷 P1217 [USACO1.5] 回文质数 Prime Palindromes
 * 题目：https://www.luogu.com.cn/problem/P1217
 * 日期：2026-10-29
 * 思路：1) 第一版是「从 a 扫到 b，先判质数再判回文」—— 5 ≤ a < b ≤ 10^8，
 *          要试 5×10⁷ 个候选，本地实测跑到 10^8 要 55 秒，洛谷时限 1.2 秒，直接 TLE。
 *       2) 那就反过来：先造回文，再判质数。回文由「前半段」唯一决定 ——
 *          5 位回文 abcba，只要枚举 abc（100~999），后半段照镜子拼出来就行。
 *       3) 还能再砍一刀：偶数位的回文一定能被 11 整除
 *          （abba = 1001a + 110b = 11 × (91a + 10b)），
 *          所以除了 11 自己，2、4、6、8 位回文全是合数，只管奇数位。
 *       4) 于是候选只剩 9 + 90 + 900 + 9000 = 9999 个，再加 11。
 *          走 1、3、5、7 位四轮，天然从小到大，不用排序。
 *       5) 镜像是：v = p，再去掉最后一位 t = p / 10，倒着一位一位接上去。
 *          len = 1 时 t = p / 10 = 0，循环一次都不进，1~9 自动就对，不用特判。
 * 要点：b ≤ 10^8 但 8 位回文全是合数，所以 len 到 7 就够。
 *       11 是唯一的两位回文质数，生成法造不出来，要单独补一次；
 *       而且得夹在 1 位和 3 位之间，否则输出顺序不对。
 * 坑：1) 第一版 is_palindrome 里写 for (int i = 1; i < len / 2; i++)，
 *          起点写成 1，str[0] 永远没参与比较；len = 2 时 len / 2 = 1，
 *          循环体一次都不执行，于是所有两位质数都被当成回文 ——
 *          「5 500」输出 93 行，正确只有 12 行。
 *       2) 只修回文判断、不改算法，还是会 TLE：枚举 5×10⁷ 个数这个量级，
 *          1 秒的机器做不完，跟你写得快不快没关系。
 * 建议：is_prime 里 i <= sqrt(n) 每轮都在重算开方，换成 i * i <= n 更快；
 *       判掉 2 之后 i 从 3 开始、每次加 2，也能少一半循环。
 */
#include <stdio.h>
#include <stdbool.h>
bool is_prime(int n)
{
    if (n < 2)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    for (int len = 1; len <= 7; len += 2)
    {
        if (len == 3 && a <= 11 && b >= 11)
        {
            printf("11\n");
        }
        int half = (len + 1) / 2;
        int lo = 1;
        for (int k = 1; k < half; k++)
            lo *= 10;
        int hi = lo * 10 - 1;
        for (int p = lo; p <= hi; p++)
        {
            int v = p;
            int t = p / 10;
            while (t > 0)
            {
                v = v * 10 + t % 10;
                t /= 10;
            }
            if (v < a || v > b)
                continue;
            if (is_prime(v))
                printf("%d\n", v);
        }
    }
    return 0;
}
