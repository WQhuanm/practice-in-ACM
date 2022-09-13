#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
            //从大到小排序，输入前m个数
int main()
{
	int C;
	scanf("%d", &C);  //C组测试
	for (int i = 0; i < C; i++)
	{
		int N;
		scanf("%d", &N);   //N个整数
		int M; scanf("%d", &M);   //从大到小输入M个数
		int arr[1100] = { 0 };
		for (int j = 0; j < N; j++)   //储存
		{
			scanf("%d", &arr[j]);
		}
		for (int j = 0; j < N; j++)          //排序(大到小）
		{
			for (int k = j+1; k < N; k++)
			{
				int emp = 0;
				if (arr[j] >=arr[k])
					break;
				if (arr[j] < arr[k])
				{
					emp = arr[j];
					arr[j] = arr[k]; arr[k] = emp;
					for (int h = j; h > 0; h--)
					{
						int ret = 0;
						if (arr[h] > arr[h - 1])
						{
							ret = arr[h];
							arr[h] = arr[h - 1]; arr[h - 1] = ret;
						}

					}

					continue;
				}

			}


		}
		
		for (int i = 0; i < M; i++)
		{
			printf("%d ", arr[i]);

		}
		printf("\n");
	}


	return 0;
}





















