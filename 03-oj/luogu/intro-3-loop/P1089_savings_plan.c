/*
 * P1089_savings_plan.c —— 津津的储蓄计划：每月存整百，年末连本带 20% 利息还回来
 * 来源：洛谷 P1089 [NOIP 2004 提高组] 津津的储蓄计划
 * 题目：https://www.luogu.com.cn/problem/P1089
 * 日期：2026-11-01
 * 思路：1) 每个月能动的钱 = 手上剩的零钱 + 妈妈给的 300，所以先把这个月的
 *          「预计结余」算出来：temp = rest + 300 - expense，一步到位。
 *       2) temp < 0 就是这月不够花。题目要的是「第一个不够的月份」，
 *          所以直接 break，用 i 记下是第几个月，不用再往下跑。
 *       3) 够的话就按题目规则存钱：整百的交出去，零头留在手上。
 *          deposit += temp / 100 * 100;  rest = temp % 100;  两句对应「存」和「留」。
 *       4) 12 个月跑完，年末拿到的是「手里的零钱 + 存款 + 20% 利息」。
 *          存款一定是 100 的倍数，所以利息用 deposit / 5 就能整数算，不碰浮点。
 * 要点：一年固定 12 个月，用 for (i = 0; i < 12; i++)，i 顺便当「第几个月」用；
 *       first 标记区分两种出口——中途没钱（打 -月份）和正常跑完（打总额）。
 *       「整百存起来」这个动作拆成 / 100 * 100 和 % 100 两半，是本篇的核心手法。
 * 坑：两处都是 gcc 明确报了警告的类型笔误：①scanf("%d", expense) 少了 &，
 *     scanf 要的是「往哪儿写」；②printf("%d", deposit * 1.2 + rest) ——
 *     1.2 让整个式子变成 double，而 %d 按整数去取参数，取到的根本不是这个数，
 *     样例直接打出 0。改成纯整数 deposit + deposit / 5 + rest 才对。
 * 建议：不用循环、直接算也行——但当心「一个月一个月往前走」这种带状态的题，
 *       循环写出来最好读，别为了少写两行把状态揉进公式里。
 */
#include <stdio.h>
int main()
{
    int rest = 0;
    int deposit = 0;
    int first = 1;
    int i;
    for (i = 0; i < 12; i++)
    {
        int expense;
        scanf("%d", &expense);
        int temp = rest + 300 - expense;
        if (temp < 0)
        {
            first = 0;
            break;
        }
        rest = temp % 100;
        deposit += (temp / 100) * 100;
    }
    if (first == 0)
        printf("-%d", i + 1);
    else
        printf("%d", deposit + deposit / 5 + rest);
    return 0;
}
