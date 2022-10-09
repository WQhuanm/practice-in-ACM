#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
const int N = 100000;
const int K = 10001;
int fa[K];

struct me {
	int a; int b; int lu;
}arr[N];

bool cmp(me x, me y) {
	return x.lu < y.lu;
}

int find(int x) {
	if (x != fa[x])	fa[x] = find(fa[x]);
	return fa[x];
}

int unit(me x,int n) {
	if (find(x.a) == find(x.b))return 0;
	else {
		fa[find(x.b)] = find(x.a); //必须比较或者变换都是用find(t),而不是fa[t](你有可能只是上级，但不是最上级，所以变换必须加find
		return x.lu;
	}
}


int main() {
	int n;
	while (scanf("%d", &n) == 1 && n) {
		memset(arr, 0, sizeof(arr));
		memset(fa, 0, sizeof(fa));
		for (int i = 1; i <= n; ++i)fa[i] = i;
		for (int i = 1; i <= n * (n - 1) / 2; ++i)scanf("%d %d %d", &arr[i].a, &arr[i].b, &arr[i].lu);
		sort(arr+1, arr+1+( n * (n - 1) / 2), cmp);    //不是到arr+1+n,因为arr的数量是到n * (n - 1) / 2
		int sum = 0;
		for (int i = 1; i <= n * (n - 1) / 2; ++i) {   //处理的是arr的n * (n - 1) / 2组数据，不止有n组
			sum += unit(arr[i],n);
		}
		cout << sum <<endl;
	}

	return 0;
}