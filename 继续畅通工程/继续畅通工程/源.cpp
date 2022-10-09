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
//ʡ��������ͨ���̡���Ŀ����ʹȫʡ�κ�������ׯ�䶼����ʵ�ֹ�·��ͨ������һ����ֱ�ӵĹ�·������ֻҪ�ܼ��ͨ����·�ɴＴ�ɣ����ֵõ������·ͳ�Ʊ������г���������������޽���·�ķ��ã��Լ��õ�·�Ƿ��Ѿ���ͨ��״̬���������д���򣬼����ȫʡ��ͨ��Ҫ����ͳɱ���
//Input
//��������������ɲ���������ÿ�����������ĵ�1�и�����ׯ��ĿN(1 < N < 100)������ N(N - 1) / 2 �ж�Ӧ��ׯ���·�ĳɱ����޽�״̬��ÿ�и�4�����������ֱ���������ׯ�ı�ţ���1��ŵ�N����������ׯ���·�ĳɱ����Լ��޽�״̬��1��ʾ�ѽ���0��ʾδ����
//
//	��NΪ0ʱ���������
//	Output
//	ÿ���������������ռһ�У����ȫʡ��ͨ��Ҫ����ͳɱ���