#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
int main() {
	int N;
	scanf("%d", &N);
	while (N--) {
		int a, b,f;
		scanf("%d %d", &a, &b);
			f = b-a;
		if (f == 1) {
			printf("1\n");
		}
		if (f == 2) {
			printf("2\n");
		}


		if (f >= 3) {
			long long f1 = 1, f2 = 2;long long fn = 0;
			for (int i = 3; i <= f; ++i) {
				fn = f1 + f2;
				f1 = f2; f2 = fn;
			}
			printf("%lld\n", fn);
		}
	}
	return 0;
}