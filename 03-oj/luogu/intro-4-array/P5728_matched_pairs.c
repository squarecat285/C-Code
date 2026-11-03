/*
 * P5728_matched_pairs.c —— 旗鼓相当的对手：n 个学生两两配对，数有几对「差不多」
 * 来源：洛谷 P5728 【深基5.例5】旗鼓相当的对手
 * 题目：https://www.luogu.com.cn/problem/P5728
 * 日期：2026-11-03
 * 思路：1) 要数「一对一对」，最直接的就是双重循环，每对判一次，j 从 i + 1 起
 *          才不会同一对数两遍、也不会自己和自已配对。
 *       2) 条件是四件事同时成立：三科各差 ≤ 5，总分差 ≤ 10 —— 所以总分要能随时取到。
 *       3) 总分只跟这个学生自己有关，跟别人无关，读入时算一次存进 sum[] 就够了，
 *          不必每判一对就重新加三次。
 *       4) 四个条件写成一条超长 if 没法读，先算成 close 再判它。
 *       5) 答案要等所有对都判完才有，所以 printf 必须在两层循环都结束之后。
 * 要点：j 从 i + 1 开始是「组合」的标准写法，复杂度 n(n-1)/2；n ≤ 1000 时约 5×10^5 对。
 * 坑：第一版把 printf 和 return 0 写进了外层 i 循环里 —— i = 0 那一轮跑完就打印退出，
 *     答案只包含「0 号和别人」的配对：5 个全 100 分输出 4（应 10）、20 个输出 19
 *     （应 190）、只有 1 号和 2 号成对时输出 0（应 1）。gcc 零警告，因为括号语法没问题。
 *     官方样例恰好是 0 号和 1 号成对，所以看不出来 —— 样例太温柔，同 P3954。
 *     另外 int arr[n][3] 是变长数组，大小由输入决定；读失败 break 之后又拿没读到的格子去比。
 * 建议：现在 O(n²) 跑满 0.006 秒，够用。若 n 涨到 10^5，就得先按总分排序，
 *       再用滑窗只比对总分相近的那一小段 —— 那是后面「排序 + 双指针」的题。
 */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    if (scanf("%d", &n) != 1)
    {
        return 1;
    }
    if (n < 1 || n > 1000)
    {
        return 1;
    }
    int score[1005][3];
    int sum[1005];
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d %d %d", &score[i][0], &score[i][1], &score[i][2]) != 3)
        {
            return 1;
        }
        sum[i] = score[i][0] + score[i][1] + score[i][2];
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int close = abs(score[i][0] - score[j][0]) <= 5
                     && abs(score[i][1] - score[j][1]) <= 5
                     && abs(score[i][2] - score[j][2]) <= 5
                     && abs(sum[i] - sum[j]) <= 10;
            if (close)
            {
                count++;
            }
        }
    }
    printf("%d", count);
    return 0;
}
