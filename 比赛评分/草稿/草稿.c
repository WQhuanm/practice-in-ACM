#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
   //��������
int main()
{
	int C = 0;
	while (scanf("%d", &C) !=EOF)    //C��ʾ��ί����
	{
		int a,max = 0, min = 2e9;
		float sum=0;
		int arr[1000] = { 0 };
		for (a = 1; a <= C; a++)
		{
			scanf("%d", &arr[a]);  //�������   
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
















































































































