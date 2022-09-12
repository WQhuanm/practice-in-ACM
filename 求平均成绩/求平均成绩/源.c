#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>

int main()
{
	int m, n,sumx=0,sumy=0;   //n人，m科目
	
	while (scanf("%d %d", &n, &m) == 2)
	{
		int arr[60][10] = { 0 }; int st = 0;
		for (int x = 1; x <= n; x++)    //第x人
		{
			for (int y = 1; y <= m; y++)   //第y科目
			{
				scanf("%d", &arr[x][y]);

			}
		}
		int flag = 1;
		for (int x = 1; x <= n; x++) //第x人的所有科目平均
		{
			sumx = 0; 
			for (int y = 1; y <= m; y++)
			{
				sumx = sumx + arr[x][y];
			}
			
			if (flag == 1)
				flag = 0;
			else
				printf(" ");
			printf("%.2lf", sumx*1.0/m);

		}
		printf("\n");
		int fla = 1;
		for (int y = 1; y <= m; y++)         //第y科目的平均
		{
			sumy = 0; 
			for (int x = 1; x <= n; x++)
			{
				sumy = sumy + arr[x][y];
			}
			
			if (fla == 1)
				fla = 0;
			else
				printf(" ");
			printf("%.2lf", sumy * 1.0 / n);
		}
		printf("\n");
		for (int x = 1; x <= n; x++)     //第x人比较平均
		{
			int count = 0;   //计数大于平均分的科目数
			for (int y = 1; y <= m; y++)   //比较第y科目
			{
				sumy = 0;
				for (int i = 1; i<= n; i++)  //第i人
				{
					sumy = sumy + arr[i][y];
				}
				double h = sumy * 1.0 / n;
				if (arr[x][y]>=h)
					count++;   //有一个科目大平均就+1
			}
			if (count == m)
				st++;
			
		}
		printf("%d\n\n", st);


	}
	return 0;
}


//优化版
int main()
{
	int m, n; double sumx = 0, sumy = 0;   //n人，m科目

	while (scanf("%d %d", &n, &m) == 2)
	{
		int arr[60][10] = { 0 }; int st = 0;
		for (int x = 1; x <= n; x++)    //第x人
		{
			for (int y = 1; y <= m; y++)   //第y科目
			{
				scanf("%d", &arr[x][y]);
			}
		}

		for (int x = 1; x <= n; x++) //第x人的所有科目平均
		{
			sumx = 0;
			for (int y = 1; y <= m; y++)
			{
				sumx = sumx + arr[x][y];
			}
			printf("%.2lf", sumx / m);
			if (x != n)               //使中间打印空格，最后不是空格而是\n的第二种方法，就是x！=n，即只要这个字符不是打印的最后一个，就在其后打印空格，如果是最后一个，打印\n
				printf(" ");
			else
				printf("\n");
		}

		double avg[60] = { 0 };    //对于后面需要的一组平均数，应该选择存入数组，方便后面直接使用，而不是等下重新计算一遍
		for (int y = 1; y <= m; y++)         //第y科目的平均
		{
			sumy = 0;
			for (int x = 1; x <= n; x++)
			{
				sumy = +arr[x][y];  //比sumy = sumy + arr[x][y];省略
			}
			avg[y] = sumy/n;
			printf("%.2lf", sumy * 1.0 / n);
			if (y != m)
				printf(" ");
			else
				printf("\n");
		}

		for (int x = 1; x <= n; x++)     //第x人比较平均
		{
			int count = 0;   //计数大于平均分的科目数
			for (int y = 1; y <= m; y++)   //比较第y科目
			{
				if (arr[x][y] >= avg[y])
					count++;   //有一个科目大平均就+1
			}
			if (count == m)
				st++;
		}
		printf("%d\n\n", st);
	}
	return 0;
}





















