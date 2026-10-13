#include<stdio.h>
int main() {
    int i,t;

    i=1;
    t=i;
    while (1) {
        i=i+2;
        t=t*i;
        if(i>=11) {
            break;
        }
    }
    printf("%d\n",t);
    return 0;
}
