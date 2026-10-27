/*
 * count_chars.c —— 输入一行字符，分别统计英文字母、空格、数字和其他字符的个数
 * 来源：《C程序设计》第五章 习题 4（原 01-textbook/3/4.c）
 * 日期：2026-10-27
 * 要点：`while ((c = getchar()) != '\n' && c != EOF)` 是「一次吃一个字符」的标准写法。
 *       括号不能省：c = getchar() 先赋值，再拿赋完的值跟 '\n' 比。
 *       c 声明成 int 而不是 char —— getchar 返回 int，用 char 接会让 EOF(-1) 变成 255，
 *       永远判不出结尾。
 *       用 <ctype.h> 的 isalpha / isspace / isdigit 比自己写 a <= c && c <= z 干净得多。
 * 坑：isspace 管的是「所有空白字符」—— 空格、\t、\n、\v、\f、\r 都算。
 *     教材的参考答案只把 ' ' 记成空格，\t 算「其他」。所以在有制表符的输入上，
 *     这里跟教材的答案会差一点（实测 "a<TAB>b" 得到 字母2 空格1，教材算 字母2 其他1）。
 *     想跟教材一致就把 isspace(c) 换成 c == ' '。
 * 建议：想统计中文也行不通 —— 中文在 UTF-8 里是 3 个字节，每个字节都会落进「其他」，
 *       一个汉字会被数成 3 个。要数汉字得先解码，那是后面的事。
 */
#include <stdio.h>
#include <ctype.h>
int main()
{
    int letters = 0, spaces = 0, digits = 0, others = 0;
    int c;
    printf("请输入一串字符:\n");
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (isalpha(c))
        {
            letters++;
        }
        else if (isspace(c))
        {
            spaces++;
        }
        else if (isdigit(c))
        {
            digits++;
        }
        else
        {
            others++;
        }
    }
    printf("字母:%d\n空格:%d\n数字:%d\n其他:%d\n", letters, spaces, digits, others);
    return 0;
}
