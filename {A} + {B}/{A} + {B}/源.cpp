#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#define ll long long
using namespace std;

bool cmp(int a, int b) {
	return a < b;
}
const int N = 1e5 + 100;
int a[N];
int b[N];

int main() {
	int n, m;
	while (cin >> n >> m) {
		for (int i = 1; i <= n; ++i)cin >> a[i];
		for (int i = 1; i <= m; ++i)cin >> b[i];
		sort(a + 1, a + 1 + n, cmp);
		sort(b + 1, b + 1 + m, cmp);
		int a1 = 1, b1 = 1; int flag = 1;
		if (flag) {
			flag = 0;
			if (a[a1] < b[b1]) {
				printf("%d", a[a1]);
				a1++;
			}
			else if (a[a1] == b[b1]) {
				printf("%d", a[a1]);
				a1++; b1++;
			}
			else {
				printf("%d", b[b1]);
				b1++;

			}
		}

		while (a1 <= n && b1 <= m) {
			if (a[a1] < b[b1]) {
				printf(" %d", a[a1]);
				a1++;
			}
			else if (a[a1] == b[b1]) {
				printf(" %d", a[a1]);
				a1++; b1++;
			}
			else {
				printf(" %d", b[b1]);
				b1++;

			}
		}

		while (a1 <= n) {
			printf(" %d", a[a1]);
			a1++;
		}
		while (b1 <= m) {
			printf(" %d", b[b1]);
			b1++;
		}
		printf("\n");

	}

	return 0;
}