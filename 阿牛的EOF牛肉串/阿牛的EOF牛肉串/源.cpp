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
				fn = 2 * (f1 + f2);          //正难则反，当第n个不为o时，无要求，直接f2*2，当第n个为o时，第n-1个必须不为o，即f1*2得到的第n-1个一定不为o
				f1 = f2; f2 = fn;         
			}                                      
			printf("%lld\n", fn);
		}
	}
	return 0;
}
