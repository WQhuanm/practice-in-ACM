#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>

int main()
{
	int C;
	scanf("%d", &C);
	for (int i = 0; i < C; ++i)
	{
		int a; int K;
		scanf("%d %d", &a, &K);
		char arr1[100] = { 0 };
		char arr2[100] = { 0 };
		for(int j=0;a>=1;++j)
		{
			int b = a % K;
			if (K < 11)
			{
				arr1[j] = b+'0';
			}
			if (K > 10 && K <= 16)
			{
				if (b < 10)
				{
					arr1[j] = b+'0';
				}
				else
				{
					arr1[j] = b - 10 + 'A';

				}

			}
			if (a == 1)
				break;
			a = a / K;
		}
		int len = strlen(arr1);
		for (int j = 0; j < len; ++j)
		{
			int h = len - 1 - j;
			arr2[j] = arr1[h];

		}
		printf("%s\n", arr2);

	}



	return 0;
}











