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
