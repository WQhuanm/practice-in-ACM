#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#define ll long long
using namespace std;

bool cmp(ll x, ll y) {
	return x > y;
}
const int N = 1e7 + 100;

ll a[N];

int main() {
	int n, m;
	while (~scanf("%d%d",&n,&m)) {   //大数组用cin，cout会超时
		for (int i = 1; i <= n; ++i)scanf("%lld",&a[i]);
		sort(a + 1, a + 1 + n, cmp);
		for (int i = 1; i <= m; ++i) {
			printf("%lld",a[i]);
			if (i == m)printf("\n");
			else printf(" ");
		}

	}


}