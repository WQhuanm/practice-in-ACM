#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
const int w = 1e5;
int min[w] = { 0 };
int main()
{
	int n,h=1;
	while (scanf("%d", &n) == 1)
	{
		int h = 1;
		int min[w] = { 0 }; min[1] = 30000;
		for (int i = 1; i <= n; ++i) {   //第i颗导弹
			int x;
			scanf("%d", &x);
			
			//h为目前拥有系统数量
			int k=1;
			for ( k = 1; k <= h; ++k)    //导弹与每个系统比较,
			{
				if (x < min[k])
				{
					min[k] = x;
					goto abc;
				}
				
			}
			h++;
			min[k] = x;


		abc:;
		}
		printf("%d\n", h);
	

	}

	




	return 0;
}