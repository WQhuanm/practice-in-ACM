#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

//
//一、游戏玩家可以是2人或者多人；
//二、游戏的道具是一个棋盘和若干的棋子，棋子上都有一个正整数（start 和 end 这2个棋子除外）； 
//三、所有的棋子都在一条直线上，每次只能从左往右走，并且只能从小的数字跳到大的数字；
//四、参与游戏的玩家每人操作一次；
//五、每个玩家的每次操作都是从最左边的start出发，到达最右边的end结束；
//六、start能跳到任何棋子，从任何棋子都能跳到end棋子。
//七、每人的得分为路径上走过的数字和；
//
//现在，如果按照从左到右的顺序告诉你棋子的信息，作为信奥小学员的你，能否编程计算出能够得到的最高分？
//Input
//输入包含多组测试用例；
//每组数据的第一个数N（N <= 1000）表示棋子的数量，然后是从左到右的N个棋子的数值（int32范围）；
//N为0的时候，表示输入数据的结束。


int dp[1100];
int a[1100];

int main() {
	int n;
	while (scanf("%d", &n) == 1 && n != 0) {
		memset(dp, 0,sizeof(dp));
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= n; ++i)scanf("%d", &a[i]); 
	
		for (int i = n; i >= 1; --i) {   //第i个数加给前面的数
			int x = 0;
			for (int j = i - 1; j >= 0; --j) {  
				if (j)//第j个数加上可以的dp[i]+a[i]
				{
					if (a[j]<a[i] && a[j]>x) {   //只要比赋值值小，并且比前面的数（除了赋值数）大，就累加（避免重复累加）		
						dp[j] = max(dp[j], dp[i] + a[i]);      //dp不加自己，只表示自己前面比自己大的数的全部累加值，因为最终存到dp[0]里面，会以 dp[i] + a[i]的形式存入a[i[-]
						x = a[j];
					}
				}
				else
					dp[j] = max(dp[j], dp[i] + a[i]);  //j=0时特判，用于存储目前最大累加值
			}
	}
		printf("%d\n", dp[0]);
	}
	return 0;
}