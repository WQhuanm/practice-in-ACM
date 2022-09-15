#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include <algorithm>
using namespace std;

bool emp(int x, int y)
{
	return x > y;
}
int main()
{
	int n;
	while (scanf("%d", &n) == 1 && n)
	{
		int money = 0;
		int tian[1100] = { 0 };
		int king[1100] = { 0 };
		for (int i = 0; i < n; ++i)  //输入田忌的马
		{
			scanf("%d", &tian[i]);
		}
		for (int i = 0; i < n; ++i)   //输入齐王的马
		{
			scanf("%d", &king[i]);
		}
		            //对俩者的马分别按照速度从大到小排序
			sort(tian, tian + n, emp);
			sort(king, king + n, emp);
		
		int best = 0, worst = n - 1;
		
		for (int i = 0; i < n; ++i)    //
		{
			int re = n - 1 - i;
			if (tian[best] <= king[i])
			{
				worst -= 1;
				money -= 200;
				continue;
			}
			else
			{
				best += 1;
				money += 200;
				continue;
			}


		}
		printf("%d\n", money);

	}

	return 0;
}