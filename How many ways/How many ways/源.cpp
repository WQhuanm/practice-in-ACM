#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#define ll long long
using namespace std;

                                 //����dfs��ȥ�����ظ���Σ�TLE������Ӧ�ô����յ�����ĵ㿪ʼ�������ÿ����ȥ�յ��·��������֤���ظ�

const int N = 110;
int a[N][N];
int b[N][N];
int t, n, m;
ll ans,sum;

int dfs(int x, int y) {
	if (b[x][y] != -1)return b[x][y]%10000;//�����Ϊ0-1��֤���Ѿ���¼��������·����
	b[x][y] = 0;//��-1֤���ǵ�һ�γ�ʼ������Ϊ0

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
		memset(b, -1, sizeof(b));//·������ʼ������Ϊ0����Ϊ�п��������������������ǵ������յ�
		b[n][m] = 1;//Ϊ1����ǰ�����ֱ���յ�ĸ��ӵ�����ͼ�һ�����Ը�ֵ1
		cout << dfs(1, 1) << endl;
	}
	return 0;
}