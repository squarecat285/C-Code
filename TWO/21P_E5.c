#include<stdio.h>
int main() {
    int n,i;
    int isPrime=1;
     printf("请输入n的值:");
     scanf("%d",&n);

     if(n<=1) {
        isPrime=0;
     } else {
        for(i=2;i*i<=n;i++) {
            if(n%i==0) {
                isPrime=0;
                break;
            }
        }
     } if(isPrime==1) {
        printf("%d是素数",n);
     } else {
        printf("%d不是素数",n);
     }
     return 0;

}
