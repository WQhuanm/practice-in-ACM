#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int dp[10000];

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int N;
		scanf("%d", &N);
		memset(dp, 0, sizeof(dp));
		dp[0] = N;
		int n150 = 0, n200 = 0, n350 = 0;
		int i = 0;
		for ( i = 1; dp[i - 1] >=0; ++i) {
			dp[i] = max(dp[n150] - 150, max(dp[n200] - 200, dp[n350] - 350));
			if (dp[i] == dp[n150] - 150)n150++;
			if (dp[i] == dp[n200] - 200)n200++;
			if (dp[i] == dp[n350] - 350)n350++;
		}
		for (int j = i-1; j >= 0; --j) {
			if (dp[j] >= 0)
			{
				printf("%d\n", dp[j]);
				break;
			}
		}
	}
	return 0;
}