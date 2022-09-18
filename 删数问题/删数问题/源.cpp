#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
                         //给定一个长度不超过30位的由'1'-'9'组成的正整数N，要求删除其中的K位数字，
                         //在不改变数字原来的相对顺序的前提下，请告诉我们，剩下的数字组成的最小的正整数是多少？

           //首先，删去越左边的数越好
             //然后，并不是只比较第一个或者第二个，假设比较完2大于1的，删去第二个，如果第三个比第二个还要大，这样就变成比删去第三个得到的数字大了，
                //所以，应该从左边找递增数列，删去最后一个，这样才是最贪心
int main() {
	int  K; char N[50] = { 0 }; 
	while (scanf("%s %d", &N, &K) == 2) {
		int len = strlen(N);
		for (int i = 1; i <= K; ++i) {    //删去第K个数
			int j = 0;
			for (j = 0; j <len-1; ++j) {    //找出左边递增数列的最后一个，删去
				if (N[j] >= N[j + 1])
					break;
			}
			int k = 0;
			for ( k = j; k < len - 1; ++k) {
				N[k] = N[k + 1];
			}
			N[k] = '\0';

		}
		printf("%s\n", N);

	}





	return 0;
}