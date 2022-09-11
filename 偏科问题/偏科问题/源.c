#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int N;
	while (scanf("%d", &N) == 1)   //N人
	{
		char name[50][10] = { 0 }; int num[50][5] = { 0 }; int lose[50][2] = { 0 };
		for (int i = 0; i < N; i++)
			scanf("%s %d %d", name[i], &num[i][0], &num[i][1]);         //输入数据
		int max = -2e9, min = 2e9;
		for (int i = 0; i < N; i++)           //算最大偏差
		{
			 lose[i][0] = fabs(num[i][0] - num[i][1]);
			if (lose[i][0] >= max)
				max = lose[i][0];
		}
		for (int i = 0; i < N; i++)             //打印第一个
		{
			if (lose[i][0] == max)
			{
				printf("%s ", name[i]);
				break;
			}
		}
		for (int i = 0; i < N; i++)           //找离最大偏差最近的第二偏差
		{
			int ret = fabs(max - lose[i][0]);
			if (min > ret && ret != 0)
				min = ret;
		}
		for (int i = 0; i < N; i++)        //打印第二个
		{
			if (fabs(max - lose[i][0]) == min)
			{
				printf("%s\n", name[i]);
				break;
			}
		}
	}


	return 0;
}





















