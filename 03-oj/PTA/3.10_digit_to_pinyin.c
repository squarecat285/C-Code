/*
 * 3.10_digit_to_pinyin.c —— 把一串数字和负号逐个念成拼音，用空格隔开
 * 来源：PTA 实验3 第 10 题
 * 日期：2026-11-24
 * 思路：1) 输入是一整行，但只有数字和负号要处理，别的字符一律跳过 ——
 *          所以逐个字符读、边读边判断，比先存进数组再遍历省地方。
 *       2) 遇到要翻译的字符，先解决「前面要不要空格」（first 标记），再交给 switch 翻译。
 * 要点：`getchar()` 返回的是 int 不是 char —— 因为要能表示 EOF(-1)，用 char 接会丢信息。
 *       读行的循环写成 `(ch = getchar()) != '\n' && ch != EOF`，两个出口都要有。
 * 建议：十个 case 其实是一张表，可以用 `const char *pinyin[] = {"ling","yi",...}` 加下标，
 *       代码能从 40 行降到 5 行。
 */
#include <stdio.h>
int main()
{
    int ch;
    int first = 0;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        if (ch == '-' || (ch >= '0' && ch <= '9'))
        {
            first++;
            if (first != 1)
                putchar(' ');

            switch (ch)
            {
            case '-':
                printf("fu");
                break;
            case '0':
                printf("ling");
                break;
            case '1':
                printf("yi");
                break;
            case '2':
                printf("er");
                break;
            case '3':
                printf("san");
                break;
            case '4':
                printf("si");
                break;
            case '5':
                printf("wu");
                break;
            case '6':
                printf("liu");
                break;
            case '7':
                printf("qi");
                break;
            case '8':
                printf("ba");
                break;
            case '9':
                printf("jiu");
                break;
            }
        }
    }
    return 0;
}
