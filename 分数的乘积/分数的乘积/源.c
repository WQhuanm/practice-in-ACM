#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>

int main()
{
	int C;
	scanf("%d", &C);  //C组
	for (int i = 0; i < C; i++)
	{
		int a, b, c, d,x;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		int e = a * c; int f = b * d;
		int e1 = e; int f1 = f;
		while (f1 != 0)  //求分子分母公约数
		{
			x = e1 % f1; e1 = f1; f1 = x;
		}
		printf("%d %d\n", e / e1, f / e1);


	}

	return 0;
}
















