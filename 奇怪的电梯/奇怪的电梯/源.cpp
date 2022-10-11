#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>

using namespace std;

const int N = 210;
const int INF = 0x3f3f3f3f;

int book[N];  //标记是否访问;
int dist[N];
int arr[N];
int now[N];      //记录离目标近的当前点
int n;
void cdis(int x) {
	int count = 0; int t1 = 1, t2 = 0;   //用于表示每个k循环now中的头和尾
	for (int i = 1; i <= n; ++i) {  //最多遍历n个book
		count++; int tmp = t2;//存储上一轮的t2
		for (int j = 1; j <= n; ++j) {

			if (i == 1) {
				if (!book[j] && (j + arr[j] == x || j - arr[j] == x)) { book[j] = 1; dist[j] = count; now[++t2] = j; }
				
			}
			else {
				for (int k = t1; k <= tmp; ++k) {  //这里不能用t2表示尾巴，因为循环中t2随时会更新，必须保证是上一轮的t2，即tmp
					if (!book[j]&&(j + arr[j] == now[k] || j - arr[j] == now[k])) { book[j] = 1; dist[j] = count; now[++t2] = j; break; }
				}

			}
		
		}
		t1 = tmp+1;  //更新t1为上一轮t2的下一个数
	}

}

int main() {
	int a, b;
	while (~scanf("%d", &n)&&n) {
		scanf("%d%d",&a, &b);
		for (int i = 1; i <= n; ++i)cin >> arr[i];
		memset(book, 0, sizeof(book));
		memset(dist, 0x3f, sizeof(dist));
		cdis(b);
		if (a == b) {  //不要忘了，没说不能a==b
			cout << 0 << endl;
		}
		else
		{
			if (dist[a] < INF)cout << dist[a] << endl;
			else cout << -1 << endl;
		}
	}
	

	return 0;
}



//
//有一个奇怪的电梯，他可以停在任何一层，并且在每个楼层有一个Ki（0 <= Ki <= N）。电梯只有两个按钮：上、下。当你在第i层，如果你按下“UP”按钮，你将上升Ki层，也就是说，你将会到达第i + Ki层，如果你按下“DOWN”按钮，你会下降 Ki层，即您将前往第i - Ki层。当然，电梯不能高于N，也不能低于1。
//例如，有5层的建筑物，并且k1 = 3，k2 = 3，k3 = 1，k4 = 2，k5 = 5。从1楼开始，你可以按下“UP”按钮，你会到4楼，但如果你按下“DOWN”按钮，电梯不做处理，因为它不能下到 - 2楼。
//
//问：当你在A楼而想去B楼时，至少须按下“UP”或“DOWN”按钮多少次？ 其中，1 <= N, A, B <= 200
//Input
//输入包含多个测试用例。
//每个测试用例包含两行：
//首先一行包含三个整数N，A，B（1 <= N，A，B <= 200），第二行由N个整数k1，k2，... kn组成。
//单个0表示输入结束。
//Output
//对于每组数据，请输出从A楼到B楼需要的最少的按钮次数，如果你不能到达B楼，请直接输出 - 1。


