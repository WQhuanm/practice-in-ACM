#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
int main()
{
	int C;//ÓÐC×é
	scanf("%d", &C);
	int n;
	int i;
	for (i = 0; i < C; i++)
	{
		scanf("%d", &n);
		while (n )
		{
			if (n % 2 == 0)
				n = n / 2;
			else if (n % 3 == 0)
				n = n / 3;
			else if (n % 5 == 0)
				n = n / 5;
			else if (n % 7 == 0)
				n = n / 7;
			else
				break;
		}
		if (n == 1)
			printf("Yes\n");
		else if (n != 1)
			printf("No\n");

	}
	return 0;
}












