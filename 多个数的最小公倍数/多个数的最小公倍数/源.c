#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
int min(int x,int y,int*ph)    //求俩数最小公倍数
{
	int r; int a = x; int b = y;
	while (y != 0)
	{
		r = x % y;
		x = y; y = r;
	}
	int maxy = x;
	 *ph=(a / x) * b;
	 return *ph;
}
int main()
{
	int C, N;    //有C组,每组N个数
	scanf("%d", &C); int h=0;
	for (int i = 0; i < C; i++)
	{
		scanf("%d", &N);
		int m=0,n=0,h=0;
		scanf("%d", &m);
		for (int j = 1; j < N; j++)
		{
			scanf("%d", &n);
			min(m, n, &h);
			m = h;
		}
		printf("%d\n",h);
		
		
	}


	return 0;
}






















