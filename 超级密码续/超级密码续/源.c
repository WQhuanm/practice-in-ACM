#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
int main()
{
	int N;   //N��
	while (scanf("%d", &N) == 1 && N != 0)  //NΪ0����������
	{
		char arr1[1100][20] = { 0 };
		int arr2[1100][5] = { 0 };
		int max = -2e9;
		for (int i = 0; i < N; i++)
			scanf("%s", arr1[i]);
		for (int i = 0; i < N; i++)    //��ȡת��arr2����
		{
			int lg = strlen(arr1[i]);
			for (int j = 0; j < lg; j++)
			{
				if (arr1[i][j] >= '0' && arr1[i][j] <= '9')
					arr2[i][0] = arr2[i][0] * 10 + arr1[i][j] - '0';
			}

		}
		for (int i = 0; i < N; i++)
		{
			if (arr2[i][0] > max)
				max = arr2[i][0];
		}
		printf("%d\n", max);

	}


	return 0;
}





















