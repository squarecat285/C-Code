/*
 * v1_basic.c —— 猜数字 v1：不限次数地猜 1~100
 * 来源：自己做的小程序（原 guess/guess.c）
 * 日期：2026-10-08
 * 要点：while(1) 无限循环、srand(time(0)) 设置随机数种子
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int secret = rand() %100 + 1;
    int guess;
    int count = 0;

    printf("我想了一个 1~100 的数，你猜：\n");

    while (1) {
        scanf("%d", &guess);
        count++;

        if (guess < secret) {
            printf("小了，再猜: \n");     
        } else if (guess > secret) {
            printf("大了，再猜: \n");
        } else {
            printf("猜对了，你用了 %d 次。\n", count);
            break;
        }
    }
    return 0;

}
