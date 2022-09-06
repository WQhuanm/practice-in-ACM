#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int a, b, c, d,r;	
		scanf("%d %d %d %d", &a, &b, &c, &d);   //a,c为分子，b，d为分母
		int un = b * d;
		int on = a * d + c * b;
		int x = on; int y = un;
		while (un != 0)
		{
			r = on % un;
			on = un;
			un = r;

		}
		printf("%d %d\n", x/on, y/on);
	}
	return 0;
}





















