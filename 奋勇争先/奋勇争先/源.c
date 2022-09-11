#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
int main()
{
	int C, N; char name[1000][10]; int num[1000][2];
	scanf("%d", &C);
	for (int j = 0; j < C; j++)     //C组测试
	{
		scanf("%d", &N);   //N个人
		char name[1100][10] = { 0 }; int num[1100][5] = { 0 };
		int max = -2e9,min=2e9;
		for (int i = 0; i < N; i++)
		{
			scanf("%s %d %d", &name[i], &num[i][0], &num[i][1]);
			if (num[i][0] > max)
				max = num[i][0];

		}             //找出最大解题数
		for (int i = 0; i < N; i++)
		{
			if (num[i][0] == max)       //找出最大解题数的人的最小罚时
				if (num[i][1] < min)
					min = num[i][1];
				}
		for (int i = 0; i < N; i++)
		{
			if (num[i][0] == max && num[i][1] == min)
				printf("%s %d %d\n", name[i], num[i][0], num[i][1]);
			}

	}
	return 0;
}























