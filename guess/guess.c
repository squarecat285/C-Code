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
