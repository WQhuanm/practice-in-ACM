#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
   //比赛评分
int main()
{
	int C = 0;
	while (scanf("%d", &C) !=EOF)    //C表示评委人数
	{
		int a,max = 0, min = 2e9;
		float sum=0;
		int arr[1000] = { 0 };
		for (a = 1; a <= C; a++)
		{
			scanf("%d", &arr[a]);  //输入分数   
			if (arr[a] >= max)
				max=arr[a];
			else if (arr[a] <= min)
				min = arr[a];
			sum = arr[a] + sum;
			
		}
		sum = sum - min - max;
		
		float average = sum / (C - 2);
		printf("%.2f\n", average);
	}
	return 0;
}
















































































































