#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
//int main()
//{
//	int T;
//	scanf("%d", &T);
//	while (T--) {
//		long long  N;
//		scanf("%lld", &N);
//		int arr[100] = { 0 }; int count = 0;               
//		long long one = 1;
//			for (int i = 1; i <= count+1; ++i) {    
//				one = (N * one) % 10;        //oneΪÿ��*N��ĸ�λ��
//				for (int k = 1; k <= count+1; ++k) {   //��one���������Ѿ���������Ƚϣ���ѭ���бȽϸ�λ����û����ͬ���������飬��ͬ��������ͳ���м��ָ�λ��(��count��
//					if (arr[k] == one) {    
//						goto abc;
//					}
//				}
//				count++;
//				arr[i] =one;
//			}
//		abc:
//			
//			if (count == 0)   //����һ��Ҫ������û�п��ܳ���Ϊ0
//				printf("0\n");
//			else {
//				arr[0] = arr[count];
//				int yu = N % count;
//				printf("%d\n", arr[yu]);
//			}
//				
//	}
//	return 0;
//}