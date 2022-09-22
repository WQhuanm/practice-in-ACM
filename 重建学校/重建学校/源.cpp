#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
int main() {
	int c;
	scanf("%d", &c);
	while (c--) {
		int n;
		scanf("%d", &n);
		if (n == 1)printf("1\n");
		if (n == 2)printf("3\n");
		if (n == 3)printf("5\n");
		if (n >= 4) {
			long long f1 = 3, f2 = 5, fn;
			for (int i = 4; i <= n; ++i) {
				fn =  f1*2 + f2;
				f1 = f2; f2 = fn;
			}
			printf("%lld\n", fn);
		}
	}



	return 0;
}