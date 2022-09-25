#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
int main() {
	int N;
	scanf("%d", &N);
	while (N--) {
		int M;
		scanf("%d", &M);
		int f2 = 1; int f3 = 2; int fn = 0;
		if (M == 2) {
			printf("1\n");
		}
		if (M == 3) {
			printf("2\n");
		}
		for (int i = 4; i <= M; ++i) {            //n阶，如果最后走俩阶，则前面情况是fn-2阶的走法，如果最后走1阶，则前面是fn-1的走法
			fn = f2 + f3;
			f2 = f3; f3 = fn;
		}
		if (M >= 4) {
			printf("%d\n", fn);
		}
	
	}
	return 0;
}
