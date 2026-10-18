/*
 * encrypt_china.c —— 把 "China" 每个字母往后挪 4 位，输出 "Glmre"
 * 来源：《C程序设计》第三章 课后习题 · 字母加密
 * 日期：2026-10-18
 * 要点：字符和整数是一回事，'C' + 4 直接就是 'G'，不用查表；
 *       输出用 putchar 一个字符一个字符地打
 * 坑：这题碰巧没踩到边界 —— 如果字母是 w / x / y / z，加 4 会跑到字母表外面去，
 *     那就得绕回 'a'，不是简单加 4 能解决的
 */
#include <stdio.h>
int main()
{
    char c1 = 'C', c2 = 'h', c3 = 'i', c4 = 'n', c5 = 'a';
    c1 = c1 + 4;
    c2 = c2 + 4;
    c3 = c3 + 4;
    c4 = c4 + 4;
    c5 = c5 + 4;
    putchar(c1);
    putchar(c2);
    putchar(c3);
    putchar(c4);
    putchar(c5);
    putchar('\n');
    return 0;
}
