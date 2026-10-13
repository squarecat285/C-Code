/*
 * v3_replay.c —— 猜数字 v3：随机提示语 + 可重来一局
 * 来源：v2 的升级（原 guess/guesspro+.c）
 * 日期：2026-10-11
 * 要点：字符串数组、嵌套循环、scanf 读字符时前面的空格
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    char again; // 定义一个字符变量来存储用户是否再来一局的选择

    char *small_msgs[] = {
        // 定义一个字符串数组来存储提示信息
        "小了,还剩 %d 次,再猜:\n",
        "太小了,往大了猜:\n",
        "不对哦,这个数有点小:\n",
        "再大一点,还剩 %d 次:\n",

    };
    char *big_msgs[] = {
        // 定义一个字符串数组来存储提示信息
        "大了,还剩 %d 次,再猜:\n",
        "太大了,往小了猜:\n",
        "不对哦,这个数有点大:\n",
        "再小一点,还剩 %d 次:\n",
    };
    while (1)
    {

        int secret = rand() % 100 + 1; // 生成一个 1~100 的随机数
        int guesses[10];               // 定义一个数组来存储用户的猜测
        int i;                         // 定义一个变量来存储循环计数
        int guess;                     // 定义一个变量来存储用户的猜测
        int count = 0;                 // 定义一个变量来存储用户的猜测次数

        printf("我想了一个 1~100 的数,你猜吧：\n"); // 提示用户输入猜测

        while (1)
        {

            if (count >= 10)
            { // 如果用户猜测次数超过 10 次，提示用户游戏结束
                printf("超过10次了,你输了,答案是 %d\n", secret);
                printf("你猜过的数字：\n");
                for (i = 0; i < count; i++)
                { // 输出用户猜测的数字
                    printf("%d ", guesses[i]);
                }
                printf("\n"); // 输出换行符
                break;        // 结束循环
            }

            scanf("%d", &guess);    // 读取用户输入的猜测
            guesses[count] = guess; // 将用户的猜测存储到数组中
            count++;                // 增加猜测次数

            if (guess < secret)
            { // 如果用户猜测的数字小于随机数，提示用户再猜
                if (10 - count > 0)
                {                                          // 如果用户还有机会，提示用户再猜
                    int index = rand() % 4;                // 随机选择一个提示信息输出
                    printf(small_msgs[index], 10 - count); // 随机选择一个提示信息输出
                }
            }
            else if (guess > secret)
            { // 如果用户猜测的数字大于随机数，提示用户再猜
                if (10 - count > 0)
                {                                        // 如果用户还有机会，提示用户再猜
                    int index = rand() % 4;              // 随机选择一个提示信息输出
                    printf(big_msgs[index], 10 - count); // 随机选择一个提示信息输出
                }
            }
            else
            {
                printf("猜对了，你用了 %d 次。\n", count); // 如果用户猜测的数字等于随机数，提示用户猜对了
                printf("你猜过的数字：\n");                // 输出用户猜测的数字
                for (i = 0; i < count; i++)
                {
                    printf("%d ", guesses[i]);
                }
                printf("\n"); // 输出换行符
                break;        // 结束循环
            }
        }
        while (1)
        {
            printf("再来一局吗？(y/n): "); // 提示用户是否再来一局
            scanf(" %c", &again);          // 读取用户输入的选择

            if (again == 'y' || again == 'Y')
            { // 如果用户选择再来一局，提示用户再来一局
                printf("好的，再来一局！\n");
                break; // 结束循环，重新开始游戏
            }
            else if (again == 'n' || again == 'N')
            { // 如果用户选择不再来一局，提示用户游戏结束
                printf("游戏结束，再见！\n");
                return 0; // 结束程序
            }
            else
            { // 如果用户输入的选择不合法，提示用户重新输入
                printf("请输入 y 或 n。\n");
            }
        }
    }
}
