#include <stdio.h>
#pragma warning(disable:4996)

int main()
{

    int input[10];

    for (int i = 0; i < 10; i++)
    {         printf("%d번째 숫자를 입력해주세요 : ", i);
        scanf("%d", &*(input+i));
	}
    
    for(int i = 0; i < 10; i++)
    {
        printf("입력한 정수는 %d 입니다.\n", *(input+i));
    }
	

    return 0;
}