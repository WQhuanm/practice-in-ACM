#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
            //�Ӵ�С��������ǰm����
int main()
{
	int C;
	scanf("%d", &C);  //C�����
	for (int i = 0; i < C; i++)
	{
		int N;
		scanf("%d", &N);   //N������
		int M; scanf("%d", &M);   //�Ӵ�С����M����
		int arr[1100] = { 0 };
		for (int j = 0; j < N; j++)   //����
		{
			scanf("%d", &arr[j]);
		}
		for (int j = 0; j < N; j++)          //����(��С��
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





















