#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>


#include<math.h>




int main()
{
	char arr[10] = { 0 };
	while (scanf("%s", arr) == 1)
	{
		int len = strlen(arr);
		int sum = 0;
		for (int i = len - 1; i >= 0; --i)
		{
			int h = len - 1 - i;
			int pin = pow(16, h);
			if (arr[i] >= '0' && arr[i] <= '9')
			{

				sum += (arr[i] - '0') * pin;
			}
			if (arr[i] >= 'A' && arr[i] <= 'F')
			{
				int m = arr[i] - 'A' + 10;
				sum += m * pin;
			}
			if (arr[i] >= 'a' && arr[i] <= 'f')
			{
				int n = arr[i] - 'a' + 10;
				sum += n * pin;

			}
			if (arr[i] < '0' || (arr[i] > '9' && arr[i] < 'A') || (arr[i] > 'F' && arr[i] < 'a') || arr[i]>'f')
			{
				printf("Error!\n");
				goto abc;
			}

		}
		printf("%d\n", sum);
	abc:;
	}
	return 0;
}



