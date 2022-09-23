#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		if (n == 1) {
			printf("1\n");
		}
		if (n == 2)printf("3\n");
		if (n >= 3) {
			long long f1 = 1, f2 = 3, fn = 0;
			for (int i = 3; i <= n; ++i) {
				fn = 2*f1 + f2;   //*2不是*3，因为fn-2会有一种全是2*1竖直的实际上与fn-1的全是竖直重复了
				f1 = f2; f2 = fn;
			}
			printf("%lld\n", fn);
		}
	}
	return 0;
}