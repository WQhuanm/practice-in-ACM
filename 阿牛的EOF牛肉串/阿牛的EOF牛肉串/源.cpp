#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
int main() {
	int n;
	while (scanf("%d", &n) == 1) {
		if (n == 1)printf("3\n");
		if (n == 2)printf("8\n");
		if (n >= 3) {
			long long f1 = 3, f2 = 8, fn = 0;
			for (int i = 3; i <= n; ++i) {
				fn = 2 * (f1 + f2);
				f1 = f2; f2 = fn;
			}
			printf("%lld\n", fn);
		}
	}
	return 0;
}