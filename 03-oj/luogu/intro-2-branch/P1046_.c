#include <stdio.h>
int main()
{
    int height;
    int apples[10];
    int count = 0;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &apples[i]);
    }
    scanf("%d", &height);
    for (int i = 0; i < 10; i++)
    {
        if (height + 30 >= apples[i])
        {
            count++;
        }
    }
    printf("%d", count);
    return 0;
}
// 可以用数组先存下数据再运算
//scanf函数漏写&
