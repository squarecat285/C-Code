/*
 * 3.08_height_weight.c —— 按性别对照标准身高/体重，判断偏高偏矮、偏胖偏瘦
 * 来源：PTA 实验3 第 8 题
 * 日期：2026-11-24
 * 思路：1) 标准值是题面直接给的表格，只有 2 行 × 2 列，所以直接建成二维数组
 *          `standard[性别][0=身高,1=体重]`，用 s 当行号查表，比写四个 if 清楚。
 *       2) 每个输入要输出两段判断（身高一段、体重一段），各自三选一。
 * 要点：题面给了表就照抄成数组，让数据和逻辑分开 —— 改数据时不用动 if。
 * 坑：`scanf(...) != 3` 后面多了一个孤立的 `;`（空语句），不影响结果但是多余。
 */
#include <stdio.h>
int main()
{
    int n;
    if (scanf("%d", &n) != 1)
        return 1;
    int standard[2][2] = {{129, 25}, {130, 27}};
    for (int i = 0; i < n; i++)
    {
        int s, h, w;
        if (scanf("%d %d %d", &s, &h, &w) != 3)
            return 1;
        ;
        if (h == standard[s][0])
            printf("wan mei! ");
        else
            printf("%s", h > standard[s][0] ? "ni li hai! " : "duo chi yu! ");
        if (w == standard[s][1])
            printf("wan mei!\n");
        else
            printf("%s", w > standard[s][1] ? "shao chi rou!\n" : "duo chi rou!\n");
    }
    return 0;
}
