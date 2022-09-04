#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
//    //字符三角形一
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

      //字符三角形二
int main()
{
	int C;   //有C组
	scanf("%d", &C);
	for (int i = 0; i < C; i++)
	{
		int N;
		scanf("%d", &N);
		int mid = N / 2;
		int l = mid;
		for (int a = 1; a <= N; a++)   //第a行
		{
			for (int b = 0; b <N-a; b++)//第a行的空格
			{
				printf(" ");
				l--;
			}
			for (int c = 0; c < 2*a-1; c++)//第a行的*
			{
				printf("*");
			}
			printf("\n");
	}
		
		

	}

	return 0;
}
