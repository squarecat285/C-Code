/*
 * P1909_buy_pencils.c —— 买铅笔：三种包装任选，各买整数包，凑够 n 支，求最少花多少钱
 * 来源：洛谷 P1909 [NOIP 2016 普及组] 买铅笔
 * 题目：https://www.luogu.com.cn/problem/P1909
 * 日期：2026-10-22
 * 要点：每种包装要买几包 = 向上取整(n / each)，再乘价格，三种取最小。
 *       整数向上取整的统一写法是 (n + each - 1) / each：
 *       有余数时补上的 each - 1 刚好把商顶到下一个整数，正好整除时又不够进一位。
 *       前提是两边都是整数——B2029 那题 v 是 double，同一个技巧就不成立，得用 ceil。
 * 坑：一开始把包数写成 number_need % each + 1，也就是「余数 + 1」，
 *     跟「需要几包」毫无关系。n、each 各取 1~10000 共一亿组，
 *     算对 56685 组、算错 99943315 组（错 99.94%），能对的都是巧合。
 *     官方样例 57 / (2,2) (50,30) (30,27) 输出 4，正确是 54。
 * 另一种写法：price_min 的初值容易出问题。本题最贵 10000 包 × 10000 元 = 1 亿，
 *     原来写的 100000000 刚好等于上界，答案真是 1 亿时就永远不更新。
 *     除了改成一个足够大的数，还可以干脆在第一组就赋值，后面两组再比：
 *
 *         for (int i = 1; i <= 3; i++)
 *         {
 *             scanf("%d %d", &each, &price);
 *             int packs = (number_need + each - 1) / each;
 *             int cost = packs * price;
 *             if (i == 1 || cost < price_min) price_min = cost;
 *         }
 *
 *     这样 price_min 不用给初值，也就不存在「初值够不够大」这个问题。
 */
#include <stdio.h>
int main()
{
    int number_need;
    scanf("%d", &number_need);
    int each, price;
    int price_min = 2147483647;
    for (int i = 1; i <= 3; i++)
    {
        scanf("%d %d", &each, &price);
        int each_least = (number_need + each - 1)/each;
        int price_one = each_least * price;
        if (price_one < price_min)
        {
            price_min = price_one;
        }
    }
    printf("%d", price_min);
    return 0;
}
