/*
 * leap_year.c —— 判断 2000—2500 之间的闰年
 * 来源：《C程序设计》第 19 页 第 3 题（原 TWO/19P_E3.c）
 * 日期：2026-10-11
 * 要点：&& || 的优先级低于比较运算符，但加括号更清楚
 */

#include<stdio.h>
int main() {
    int year;
    year=2000;
    while (year<=2500) {
        if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            printf("%d 是闰年\n",year);
        } else {
            printf("%d 不是闰年\n",year);
        } year=year+1;
    } return 0;
}
