#include<stdio.h>
int main() {
    int i,t;

    i=1;
    t=i;
    while(i<5) {
        i=i+1;
        t=t*i;
    }
    printf("%d\n",t);
    return 0;
}
