/*
 * 3.14_menu_pricing.c —— 打印菜单，然后按输入的编号报价，0 或满 5 次退出
 * 来源：PTA 实验3 第 14 题
 * 日期：2026-11-24
 * 思路：1) 菜单是固定的五行，先原样打出来。
 *       2) 之后是一个「最多读 5 次」的循环：读到 0 立刻结束，读别的就报价。
 *          所以计数要在读之前加，退出条件放在处理之后判断。
 * 要点：switch 里每个 case 末尾都要 break，否则会一路穿透下去把后面的价也报了。
 *       对于没有匹配项的输入，default 兜底报 0.00。
 * 建议：`count == 5` 和 `n == 0` 两个退出条件可以合并到 while 条件里，代码更紧凑。
 */
#include <stdio.h>
int main()
{
    printf("[1] apple\n");
    printf("[2] pear\n");
    printf("[3] orange\n");
    printf("[4] grape\n");
    printf("[0] exit\n");
    int count = 0;
    for (;;)
    {
        count++;
        int n;
        if (scanf("%d", &n) != 1)
            return 1;
        switch (n)
        {
        case 0:
            break;
        case 1:
            printf("price = 3.00\n");
            break;
        case 2:
            printf("price = 2.50\n");
            break;
        case 3:
            printf("price = 4.10\n");
            break;
        case 4:
            printf("price = 10.20\n");
            break;
        default:
            printf("price = 0.00\n");
            break;
        }
        if (n == 0 || count == 5)
            break;
    }
    return 0;
}
