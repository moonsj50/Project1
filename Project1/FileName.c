#include <stdio.h>
#pragma warning(disable:4996)

int main()
{

    int input[10];

    for (int i = 0; i < 10; i++)
    {         printf("%d��° ���ڸ� �Է����ּ��� : ", i);
        scanf("%d", &*(input+i));
	}
    
    for(int i = 0; i < 10; i++)
    {
        printf("�Է��� ������ %d �Դϴ�.\n", *(input+i));
    }
	

    return 0;
}