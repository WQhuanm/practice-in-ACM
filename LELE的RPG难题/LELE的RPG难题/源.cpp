#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
int main() {
	int T;
	
	while (scanf("%d", &T)==1) {
		if (T == 1) {
			printf("3\n");
		}
		if (T == 2) {
			printf("6\n");
		}
		if (T == 3)printf("6\n");
		long long f1 =6,f2=6,fn;
		if (T > 3) {
			for (int i = 4; i <= T; ++i) {
				fn = f1 * 2 + f2;
				f1 = f2; f2 = fn;
			}
			printf("%lld\n", fn);
		}

	}
}