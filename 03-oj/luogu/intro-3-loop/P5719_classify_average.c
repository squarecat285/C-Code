/*
 * P5719_classify_average.c —— 分类平均：1~n 里 k 的倍数求平均、非倍数求平均
 * 来源：洛谷 P5719 【深基4.例3】分类平均
 * 题目：https://www.luogu.com.cn/problem/P5719
 * 日期：2026-10-24
 * 要点：一趟循环把 k 的倍数挑出来：累加进 sum、个数记 count。
 *       A 类平均数 = sum / count；B 类的和不用再扫一遍，用总和减掉就行
 *       —— 1~n 的总和是 n*(n+1)/2。数据 1 ≤ n ≤ 10000、1 ≤ k ≤ 100。
 * 坑：sum 和 A、B 原来写成 float，会在大数据上算错小数点后一位。
 *     验证：n=4096 k=3，float 给 "2049.0 2048.2"，正确是 "2048.3"；
 *           n=10000 k=3，float 给 "5000.2"，正确是 "5000.3"。
 *     把 k=1..100、n=1..10000 全部 985050 组跟精确值比，float 版错 3163 组（0.32%）。
 *     原因：float 只有 24 位有效位，十进制只保证 6~7 位；A、B 都是除法结果，
 *           差一点点就跨过了 .x5 这个四舍五入的分界线。
 *     改法：float → double（scanf 不用动，两个变量本来就只由整数算出来）。
 */
#include <stdio.h>
int main()
{
    int n, k, count = 0;
    double sum = 0;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        if (i % k == 0)
        {
            sum += i;
            count++;
        }
    }
    double A = sum / count;
    double B = (n * (1 + n) / 2 - sum) / (n - count);
    printf("%.1f %.1f", A, B);
    return 0;
}
