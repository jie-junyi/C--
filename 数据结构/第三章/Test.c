#include <stdio.h>
int main()
{
    int i, k, h, num = 0, n = 0;
    scanf("%d", &h);

    // 2������
    printf("2 ");

    //����3��h����
    for (i = 3; i < h && n < 9; i++)
    { //�жϸ����ǲ���������������ǣ���break���������ǵĻ������
        for (k = 2; k < i; k++)
        {
            if (i % k == 0)
            {   
                break;
            }
        }
        //�ж��Ƿ�Ϊ����
        if(k==i){
            printf("%d ", i);
            n++;
        }
    }
}
// 4���� С��һ������ʮ������