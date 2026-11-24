/*
 * 3.11_speeding.c —— 按超速比例判定：10% 以内放行，50% 以内罚款 200，再高吊销驾照
 * 来源：PTA 实验3 第 11 题
 * 日期：2026-11-24
 * 思路：1) 关键量是「超速比例」而不是「超了多少」：excess = (实际 - 限速) / 限速。
 *       2) 比例算出来按三档判断，档位边界都用「小于」写，这样正好落在边界上时归到高一档。
 * 要点：整数除整数会截断，所以分子乘 1.0（或强转 double）把整条式子拉成浮点。
 *       输出 `%.0f%%` —— 百分号本身要写 `%%`，否则 printf 会去找参数。
 * 坑：没超速时 excess 是负数，正好落进 `< 0.1`，输出 OK —— 碰巧对，
 *     但更直的写法是先判 `speed <= speed_limit`。
 */
#include <stdio.h>
int main()
{
    int speed, speed_limit;
    if (scanf("%d %d", &speed, &speed_limit) != 2)
        return 1;
    double excess = (speed - speed_limit) * 1.0 / speed_limit;
    if (excess < 0.1)
        printf("OK");
    else
    {
        if (excess < 0.5)
            printf("Exceed %.0f%%. Ticket 200", excess * 100);
        else
            printf("Exceed %.0f%%. License Revoked", excess * 100);
    }
    return 0;
}
