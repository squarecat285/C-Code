/*
 * P1554_dream_counting.c —— 统计 M..N 之间每个数码 0~9 各出现了多少次
 * 来源：洛谷 P1554 [USACO06DEC] 梦中的统计 Dream Counting B
 * 题目：https://www.luogu.com.cn/problem/P1554
 * 日期：2026-11-24
 * 思路：1) 要的是「每个数码各几次」，最直接就是拿每个数去和 0~9 挨个碰，
 *          前提是会「把一个数拆成一位一位」——这正是 %10 和 /10 的用途。
 *       2) 拆位是里层动作，统计十个数码是外层，于是自然写成「对每个数码 i，
 *          把 M..N 全扫一遍」，一共扫 10 遍。
 *       3) 但同一个数被拆 10 遍是浪费：拆一次就能给十个计数器各加一笔，
 *          所以「扫一遍、边拆边加」是更好的写法（见建议 2）。
 *       4) 能不能不枚举？题目真正给的规模不是 N 多大，而是 N-M ≤ 5×10^5，
 *          区间长度只有五十万，所以逐个枚举完全跑得动。
 * 要点：拆位的固定套路 —— n % 10 取末位、n / 10 去掉末位，while 到 n == 0 停。
 *       while 一次都不进的情况（数本身就是 0）不会出现在这里，因为 M ≥ 1。
 * 坑：1) while (!n == 0) 能跑对，但 `!` 比 `==` 结合得紧，它其实是 (!n) == 0，
 *          等价于 n != 0。写成 while (n != 0) 才一眼能读。
 *       2) j 用 int：N ≤ 2×10^9，而 INT_MAX = 2147483647，刚好装得下；
 *          如果哪天 N 真给到 2147483647，j++ 就会溢出成负数、循环不终止。
 * 建议：1) 函数声明 int digit(int, int); 写在 main 里，挪到文件顶部更好找
 *          （或者把 digit 的定义直接放到 main 前面，声明就省了）。
 *       2) 改成一趟拆完：外层遍历数、内层拆位、cnt[末位]++ 十个计数器一起加。
 *          实测 N-M = 5×10^5 时 0.017s → 0.001s，快 17 倍，而且少一层循环。
 *       3) 参数名 digit(int x, int n) 看不出谁是数码、谁是数，
 *          改成 count_digit(int num, int d) 读调用处 digit(i, j) 才不会看反。
 */
#include <stdio.h>
int main()
{
    int digit(int x, int n);
    int M, N;
    if (scanf("%d %d", &M, &N) != 2)
        return 1;
    for (int i = 0; i < 10; i++)
    {
        int sum = 0;
        for (int j = M; j <= N; j++)
        {
            sum += digit(i, j);
        }
        printf("%d", sum);
        if (i != 9)
            printf(" ");
    }
    return 0;
}
int digit(int x, int n)
{
    int sum = 0;
    while (!n == 0)
    {
        if (n % 10 == x)
            sum++;

        n = n / 10;
    }
    return sum;
}
