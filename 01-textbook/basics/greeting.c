/*
 * greeting.c —— 读取名字并问候
 * 来源：输入输出练习（原 name/name.c）
 * 日期：2026-10-08
 * 要点：scanf 用 %s 读字符串、字符数组、数组名本身即地址所以不加 &
 */

#include <stdio.h>
int main()
{
    char name[20];
    printf("你叫什么名字？\n");
    scanf("%s", name);
    printf("你好,%s,欢迎来到计算机世界！\n", name);
    return 0;
}
