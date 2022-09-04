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


//
//int main()
//{
//	int N = 0;
//	scanf("%d", &N);  //有N组
//	getchar();
//	int i = 0; int sum = 0;
//	for (i = 0; i < N; i++)
//	{
//		char arr1[100] = { 0 }; char arr2[40] = { 0 };         //32位类型整数指int,不是32个数字，64位指long long
//		gets(arr1);    //输入测试字符串
//		int a = 0, d = 0;
//		int b = strlen(arr1);
//		for (a = 0; a < b; a++)
//		{
//			if (arr1[a] <= '9' && arr1[a] >= '0')
//			{
//				arr2[d] = arr1[a];    //提取字符串中数字转到另一数组
//				d++;
//			}
//		}
//		int h;
//		sscanf(arr2, "%d", &h);   //把数组转为整型
//		sum = h * 513;
//		printf("%d\n", sum);
//	}
//	return 0;
//}

           











