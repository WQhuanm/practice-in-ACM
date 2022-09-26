#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

                //要使得利益最大化，每次只要 i 个公司 j 台机器利益最大。
             //而 i 个公司 j 台机器利益最大，也就是要 i - 1 个公司有 z 台机器利益最大化 + 第 i 个公司有 j - z 台机器最大利益把所有情况推导一遍就可以。






int dp[110][110];
int arr[110][110];
int main() {
	int n, m;
	while (scanf("%d %d", &n, &m) == 2) {
		memset(dp, 0, sizeof(dp));
		memset(arr, 0, sizeof(dp));
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				scanf("%d", &arr[i][j]);
			}
		}
		
		for (int i = 1; i <= n; ++i) {    //共i家公司
			for (int j = 1; j <= m; ++j) {    //共负责i个机器，j从1开始，至少负责一件
				for (int z = 0; z <= j; ++z) {    //表示前i-1个公司共负责了z个机器，z是从0开始的，因为前i-1个公司是可以不负责的
					dp[i][j ] = max(dp[i][j], dp[i - 1][z]+arr[i][j-z]);   //筛出最大的dp[i][j]			}
			}
		}
		printf("%d\n", dp[n][m]);
	}
	return 0;
}