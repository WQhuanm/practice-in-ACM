#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char x[1100]; char y[1100];
int dp[1100][1100];

int main() {
	while (scanf("%s %s", x, y) == 2) {
		memset(dp, 0, sizeof(dp));
		int len1 = strlen(x); int len2 = strlen(y);
		for (int i = 1; i <= len1; ++i) {
			for (int j = 1; j <= len2; ++j) {                  //假设前n-1都是最长的，对于n，有俩种情况，一种Xn==Ym，这样就长度加一，要么不等，那么fn还是与前一个一样，
				if (x[i - 1] == y[j - 1])dp[i][j] = dp[i - 1][j - 1] + 1;   //那么要么是为Xn-1Ym的最长序列，要么是XnYm-1的
				else    //因为x[]与y[]都是从下标0开始，而i从1开始，所以减一，但是统计长度dp从1开始，所以不用
					dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
		printf("%d\n", dp[len1][len2]);

}



	return 0;
}