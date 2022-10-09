#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>

using namespace std;

const int N = 101;
struct ct {
	int a; int b; int c; int d;
}arr[N * (N - 1) / 2];

int fa[N];

bool cmp(ct x, ct y) {
	return x.c < y.c;
}

int find(int x) {
	if (x != fa[x])fa[x] = find(fa[x]);
	return fa[x];
}

int unit(ct x) {
	if (find(x.a) == find(x.b))return 0;
	else {
		fa[find(x.a)] = find(x.b);
		return x.c;
	}
}

int main() {
	int n;
	while (scanf("%d", &n) == 1 && n) {
		memset(arr, 0, sizeof(arr));
		memset(fa, 0, sizeof(fa));
		for (int i = 1; i <= n; ++i)fa[i] = i;
		for (int i = 1; i <= n * (n - 1) / 2; ++i) {
			scanf("%d %d %d %d", &arr[i].a, &arr[i].b, &arr[i].c, &arr[i].d);
			if (arr[i].d == 1)arr[i].c = 0;
		}
		sort(arr + 1, arr + 1 + n * (n - 1) / 2, cmp);
		int sum = 0;
		for (int i = 1; i <= n * (n - 1) / 2; ++i)sum += unit(arr[i]);

		cout << sum << endl;
	}
	return 0;
}



//Problem Description
//省政府“畅通工程”的目标是使全省任何两个村庄间都可以实现公路交通（但不一定有直接的公路相连，只要能间接通过公路可达即可）。现得到城镇道路统计表，表中列出了任意两城镇间修建道路的费用，以及该道路是否已经修通的状态。现请你编写程序，计算出全省畅通需要的最低成本。
//Input
//测试输入包含若干测试用例。每个测试用例的第1行给出村庄数目N(1 < N < 100)；随后的 N(N - 1) / 2 行对应村庄间道路的成本及修建状态，每行给4个正整数，分别是两个村庄的编号（从1编号到N），此两村庄间道路的成本，以及修建状态：1表示已建，0表示未建。
//
//	当N为0时输入结束。
//	Output
//	每个测试用例的输出占一行，输出全省畅通需要的最低成本。