#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;


const int N = 50;

int dp[N];
int b[N];
int a[N][2];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		memset(b, 0, sizeof(b));
		memset(dp, 0, sizeof(dp));
		
		for (int i = 1; i <= k; ++i) cin >> a[i][0] >> a[i][1];
		dp[0] = 1;//dp[0]Ϊ1�Ǳ�ֻ֤��h�Լ�ʱ��Ҳ����һ�֣������Ǽ�0
		for (int i = 1; i <= k; ++i) {
			for (int j = 0; j <= n; ++j) {
				for (int h = 0; j + h <= n && h <= a[i][0] * a[i][1]; h += a[i][0]) {
					b[j + h] += dp[j];
				}
			}
			for (int j = 0; j <= n; ++j) { dp[j] = b[j]; b[j] = 0; }
		}

		cout << dp[n] << endl;
	}

	return 0;
}