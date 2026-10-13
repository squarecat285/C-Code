#include<stdio.h>
int main()
{
    char name[20];
    printf("你叫什么名字？\n");
    scanf("%s",name);  
    printf("你好,%s,欢迎来到计算机世界！\n",name);
    return 0;
}