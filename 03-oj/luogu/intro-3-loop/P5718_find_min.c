/*
 * P5718_find_min.c —— 找最小值：n 个非负整数里最小的那个
 * 来源：洛谷 P5718 【深基4.例2】找最小值
 * 题目：https://www.luogu.com.cn/problem/P5718
 * 日期：2026-10-24
 * 要点：先读第一个当「擂主」，后面每读一个就跟擂主比，比它小就换人。数据 n ≤ 100、a_i ≤ 1000。
 * 建议：这题其实不用数组 —— 边读边比，读完就有答案，内存只用两个 int：
 *           int min = 1001;              // 比最大值还大，保证第一个数一定能顶掉它
 *           for (int i = 0; i < n; i++) { int x; scanf("%d", &x); if (x < min) min = x; }
 *       跟 P1085 不高兴的津津是同一个套路（循环 + 一个记忆变量）。
 *       int s[n + 1] 是变长数组（VLA），C99 才有，n 在运行时才确定的写法；
 *       VS Code 默认能编，旧编译器不认。小数据没问题，但数据一大就吃栈 —— 后面学数组时会讲。
 */
#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int s[n + 1];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
    }
    int min = s[0];
    for (int i = 1; i < n; i++)
    {
        if (s[i] < min)
        {
            min = s[i];
        }
    }
    printf("%d", min);
    return 0;
}
