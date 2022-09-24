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
				fn = f1 * 2 + f2;              //fn-1时，n-1的格子与第一个一定不同，fn-2时，n-2的格子与第一个不同，所以n-1可以与第一个同，这样n有俩种色可以选
				f1 = f2; f2 = fn;         //或者一种另一种色，这样n只有一种色可以选，但是，这样并不意味着f1*3，因为当n-1与第一个同时，实际上是f2的其中一部分情况（不是全部，因为f2没要求n-2一定与第一个不同），重复了
			}
			printf("%lld\n", fn);
		}

	}
}
