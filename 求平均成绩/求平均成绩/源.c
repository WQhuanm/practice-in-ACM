#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>

int main()
{
	int m, n,sumx=0,sumy=0;   //n�ˣ�m��Ŀ
	
	while (scanf("%d %d", &n, &m) == 2)
	{
		int arr[60][10] = { 0 }; int st = 0;
		for (int x = 1; x <= n; x++)    //��x��
		{
			for (int y = 1; y <= m; y++)   //��y��Ŀ
			{
				scanf("%d", &arr[x][y]);

			}
		}
		int flag = 1;
		for (int x = 1; x <= n; x++) //��x�˵����п�Ŀƽ��
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
		for (int y = 1; y <= m; y++)         //��y��Ŀ��ƽ��
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
		for (int x = 1; x <= n; x++)     //��x�˱Ƚ�ƽ��
		{
			int count = 0;   //��������ƽ���ֵĿ�Ŀ��
			for (int y = 1; y <= m; y++)   //�Ƚϵ�y��Ŀ
			{
				sumy = 0;
				for (int i = 1; i<= n; i++)  //��i��
				{
					sumy = sumy + arr[i][y];
				}
				double h = sumy * 1.0 / n;
				if (arr[x][y]>=h)
					count++;   //��һ����Ŀ��ƽ����+1
			}
			if (count == m)
				st++;
			
		}
		printf("%d\n\n", st);


	}
	return 0;
}
























