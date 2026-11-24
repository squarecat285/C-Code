/*
 * 3.05_binary_tree_index.c —— 按 y/n 路径在完全二叉树里找叶子编号
 * 来源：PTA 实验3 第 5 题
 * 日期：2026-11-24
 * 思路：1) 完全二叉树按层编号时，从根（1 号）往下走：y 走左边、n 走右边。
 *          树的节点总数是 2^n，当前子树根节点的编号就等于「已确定的偏移 + 1」。
 *       2) 每走一步，子树规模减半，所以 all 每次除以 2；
 *          走右边就把这一半的起点加进 temp，走左边保持不动。
 *       3) 每棵树的分值只要读 n 个字符，所以外层循环跑 a 次，每次读满 n 个。
 * 要点：`" %c"` 前面的空格让 scanf 跳过所有空白（含换行），读字符时几乎总要加。
 * 坑：`temp = temp;` 是空语句（自己赋给自己），什么也没做，直接不写。
 * 建议：`pow(2, n)` 要链 `-lm` 还绕，`1 << n` 更直接；但 n 大了会溢出，用 long long 更稳。
 */
#include <stdio.h>
#include <math.h>
int main()
{
    int n, a;

    char q;
    if (scanf("%d %d", &n, &a) != 2)
        return 1;
    for (int i = 0; i < a; i++)
    {
        int all = pow(2, n);
        int temp = 1;
        for (int j = 0; j < n; j++)
        {
            if (scanf(" %c", &q) != 1)
                return 1;
            if (q == 'y')
                temp = temp;
            else
                temp = temp + all / 2;
            all = all / 2;
        }
        printf("%d\n", temp);
    }
    return 0;
}
