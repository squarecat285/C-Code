/*
 * P5717_triangle_classify.c —— 三角形分类：判断能否成三角形，以及是哪种三角形
 * 来源：洛谷 P5717 【深基3.习8】三角形分类
 * 题目：https://www.luogu.com.cn/problem/P5717
 * 日期：2026-10-22
 * 要点：1) 判三角形：最长边 < 另外两边之和（等价于 2 * 最长边 < 三边和）。
 *       2) 判角度只用比一次：三角形里最大的角对着最长的边，
 *          所以「锐角 ⟺ 最长边的平方 < 另两边平方和」，直角、钝角同理。
 *          三个角里只有最大的那个可能 ≥ 90°，另外两个必然 < 90°，比一次就够。
 *          但前提是得先知道哪条最长——输入顺序是乱的，不能直接把 a b 当两短边。
 *       3) mid 不用单独求，用 三边和 - max - min 反推一个就够。
 *       4) 两条边相等只可能出现在 min == mid 或 mid == max 两处，都要判；
 *          等边是 min == max。题目说符合多个条件要按顺序分别输出，
 *          所以等边三角形同时也要打等腰那一行。
 * 坑：1) 求 max 写成 max = (a > c) ? a : c;，把上一轮算出来的 b 丢了，
 *          应该是 max = (max > c) ? max : c;。只在 b 恰好最大时才露馅：
 *          3 5 4 是直角三角形，却因为 max 被算成 4 而判成钝角。
 *       2) 锐角和钝角的判断写反了：平方和小于长边平方是钝角，不是锐角。
 *       3) 等腰只写了 min == mid，漏掉 mid == max，3 4 4 和 6 3 6 都判不出来。
 *       4) if (max = min) 是赋值不是比较；而且下一行只写了一个字符串字面量、
 *          没有 printf，gcc 报 statement with no effect，运行时什么都不输出。
 * 建议：1) 更直白的写法是先把三边排序（P5715 的排序网络，三行 if 交换），
 *          排完 a ≤ b ≤ c 之后 a、b、c 天然就是短、中、长，
 *          不用再维护 max / min / mid 三个变量，也就不会有「max 算错」这种坑：
 *
 *              if (a > b) { int t = a; a = b; b = t; }
 *              if (a > c) { int t = a; a = c; c = t; }
 *              if (b > c) { int t = b; b = c; c = t; }
 *
 *       2) 判三角形还可以写成 max >= a + b + c - max，读作「最长边 ≥ 另外两边之和」，
 *          和 2 * max >= a + b + c 完全等价，哪个顺手用哪个。
 *       3) 角度的三个分支互斥，所以用 else if 是对的；
 *          等腰、等边可能和角度同时成立（比如等边也是锐角），
 *          所以必须用独立的 if，不能并进上面那串 else if 里。
 */
#include <stdio.h>
int main()
{
    int a, b, c, max, min;
    scanf("%d %d %d", &a, &b, &c);
    max = (a > b) ? a : b;
    max = (max > c) ? max : c;
    if (2 * max >= a + b + c)
    {
        printf("Not triangle\n");
        return 0;
    }
    min = (a < b) ? a : b;
    min = (min < c) ? min : c;
    int mid = a + b + c - max - min;
    if (mid * mid + min * min == max * max)
    {
        printf("Right triangle\n");
    }
    else if (mid * mid + min * min > max * max)
    {
        printf("Acute triangle\n");
    }
    else
    {
        printf("Obtuse triangle\n");
    }
    if (min == mid || mid == max)
    {
        printf("Isosceles triangle\n");
    }
    if (max == min)
        printf("Equilateral triangle\n");
    return 0;
}
