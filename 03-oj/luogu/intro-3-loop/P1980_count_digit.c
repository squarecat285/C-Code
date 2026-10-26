/*
 * P1980_count_digit.c —— 计数问题：1 到 n 之间，数字 x 一共出现了多少次
 * 来源：洛谷 P1980 [NOIP 2013 普及组] 计数问题
 * 题目：https://www.luogu.com.cn/problem/P1980
 * 日期：2026-10-26
 * 要点：逐个数的逐位拆。外层遍历 1~n，内层 temp % 10 取末位、temp / 10 去掉末位，
 *       这是「把一个数的每一位拆出来」的固定套路，后面很多题都用它。
 *       内层用 while 而不是 for，因为事先不知道这个数有几位。
 *       1 ≤ n ≤ 10^6，最多约 700 万次内层循环，够快。
 * 坑：1) 变量名 dight 拼错了，应该是 digit
 *     2) 外层写成 i = 0; i < n 再算 temp = i + 1，多一层心算；直接 i = 1; i <= n 更直白
 *     3) x = 0 是这种题最容易漏的情况，已实测 n = 10 / 100 / 1000000 且 x = 0 时
 *        分别得 1 / 11 / 488895，全对
 */
#include <stdio.h>
int main()
{
    int n, x;
    scanf("%d %d", &n, &x);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = i + 1;
        while (temp > 0)
        {
            int digit = temp % 10;
            if (digit == x)
            {
                count++;
            }
            temp /= 10;
        }
    }
    printf("%d", count);
    return 0;
}
