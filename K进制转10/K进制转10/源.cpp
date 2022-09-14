#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	char arr[1000] = { 0 };
	int K;
	while(scanf("%s",arr)==1)
	{
		scanf("%d", &K);
		int len = strlen(arr);
		int sum = 0;
		for (int i = len - 1; i >= 0; i--)
		{
			int h = len - 1 - i;
			int pin = pow(K, h);
			if (K > 0 && K <= 10)
			{
				if (arr[i] >= '0' && arr[i] <= '0' + K - 1)
				{
					sum += (arr[i]-'0') * pin;
				}
				else
				{
					printf("Error!\n");
					goto abc;

				}
			}
			if (K > 10 && K <= 16)
			{
				if (arr[i] >= '0' && arr[i] <= '0' + K - 1)
				{
					sum += (arr[i] - '0') * pin;
				}
				if (arr[i] < '0' || (arr[i] > '9' && arr[i] < 'A') || ((arr[i] > 'A' + K - 11) && arr[i] < 'a') || (arr[i] > 'a' + K - 11))
				{
					printf("Error!\n");
						goto abc;
				}
				if (arr[i] >= 'A' && arr[i] <= 'A' + K - 11)
				{
					int m = arr[i] - 'A' + 10;
					sum += m * pin;
				}
				if (arr[i] >= 'a' && arr[i] <= 'a' + K - 11)
				{
					int m = arr[i] - 'a' + 10;
					sum += m * pin;
				}
				
			}
		}
		printf("%d\n", sum);


	abc:;
		char arr[1000] = { 0 };
	}

	return 0;
}



















