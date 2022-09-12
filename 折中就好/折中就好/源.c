#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<math.h>
int arr[30][30] = { 0 };
int main()
{
	int N;
	while (scanf("%d", &N) == 1)//表示接下来有这组有N个正整数
	{
		int sum = 0; double min = 2e9; double ret = 0;
		for (int i = 1; i <= N; i++)              //输入数据算出总和
		{
			for (int j = 1; j <= N; j++)
			{
				scanf("%d", &arr[i][j]);
				sum = sum + arr[i][j];
			}


		}
		double average = (1.0 * sum) / N / N;
		printf("%.2lf ", average);
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				ret = fabs(arr[i][j] - average);
				if (ret < min)
					min = ret;
			}
		}

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (min == fabs(arr[i][j] - average))
				{
					printf("%d %d\n", i, j);
					goto abc;
				}
			}

		}
	abc:;
	}
	return 0;
}