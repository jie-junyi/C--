#include <stdio.h>
int main()
{
    int i, k, h, num = 0, n = 0;
    scanf("%d", &h);

    // 2是素数
    printf("2 ");

    //遍历3到h的数
    for (i = 3; i < h && n < 9; i++)
    { //判断该数是不是素数，如果不是，则break跳出来，是的话，输出
        for (k = 2; k < i; k++)
        {
            if (i % k == 0)
            {   
                break;
            }
        }
        //判断是否为素数
        if(k==i){
            printf("%d ", i);
            n++;
        }
    }
}
// 4个空 小于一个数的十个素数