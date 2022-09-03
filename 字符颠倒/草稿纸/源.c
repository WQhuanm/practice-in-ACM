#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>

void swap(char *px,char *py)
{
	char z=0;
	z = *px; 
	*px = *py;
	*py = z;
}
int main()
{
	int N; int i=0;
	scanf("%d", &N);
	getchar();
     int a = 0;
	char arr[1000] = { 0 };
	for(i=0;i<N;i++)
	{
		
		gets(arr);
		int right = strlen(arr)-1;
		int left = 0;
		while (left<right)
		{
			
			if (left < right)
			{
				swap(&arr[left], &arr[right]);
				left++; right--;
				continue;
			}
			else
				break;

		}
		printf("%s\n", arr);
		char arr[1000] = { 0 };
	}
	return 0;
}



























