#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;


//
//小老鼠准备了M磅的猫粮，准备去和看守仓库的猫做交易，因为仓库里有小老鼠喜欢吃的五香豆。
//仓库有N个房间；第i个房间有J[i] 磅的五香豆，需要用F[i]磅的猫粮去交换；
//需要指出的是：老鼠如果要和某个房间的猫做交易，就必须交换该房间所有的五香豆！
//现在，请帮忙计算一下，小老鼠通过交易最多能够得到多少磅的五香豆？
//Input
//输入包含多组测试用例。
//每组测试数据首先一行是2个非负整数M和N，接着的N行，每行分别包含2个非负整数J[i]和F[i]，数据的具体含义详见题目描述。
//输入数据以两个 - 1结束。
//题目保证所有的数据不超过1000.

int j[1100]; //豆子
int f[1100];  //猫粮
int dp[1100][1100];  //dp[i][k]表示第i间房间剩余k猫粮时的共换取最大豆子的最优解

int main() {
	
	int N,M;  //有N个房间,M磅的猫粮
	while (scanf("%d %d", &M,&N) == 2&&(N!=-1||M!=-1) ){
		memset(j, 0, sizeof(j));
		memset(f, 0, sizeof(f));
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= N; ++i) {
			scanf("%d %d", &j[i], &f[i]);
		}
		for (int i = 1; i <= N; ++i) {
			for(int k=0;k<=M;++k){  //从猫粮为0开始，说不定人家可以免费送你豆子呢
				if (k < f[i])dp[i][k] = dp[i - 1][k];
				else
					dp[i][k] = max(dp[i - 1][k], dp[i - 1][k - f[i]] + j[i]);
			}
		}
		printf("%d\n", dp[N][M]);

	}

	return 0;
}


