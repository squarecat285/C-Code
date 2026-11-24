/*
 * 3.15_card_rank.c —— 把牌面数字 1~13 转成显示的字符（1→A，11→J，12→Q，13→K）
 * 来源：PTA 实验3 第 15 题
 * 日期：2026-11-24
 * 思路：1) 2~9 原样输出，10~13 要换成字母，1 也换成 A —— 只有 1 开头的那几个特殊。
 *       2) 先用 str[0] 分支：'2'~'9' 直接打印；'1' 再进去细分成 1、10、11、12、13。
 * 要点：字符串比较用 strcmp，相等时返回 0；`case '1':` 后面用 `{ }` 把一串声明和 if 包起来。
 * 坑：1) char str[3] 只够 2 个字符 + 结尾 '\0'，输入正好是 "13" 时卡在边界，
 *          再长一位就越界；scanf 也没限宽。
 *       2) 2~9 分支只看 str[0]，所以输入 "99" 会输出 9 而不是 none ——
 *          1x 分支用整串比较、2~9 分支只看首字符，两种判法不一致。
 * 建议：整个 switch 可以用 `atoi(str)` 转成数字再判断，逻辑更统一。
 */
#include <stdio.h>
#include <string.h>
int main()
{
    char str[3];
    if (scanf("%s", str) != 1)
        return 1;
    switch (str[0])
    {
    case '2':
        printf("2");
        break;
    case '3':
        printf("3");
        break;
    case '4':
        printf("4");
        break;
    case '5':
        printf("5");
        break;
    case '6':
        printf("6");
        break;
    case '7':
        printf("7");
        break;
    case '8':
        printf("8");
        break;
    case '9':
        printf("9");
        break;
    case '1':
    {
        if (strcmp(str, "1") == 0)
        {
            printf("A");
            break;
        }
        else if (strcmp(str, "10") == 0)
        {
            printf("T");
            break;
        }
        else if (strcmp(str, "11") == 0)
        {
            printf("J");
            break;
        }
        else if (strcmp(str, "12") == 0)
        {
            printf("Q");
            break;
        }
        else if (strcmp(str, "13") == 0)
        {
            printf("K");
            break;
        }
        else
        {
            printf("none");
            break;
        }
    }

    default:
        printf("none");
        break;
    }

    return 0;
}
