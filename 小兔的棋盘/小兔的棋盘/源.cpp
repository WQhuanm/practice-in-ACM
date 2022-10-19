#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#define ll long long 
using namespace std;

const int N = 40;
ll way[2][2] = { {1,0},{0,1} };
ll a[N][N];
ll book[N][N];
ll dfs(ll x,ll y) {
	if (a[x][y])return a[x][y];
	for (ll i = 0; i <= 1; ++i) {
		ll tx = x + way[i][0];
		ll ty = y + way[i][1];
		if (book[tx][ty])a[x][y] += dfs(tx, ty);
	}
	return a[x][y];
}


int main() {
	ll n,num=0;//dfs多用ll，这里int是WA
	
	while (cin >> n && n != -1) {
		for (ll i = 0; i <= n; ++i)for (ll j = 0; j <= i; ++j)book[i][j] = 1;//可以走的范围
		memset(a, 0, sizeof(a));
		a[n][n] = 1;  //dfs逆向走法，终点必须为1，保证叠加时从1开始
		dfs(0,0);
		cout << ++num <<" "<< n <<" " << a[0][0]*2<<endl;


	}

	return 0;
}