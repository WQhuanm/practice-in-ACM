#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>

int main()
{
	int C,N;  //C����ԣ�N��ͬѧ
	scanf("%d", &C);
	int i,a;
	int arr[100] = { 0 };
	
	for (i = 0; i < C; i++)  //�ڼ���
	{
		float sum1 = 0, sum2 = 0, l = 0, average;
		scanf("%d", &N);
		for (a = 0; a < N; a++)   //����ͬѧ�ǵĳɼ�
		{
			scanf("%d", &arr[a]);
			sum1 = arr[a] + sum1;  //�ɼ���

		}
		average = sum1 / N;
		printf("%.2f ", average);
		for (a = 0; a < N; a++)
		{
			if (arr[a] >= average)
				l = arr[a] - average;
			else if (arr[a] < average)
				l = average - arr[a];

			sum2 = sum2 + l;
			
		}
		printf("%.2f\n", sum2);
		int arr[100] = { 0 };
	}




	return 0;
}









