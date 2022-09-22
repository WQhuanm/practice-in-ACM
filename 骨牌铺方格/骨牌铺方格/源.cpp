#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
int main() {
	int n;                 
	while (scanf("%d", &n) == 1) {
		long long f1 = 1,f2 = 2, fn = 0;   //不是只有fn要long long，都要，后面都会爆炸的
		if (n == 1) {
			printf("1\n");
		}
		if (n == 2) {
			printf("2\n");
		}
		if (n >= 3) {
			for (int i = 3; i <= n; ++i) {
				fn = f1 + f2;
				f1 = f2; f2 = fn;
			}
			printf("%lld\n", fn);
		}
	}
}