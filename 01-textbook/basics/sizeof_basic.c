/*
 * sizeof_basic.c —— 查看 short / int / long 各占几个字节
 * 来源：数据类型实验（原 int/int.c）
 * 日期：2026-10-11
 * 要点：sizeof 运算符、%zu 格式符
 */

#include <stdio.h>
int main()
{
    printf("%zu\n", sizeof(short));
    printf("%zu\n", sizeof(int));
    printf("%zu\n", sizeof(long));

    return 0;
}
