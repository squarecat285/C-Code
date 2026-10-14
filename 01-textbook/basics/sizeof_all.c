/*
 * sizeof_all.c —— 查看全部基本类型的字节数
 * 来源：上面那个的完整版（原 try/try.c）
 * 日期：2026-10-13
 * 要点：char / short / int / long / long long / float / double
 */

#include <stdio.h>
int main()
{
    printf("%zu %zu %zu %zu %zu %zu %zu\n", sizeof(char), sizeof(short), sizeof(int), sizeof(long), sizeof(long long), sizeof(float), sizeof(double));
    return 0;
}
