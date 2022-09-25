#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>       
//数组直接转为整型的方法
int main()
{
	int N;
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++)
	{
		int ret = 0;
		char arr1[40] = { 0 }; char arr2[40] = { 0 };
		gets(arr1);            //不要用scanf输入数组，遇到空格就没了
		int b = strlen(arr1);
		for (int a = 0; a < b; a++)
		{
			if (arr1[a] >= '0' && arr1[a] <= '9')
				ret = ret * 10 + arr1[a]-'0';    //前面的*10，留下个位数补填        -'0'是因为数组里面的数字是如3，而不是'3'
		}
		int sum = ret * 513;
		printf("%d\n", sum);
	}


	return 0;
}





