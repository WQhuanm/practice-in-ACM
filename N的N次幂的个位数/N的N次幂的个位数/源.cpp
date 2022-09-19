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
//				one = (N * one) % 10;        //one为每次*N后的个位数
//				for (int k = 1; k <= count+1; ++k) {   //将one与数组中已经存入的数比较，在循环中比较个位数，没有相同，存入数组，相同，跳出，统计有几种个位数(即count）
//					if (arr[k] == one) {    
//						goto abc;
//					}
//				}
//				count++;
//				arr[i] =one;
//			}
//		abc:
//			
//			if (count == 0)   //除法一定要考虑有没有可能除数为0
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