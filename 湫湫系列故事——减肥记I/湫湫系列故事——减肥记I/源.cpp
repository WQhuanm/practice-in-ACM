#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

//
//当然，为了方便你制作食谱，湫湫给了你每日食物清单，上面描述了当天她想吃的每种食物能带给她的幸福程度，以及会增加的卡路里量。
//Input
//输入包含多组测试用例。
//每组数据以一个整数n开始，表示每天的食物清单有n种食物。
//接下来n行，每行两个整数a和b，其中a表示这种食物可以带给湫湫的幸福值（数值越大，越幸福），b表示湫湫吃这种食物会吸收的卡路里量。
//最后是一个整数m，表示湫湫一天吸收的卡路里不能超过m。
//
//[Technical Specification]
//1. 1 <= n <= 100
//2. 0 <= a, b <= 100000
//3. 1 <= m <= 100000
//Output
//对每份清单，输出一个整数，即满足卡路里吸收量的同时，湫湫可获得的最大幸福值。



int dp[100010];  //dp[j]表示有j卡路里可以用时最大幸福值，完全不需要管有多少fj，因为放在循环中自然用到
int a[110];  //幸福值
int b[110];  //卡路里

int main() {
	int n;
	while (scanf("%d", &n) == 1) {
		memset(dp, 0, sizeof(dp));
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		
		for (int i = 1; i <= n; ++i)scanf("%d %d", &a[i], &b[i]);
		int m;
		scanf("%d", &m);
   	
		for (int k = 0; k <= m; ++k) {     //以拥有卡路里为头
			for (int i = 1; i <= n; ++i) {  //每k个卡路里遍历全部b[i]，因为没有说只有一个，或者有限个，所以这么写
				if (k < b[i])dp[k] = dp[k];
				else {
					dp[k] = max(dp[k], dp[k - b[i]] + a[i]);

				}
			}

		}
		printf("%d\n", dp[m]);

	}
	

	return 0;
}