#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
int main()
{
	int A, B, C, sum;
	while (scanf("%d %d %d", &A, &B, &C) != EOF)  //总成绩 = 作业成绩 × 20% + 小测成绩 × 30% + 期末考试成绩 × 50%
	{
		sum = A * 0.2 + B * 0.3 + C * 0.5;
		printf("%d\n", sum);
	}


	return 0;
}


















