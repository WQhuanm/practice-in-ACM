#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
//    //�ַ�������һ
//int main()
//{
//	int N;
//	while(scanf("%d", &N) !=EOF )
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j <= i; j++)
//		{
//			printf("*");
//
//		}
//		printf("\n");
//
//
//
//	}
//
//
//	return 0;
//}

      //�ַ������ζ�
int main()
{
	int C;   //��C��
	scanf("%d", &C);
	for (int i = 0; i < C; i++)
	{
		int N;
		scanf("%d", &N);
		int mid = N / 2;
		int l = mid;
		for (int a = 1; a <= N; a++)   //��a��
		{
			for (int b = 0; b <N-a; b++)//��a�еĿո�
			{
				printf(" ");
				l--;
			}
			for (int c = 0; c < 2*a-1; c++)//��a�е�*
			{
				printf("*");
			}
			printf("\n");
	}
		
		

	}

	return 0;
}
