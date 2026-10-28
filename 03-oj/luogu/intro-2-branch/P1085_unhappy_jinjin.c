/*
 * P1085_unhappy_jinjin.c —— 不高兴的津津：7 天里找出上课时间最长、且超过 8 小时的那天
 * 来源：洛谷 P1085 [NOIP 2004 普及组] 不高兴的津津
 * 题目：https://www.luogu.com.cn/problem/P1085
 * 日期：2026-10-21
 * 思路：1) 每天两段课的时间一加就是当天总时长，超过 8 小时才算「不高兴」。
 *       2) 要找「最不高兴的那天」，本质是找最大值 —— 但还要知道是哪一天，
 *          所以要配两个变量：一个记最大值，一个记它的下标。
 *       3) 边读边比，读完就出结果，不需要把 7 天都存进数组。
 *       4) 两个条件同时成立才更新：total > 8（今天确实不高兴）
 *          且 total > max_total（比之前更不高兴）。写成 >= 会在打平时取到靠后那天。
 *       5) max_day 初值给 0 —— 一天都没超 8 小时时它不会被改，
 *          正好就是题目要的「输出 0」。
 * 要点：第一道「边读边比」的题，不需要数组。max_total 记当前最长的时间，
 *       max_day 记是哪一天。判断必须是 total > 8 && total > max_total：
 *       少了 total > 8，七天的 8 小时会误报第 1 天（应为 0）；
 *       写成 >=，并列时会取到靠后的那天（题目要最靠前的）。
 *       都不超过 8 小时时 max_day 一直是初值 0，正好就是答案，不用另外处理。
 *       scanf 放在循环里就行，它自己记住读到哪儿了，%d 会自动跳过空格和换行。
 * 坑：① for 条件写成 1 <= 7，恒真 → 死循环（gcc 不报，它以为你故意写死循环）；
 *     ② scanf("%d %d", a, b) 少了 &，scanf 往地址 1、2 写 → 段错误；
 *     ③ 只更新 max_day 不更新 max_total，比较永远成立 → 输出了最后一天。
 */
#include <stdio.h>
int main()
{
    int max_total = 0, max_day = 0;

    for (int i = 1; i <= 7; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        int total = a + b;
        if (total > 8 && total > max_total)
        {
            max_total = total;
            max_day = i;
        }
    }
    printf("%d", max_day);
    return 0;
}
