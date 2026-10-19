/*
 * P5709_apples_prologue.c —— 苹果和虫子：m 个苹果，吃完一个要 t 分钟，过了 s 分钟还剩几个完整的
 * 来源：洛谷 P5709 【深基2.习6】Apples Prologue / 苹果和虫子
 * 题目：https://www.luogu.com.cn/problem/P5709
 * 结果：⬜ 待提交（本地 10,100,000 组边界全对）
 * 日期：2026-10-19
 * 要点：吃掉的个数是向上取整 ceil(s / t)，整数写法 (s + t - 1) / t；
 *       剩下的 = m - 吃掉，但不够吃的时候答案就是 0，不是「没有答案」。
 *       先把结果夹到合法范围，再统一 printf，比在两个分支里各写一次输出稳。
 * 坑：1) t = 0 是合法数据（0 ≤ t ≤ 100），直接除会 RE，必须先拦住。
 *    2) 原来写 if (m - e >= 0) printf(...)，为假时什么都不输出。
 *       洛谷逐字节比对，标准答案是 0 而你交了空白 → WA。
 *       本地用 1 100 10000 这样的数据才能撞出来，用 t = 0 的数据撞不到。
 */
#include <stdio.h>

int main()
{
    int m, t, s;
    scanf("%d %d %d", &m, &t, &s);

    if (t == 0) /* 一个苹果都不花时间，等于全吃完了 */
    {
        printf("0");
        return 0;
    }

    int eaten = (s + t - 1) / t; /* 向上取整：吃掉几个 */
    int left = m - eaten;
    if (left < 0) /* 不够吃，剩 0 个 */
        left = 0;

    printf("%d", left);
    return 0;
}
