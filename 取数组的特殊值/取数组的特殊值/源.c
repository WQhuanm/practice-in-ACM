#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>       
//����ֱ��תΪ���͵ķ���
int main()
{
	int N;
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++)
	{
		int ret = 0;
		char arr1[40] = { 0 }; char arr2[40] = { 0 };
		gets(arr1);            //��Ҫ��scanf�������飬�����ո��û��
		int b = strlen(arr1);
		for (int a = 0; a < b; a++)
		{
			if (arr1[a] >= '0' && arr1[a] <= '9')
				ret = ret * 10 + arr1[a]-'0';    //ǰ���*10�����¸�λ������        -'0'����Ϊ�����������������3��������'3'
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
//	scanf("%d", &N);  //��N��
//	getchar();
//	int i = 0; int sum = 0;
//	for (i = 0; i < N; i++)
//	{
//		char arr1[100] = { 0 }; char arr2[40] = { 0 };         //32λ��������ָint,����32�����֣�64λָlong long
//		gets(arr1);    //��������ַ���
//		int a = 0, d = 0;
//		int b = strlen(arr1);
//		for (a = 0; a < b; a++)
//		{
//			if (arr1[a] <= '9' && arr1[a] >= '0')
//			{
//				arr2[d] = arr1[a];    //��ȡ�ַ���������ת����һ����
//				d++;
//			}
//		}
//		int h;
//		sscanf(arr2, "%d", &h);   //������תΪ����
//		sum = h * 513;
//		printf("%d\n", sum);
//	}
//	return 0;
//}

           











