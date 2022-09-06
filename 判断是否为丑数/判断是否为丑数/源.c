#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
int main()
{
	int C;
	scanf("%d", &C);
	for (int i = 0; i < C; i++)
	{
		int n;
		while (scanf("%d", &n) != EOF)
		{
			while (n>0)
			{
				if (n % 2 == 0)
					n = n / 2;
				if (n % 3 == 0)
					n = n / 3;
				if (n % 5 == 0)
					n = n / 5;
				if (n % 7 == 0)
					n = n / 7;
				if (n % 2 != 0 && n % 3 != 0 && n % 5 != 0 && n % 7 != 0)
					break;
			}
			if (1 == n)
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	return 0;
}




















