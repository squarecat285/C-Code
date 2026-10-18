/*
 * char_analysis.c —— 同一个 char 变量，按 %c 打是字母，按 %d 打是 ASCII 码
 * 来源：《C程序设计》第三章 课后习题 · 分析程序的输出
 * 日期：2026-10-18
 * 要点：char 本质上就是个 1 字节整数，a 就是 97、b 就是 98；
 *       变量自始至终没变，变的是 printf 用哪个格式符去解释它
 */
#include <stdio.h>
int main()
{
    char c1, c2;
    c1 = 97;
    c2 = 98;
    printf("c1=%c,c2=%c\n", c1, c2);
    printf("c1=%d,c2=%d\n", c1, c2);
    return 0;
}
