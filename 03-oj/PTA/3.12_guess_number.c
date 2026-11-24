/*
 * 3.12_guess_number.c —— 猜数字：按猜中次数分 Bingo / Lucky You / Good Guess，
 *                        输入负数或猜满 N 次还没中，输出 Game Over
 * 来源：PTA 实验3 第 12 题（猜数字游戏）
 * 日期：2026-11-24
 * 思路：1) 「猜中、猜大、猜小、输入负数、次数用完」五件事，都要在一个循环里判。
 *       2) 判断顺序有讲究：负数必须放在大小比较之前，否则负数会被当成「猜小了」多打一行。
 *       3) 每个「该结束了」的分支，除了记标记，还必须立刻 break 出循环 ——
 *          标记本身不会让程序停下来。
 * 要点：`n == limit` 的判断放在 n++ 之后、比较之后，才能保证第 N 次猜中算 Good Guess。
 * 坑：1) 第一版把「输入负数」和「次数用完」写成 `else if (guess < 0 || n == limit)`，
 *          但前面 `>`、`<`、`==` 三个分支已经穷尽了所有情况，第四个 else if 永远执行不到 ——
 *          负数被当成「猜小了」，Game Over 永远打不出来。
 *       2) 第二版拆成两个独立 if，条件可达了，但没有 break，循环继续跑到读不到输入才停。
 * 建议：`first` 这个标记位的名字体现不出「结束」，叫 `game_over` 更直白。
 */
#include <stdio.h>
int main()
{
    int answer, limit;
    if (scanf("%d %d", &answer, &limit) != 2)
        return 1;
    int n = 0, guess, first = 0;
    for (;;)
    {
        if (scanf("%d", &guess) != 1)
            return 1;
        n++;
        if (guess < 0)
        {
            first = 1;
            break;
        }
        if (guess > answer)
            printf("Too big\n");
        else if (guess < answer)
            printf("Too small\n");
        else if (guess == answer)
            break;
        if (n == limit)
        {
            first = 1;
            break;
        }
    }
    if (first == 1)
    {
        printf("Game Over");
        return 0;
    }
    if (n == 1)
        printf("Bingo!");
    else if (n <= 3)
        printf("Lucky You!");
    else
        printf("Good Guess!");
    return 0;
}
