#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
void swap(char arr1[100], char arr2[100])
{
	char arr3[100] = { 0 };
	int b = strlen(arr1);
	int c = strlen(arr2);
	for (int i = 0; i <= b;  ++i)   //for循环i++效果与++i等效，但是++i速度快一点
	{
		arr3[i] = arr1[i];
	}
	
	for (int i = 0; i <= c;  ++i)
	{
		arr1[i] = arr2[i];
	}

	for (int i = 0; i <= b; ++i)
	{
		arr2[i] = arr3[i];
	}
}
int main()
{
	int C;
	scanf("%d", &C);
	for (int i = 0; i < C; i++)
	{
		int N, M;
		scanf("%d %d", &N, &M);
		char name[1100][15] = { 0 };
		int num[1100][5] = { 0 };
		for (int j = 0; j < N; j++)
		{
			scanf("%s %d %d", name[j], &num[j][0], &num[j][1]);
		}
		for (int k = 0; k < N; k++)
		{
			for (int j = k; j < N; j++)
			{
				int ret1, ret2; char ret3[100] = { 0 };
				if (num[j][0] < num[j + 1][0])
				{
					ret1 = num[j][0];
					num[j][0] = num[j + 1][0];
					num[j + 1][0] = ret1;
					ret2 = num[j][1];
					num[j][1] = num[j + 1][1];
					num[j + 1][1] = ret2;
					swap(name[j], name[j + 1]);
					for (int h = j; h> 0; h--)
					{
						if (num[h][0] > num[h - 1][0])
						{
							ret1 = num[h][0];
							num[h][0] = num[h-1][0];
							num[h-1][0] = ret1;
							ret2 = num[h][1];
							num[h][1] = num[h-1][1];
							num[h-1][1] = ret2;
							swap(name[h], name[h - 1]);


						}
					}
				}

			}

		}

		for (int k = 0; k < N; k++)
		{
			for (int j = k; j < N; j++)
			{
				int ret1, ret2; char ret3[100] = { 0 };
				if (num[j][0] == num[j + 1][0] && num[j][1] > num[j+1][1])
				{

					ret1 = num[j][0];
					num[j][0] = num[j + 1][0];
					num[j + 1][0] = ret1;
					ret2 = num[j][1];
					num[j][1] = num[j + 1][1];
					num[j + 1][1] = ret2;
					swap(name[j], name[j + 1]);
					for (int h = j; h > 0; h--)
					{
						if (num[h][1] < num[h - 1][1] &&num[h][0]==num[h-1][0])
						{
							ret1 = num[h][0];
							num[h][0] = num[h - 1][0];
							num[h - 1][0] = ret1;
							ret2 = num[h][1];
							num[h][1] = num[h - 1][1];
							num[h - 1][1] = ret2;
							swap(name[h], name[h - 1]);


						}
					}

				}


			}



		}

		for (int k = 0; k < M; k++)
		{
			printf("%s %d %d\n", name[k], num[k][0], num[k][1]);

		}
		printf("\n");




	}

	return 0;
}

