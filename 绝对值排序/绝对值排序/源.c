#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int n;
	while (scanf("%d", &n) == 1 && n != 0)
	{
		int arr[110] = { 0 };
		for (int i = 0; i < n; i++)   //输入并存入数组
		{
			
			scanf("%d", &arr[i]);
			

		}
		for (int i = 0; i < n; i++)  //排序(比较绝对值）
		{
			for (int j = i; j < n; j++)
			{
				if (abs(arr[j]) > abs(arr[j + 1]))
					break;
				if (abs(arr[j]) < abs(arr[j + 1]))
				{
					int emp = 0;
					emp = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = emp;
					for (int h = j; h > 0; h--)
					{
						if (abs(arr[h]) > abs(arr[h - 1]))
						{
							int ret = arr[h];
							arr[h] = arr[h - 1]; arr[h - 1] = ret;
						}
					}

				}

			}




		}

		for (int i = 0; i < n; i++)
		{
			if (i != n - 1)
				printf("%d ", arr[i]);
			else
				printf("%d\n", arr[i]);

		}
		
	}





	return 0;
}




















