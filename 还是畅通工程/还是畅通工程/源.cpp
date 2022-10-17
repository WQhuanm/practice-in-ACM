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



某省调查乡村交通状况，得到的统计表中列出了任意两村庄间的距离。省政府“畅通工程”的目标是使全省任何两个村庄间都可以实现公路交通（但不一定有直接的公路相连，只要能间接通过公路可达即可），并要求铺设的公路总长度为最小。请计算最小的公路总长度。
Input
测试输入包含若干测试用例。每个测试用例的第1行给出村庄数目N ( < 100 )；随后的N(N-1)/2行对应村庄间的距离，每行给出一对正整数，分别是两个村庄的编号，以及此两村庄间的距离。为简单起见，村庄从1到N编号。
当N为0时，输入结束，该用例不被处理。
Output
对每个测试用例，在1行里输出最小的公路总长度。
