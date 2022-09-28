#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;
//
//Input
//输入数据首先包含一个正整数C，表示有C组测试用例，每组测试用例的第一行是两个整数n和m(1 <= n <= 100, 1 <= m <= 100), 分别表示经费的金额和大米的种类，然后是m行数据，
//每行包含3个数p，h和c(1 <= p <= 20, 1 <= h <= 200, 1 <= c <= 20)，分别表示每袋的价格、每袋的重量以及对应种类大米的袋数。
//Output
//对于每组测试数据，请输出能够购买大米的最多重量，你可以假设经费买不光所有的大米，并且经费你可以不用完。每个实例的输出占一行。
//


int dp[2100][110];   //dp[i][j]为当前i件剩余j金额情况下获得的最优重量
int h[2100];  //表示第几类大米对应的重量
int p[2100]; //表示第几类大米对应的价格

int main() {
	int C;
	scanf("%d", &C);
	while (C--) {
		int n, m;
		scanf("%d %d", &n, &m);
		memset(dp, 0, sizeof(dp));
		memset(h, 0, sizeof(h));
		memset(p, 0, sizeof(p));
		int sum = 0;  //sum为所以米总袋数
		int x = 1;  //大米数组从1开始 
		for (int i = 1; i <= m; ++i) {      //遍历每一种类大米
			int k = 0;   //k表示这种类型大米的袋数,
			scanf("%d %d %d", &p[x], &h[x], &k);  //p[x],h[x]为每种类大米的头头
			                 
				for (int j =x; j <= k+x-1; ++j) {   //把这种米填入数组
					h[j] = h[x]; p[j] = p[x];
				}
				x += k;  //使下一次填入大米在k袋后面
			
			sum += k;
		}
		
		for (int i = 1; i <= sum; ++i) {           //dp[i][j]为当前i件剩余j金额情况下获得的最优重量
			for(int j = 0; j <= n; ++j) {    //从j=0开始，说不定可以免费买米？这样保险
				if (j < p[i])dp[i][j] = dp[i - 1][j];   //如果剩下j元不够买，那么情况与i-1件剩余j元情况相同
				else {
					dp[i][j] = max(dp[i - 1][j], dp[i-1][j - p[i]] + h[i]);  //比较不加入第i件与用了j - p[i]元获得的最大价值（重量），然后花剩余的p[i]元再买入价值（重量)h[i]谁是最优解
					                         //注意，比较的俩者都是在当前i-1件的前提下，不是有一个是i
				}

			}
		}
		printf("%d\n", dp[sum][n]);


	}
	return 0;
}