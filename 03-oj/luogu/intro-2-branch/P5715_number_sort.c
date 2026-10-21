/*
 * P5715_number_sort.c —— 三位数排序：读入三个整数，从小到大输出
 * 来源：洛谷 P5715 【深基3.例8】三位数排序
 * 题目：https://www.luogu.com.cn/problem/P5715
 * 日期：2026-10-21
 * 要点：三个 if 交换就是一张排序网络，三次比较就够，不用冒泡：
 *       先拿 a 跟 b、c 比，把最小的换到 a；
 *       再比 b 和 c，剩下的两个自然就排好了。
 */
#include <stdio.h>
int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a > b)
    {
        int t = a;
        a = b, b = t;
    }
    if (a > c)
    {
        int t = a;
        a = c, c = t;
    }
    if (b > c)
    {
        int t = b;
        b = c, c = t;
    }
    printf("%d %d %d", a, b, c);
    return 0;
}
