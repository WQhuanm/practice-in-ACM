#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#define ll long long
using namespace std;

                                 //正向dfs过去，会重复多次，TLE，所以应该从离终点最近的点开始，保存从每个点去终点的路径数，保证不重复

const int N = 110;
int a[N][N];
int b[N][N];
int t, n, m;
ll ans,sum;

int dfs(int x, int y) {
	if (b[x][y] != -1)return b[x][y]%10000;//如果不为0-1，证明已经记录过这个点的路径数
	b[x][y] = 0;//是-1证明是第一次初始化，改为0

	for (int i = 1; i <= a[x][y]; ++i)for (int j = 0; j <= i; ++j) {
		int tx = x + j; int ty = y + i - j;
		if (tx<1 || tx>n || ty<1 || ty>m)continue;
		b[x][y] += dfs(tx, ty)%10000;


	}
	return b[x][y]%10000;

}

int main() {
	
	cin >> t;
	while (t--) {
		ans = 0; sum = 0;
		cin >> n >> m;
		for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)cin >> a[i][j];
		memset(b, -1, sizeof(b));//路径数初始化不能为0，因为有可能算完从他这里出发就是到不了终点
		b[n][m] = 1;//为1，让前面可以直达终点的格子到这里就加一，所以赋值1
		cout << dfs(1, 1) << endl;
	}
	return 0;
}