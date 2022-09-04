#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
int main()
{
	int N;
	while (scanf("%d", &N) !=EOF)
	{
		if (0 == N)
			break;
		for (int j = 1; j <= N; j++)         //ÑùÀý
		{
			for (int i = 1; i <= j; i++)
			{
				printf("%d*%d=%d ", i, j, i * j);

			}
			printf("\n");
		}
		printf("\n");
	}
	
	return 0;
}



















