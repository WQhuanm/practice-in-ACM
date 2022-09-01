#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>

int main()
{
	int C,N;
	while (scanf("%d", &C) != EOF)
	{
		scanf("%d", &N);
		int i; int sum = 0; int a = 0;
		int arr[] = { 0 };
		for (i = 2; i <= N; i++)
		{
		  sum = arr[i-1];
			scanf("%d", &arr[i]);
			sum = arr[i] + sum;
		}
		double aver = sum / N;
		printf("%.2lf ", aver);
		for (i = 2; i <= N; i++)
		{
			if (arr[i] >= aver)
				a++;
		}
		printf("%d\n", a);


	}
























	return 0;
}

































































































