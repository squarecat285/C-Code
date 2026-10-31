/*
 * P5726_scoring.c —— 打分：去掉一个最高分和一个最低分，求剩下分数的平均
 * 来源：洛谷 P5726 【深基4.习9】打分
 * 题目：https://www.luogu.com.cn/problem/P5726
 * 日期：2026-10-31
 * 思路：1) 要去掉最高和最低 ⇒ 得知道 max、min；剩下的还要平均 ⇒ 得知道总和。
 *          三个量一趟循环就能一起求出来，不用存数组。
 *       2) 有多个最高/最低时只去掉一个 —— 直接「总和减一次 max、减一次 min」
 *          天生就满足，不需要统计出现了几次。
 *       3) 剩下的个数是 n - 2（数据保证 n ≥ 3），平均数 = (sum - max - min) / (n - 2)。
 *       4) 要两位小数，所以除法必须落在浮点上：乘 1.0 或先强转 double。
 * 要点：分值范围是 0~10，所以 max 从 -1 起步、min 从 11 起步，比所有可能值都更极端。
 * 坑：如果写成 (sum - min - max) / (n - 2) 直接整数除，结果会被截断成整数，
 *     %.2f 只能打出 .00。这个错编译器不会警告，因为语法完全合法。
 * 建议：(sum - min - max) * 1.0 / (n - 2) 里的 * 1.0 有点隐晦，
 *       写成 (double)(sum - min - max) / (n - 2) 一眼就知道在做什么。
 */
#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int max = -1;
    int min = 11;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        if (a > max)
            max = a;
        if (a < min)
            min = a;
        sum += a;
    }
    printf("%.2f", (sum - min - max) * 1.0 / (n - 2));
    return 0;
}
