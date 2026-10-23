/*
 * P1046_apple_picking.c —— 陶陶摘苹果：算她一共能摘到几个苹果
 * 来源：洛谷 P1046 [NOIP 2005 普及组] 陶陶摘苹果
 * 题目：https://www.luogu.com.cn/problem/P1046
 * 日期：2026-10-23
 * 要点：1) 能摸到的高度 = 把手伸直能到的最大高度 + 30 厘米（板凳的高度）。
 *       2) 10 个苹果的高度先读进数组，再逐个跟能摸到的高度比，够得着就 count++。
 *       3) 判断用 <= ——「碰到苹果，苹果就会掉下来」，正好齐平也算摘到；
 *          写成 < 会在刚好齐平时漏掉一个。
 *       4) 输入是两行：先 10 个苹果高度，再 1 个陶陶的高度，scanf 的顺序别搞反。
 *       5) 循环读数组的标准写法：for (i = 0; i < 10; i++) scanf("%d", &apples[i]);
 *          数组名 apples 是首地址，但 apples[i] 是「值」，所以循环里必须写 &apples[i]。
 *
 * 建议：这题固定 10 个苹果，其实可以不存数组，读一个比一个：
 *       for (i = 0; i < 10; i++) { scanf("%d", &h); if (h <= reach) count++; }
 *       能省一个数组。但「先把数据存下来再处理」是更通用的习惯——
 *       只要后面还要用第二次（排序、找最大、多轮询问），就必须存。
 *
 * 坑：① 题目给的是「陶陶把手伸直能够达到的最大高度」，不含板凳，
 *          那 30 厘米要自己加，漏了会少算很多苹果；
 *       ② scanf 漏写 & 是老毛病（P4414、P1085 也栽过），
 *          gcc 的 -Wformat 警告会直接点出来，别忽略。
 */
#include <stdio.h>
int main()
{
    int height;
    int apples[10];
    int count = 0;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &apples[i]);
    }
    scanf("%d", &height);
    for (int i = 0; i < 10; i++)
    {
        if (height + 30 >= apples[i])
        {
            count++;
        }
    }
    printf("%d", count);
    return 0;
}
