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
				fn = 2*f1 + f2;   //*2����*3����Ϊfn-2����һ��ȫ��2*1��ֱ��ʵ������fn-1��ȫ����ֱ�ظ���
				f1 = f2; f2 = fn;
			}
			printf("%lld\n", fn);
		}
	}
	return 0;
}