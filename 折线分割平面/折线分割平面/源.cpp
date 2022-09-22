#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
int main() {
	int C;
	scanf("%d", &C);
	while (C--) {
		int n;
		scanf("%d", &n);
		long long f1 = 2,fn=0;
		if (n == 1)printf("2\n");
		if (n >= 2) {
			for (int i = 2; i <= n; ++i) {
				fn = 4 * (i - 1) + 1 + f1;
				f1 = fn;
			}
			printf("%lld\n", fn);
		}
	}
}