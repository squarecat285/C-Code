/*
 * v2_limit10.c —— 猜数字 v2：限 10 次，并记录猜过的数字
 * 来源：v1 的升级（原 guess/guesspro.c）
 * 日期：2026-10-11
 * 要点：用数组保存历史记录
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));                // 使用当前时间作为随机数种子
    int secret = rand() % 100 + 1; // 将获得的随机数除以100，取余数加1，得到1~100的随机数
    int guess;                     // 定义一个变量来储存用户输入的数字
    int count = 0;                 // 定义一个变量来统计用户猜的次数
    int guesses[10];               // 定义一个数组来储存用户猜过的数字
    int i;                         // 定义一个变量来循环输出用户猜过的数字

    printf("我想了一个 1~100 的数，你猜：\n"); // 提示用户输入数字

    while (1)
    { // 无限循环，直到用户才对或猜的次数超过10次

        if (count >= 10)
        {                                                    // 如果用户猜的次数超过10次
            printf("超过10次了,你输了,答案是 %d\n", secret); // 提示用户输了，并输出正确答案
            printf("你猜过的数字：\n");                      // 输出用户猜过的数字
            for (i = 0; i < count; i++)
            {                              // 循环输出用户猜过的数字
                printf("%d ", guesses[i]); // 输出用户猜过的数字
            }
            printf("\n"); // 换行
            break;        // 退出循环
        }

        scanf("%d", &guess);    // 读取用户输入的数字
        guesses[count] = guess; // 将用户输入的数字存入数组中
        count++;                // 增加猜测次数

        if (guess < secret)
        {
            printf("小了，再猜: \n"); // 如果用户输入的数字小于随机数，提示用户小了，在猜
        }
        else if (guess > secret)
        {
            printf("大了，再猜: \n"); // 如果用户输入的数字大于随机数，提示用户大了，在猜
        }
        else
        {
            printf("猜对了，你用了 %d 次。\n", count); // 如果用户输入的数字等于随机数，提示用户猜对了，并输出猜测次数
            printf("你猜过的数字：\n");                // 输出用户猜过的数字
            for (i = 0; i < count; i++)
            {                              // 循环输出用户猜过的数字
                printf("%d ", guesses[i]); // 输出用户猜过的数字
            }
            printf("\n"); // 换行
            break;        // 退出循环
        }
    }
    return 0; // 返回0，表示程序正常结束
}
