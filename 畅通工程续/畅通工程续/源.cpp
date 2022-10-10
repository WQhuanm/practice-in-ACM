#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>

using namespace std;
//                               //froly算法（复杂度O（n^3),用于求俩点最短距离
//const int MAXN = 0x3f3f3f3f;     //开maxn就要最大，防止被卡，这里开2e9还会被卡
//const int N = 210;
//
//int arr[N][N];
//
//int main() {
//	int n, m;
//	while (scanf("%d %d", &n, &m) == 2) {
//		int a, b, c;
//		memset(arr, 0, sizeof(arr));  //不要忘了多组数据要清零
//		for (int i = 0; i < n; ++i)for (int j = 0; j < n; ++j) {
//			if (i == j)arr[i][j] = 0;   //初始化时，i==j，说明起点与终点一样，那么距离肯定是0，其余初始化为无穷大
//			else arr[i][j] = MAXN;   
//		}
//		for (int i = 1; i <= m; ++i) {
//			scanf("%d %d %d", &a, &b, &c);
//			if(arr[a][b]>c)arr[a][b]=arr[b][a] = c;
//
//		}            
//		for (int k = 0; k < n; ++k)for (int i = 0; i < n; ++i)for (int j = 0; j < n; ++j)arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);//注意，k放最前面循环，表示第k个为中间时起点与终点情况
//		int s, t;
//		cin >> s >> t;
//		if (arr[s][t] >= MAXN)cout << -1 << endl;
//		else cout << arr[s][t] << endl;
//	}
//	return 0;
//}

                        //迪杰斯特拉法（贪心）,时间复杂度O（n^2)
const int INF = 0x3f3f3f3f;
const int N = 210;

int arr[N][N];  //arr[i][j]表示i到j距离
int book[N];//标记是否被访问过
int dis[N];//dis[i]表示i到目标的距离

int n, m;

void dijsktra(int x) {
	for (int i = 0; i < n; ++i) {  //需要每个都寻找一遍
		int tmp = -1;
		dis[x] = 0;//目标到目标距离肯定为0
		for (int j = 0; j < n; ++j) {  //每一次遍历找当前最小
			if (!book[j] && (tmp == -1 || dis[j] < dis[tmp]))tmp = j;//tmp = -1是保证第一个数一定能进来，之后遍历寻找目前离目标最近的点（标记为tmp）
			                     //注意tmp==-1不要写成=-1
		}
		book[tmp] = 1;//先标记为已经访问
		for (int k=0; k < n; ++k)dis[k] = min(dis[k], dis[tmp] + arr[tmp][k]);  //更新有了dis[tmp]后获得的新一轮的离目标最近的dis[]
		//这里还在i循环里面，不要不小心还用i来循环
	}

}

int main() {
	while (~scanf("%d %d", &n, &m)) {
		memset(arr, 0x3f, sizeof(arr));  //memset每次处理一个字节，int是4个字节，那么0x3f对应4个字节就是0x3f3f3f3f
		memset(book, 0, sizeof(book));//book==0表示还未操作过
		memset(dis, 0x3f, sizeof(dis));
		for (int i = 1; i <= m; ++i) {
			int a, b, c;
			cin >> a >> b >> c;
			arr[a][b] =arr[b][a]= min(arr[a][b], c);
		}
		int s, t;
		cin >> s >> t;
		dijsktra(s);
		if (dis[t] < INF)cout << dis[t] << endl;
		else cout << -1 << endl;
	}

	return 0;
}











//
//某省自从实行了很多年的畅通工程计划后，终于修建了很多路。不过路多了也不好，每次要从一个城镇到另一个城镇时，都有许多种道路方案可以选择，而某些方案要比另一些方案行走的距离要短很多。这让行人很困扰。
//
//现在，已知起点和终点，请你计算出要从起点到终点，最短需要行走多少距离。
//Input
//本题目包含多组数据，请处理到文件结束。
//每组数据第一行包含两个正整数N和M(0 < N < 200, 0 < M < 1000)，分别代表现有城镇的数目和已修建的道路的数目。城镇分别以0～N - 1编号。
//	接下来是M行道路信息。每一行有三个整数A, B, X(0 <= A, B < N, A != B, 0 < X < 10000), 表示城镇A和城镇B之间有一条长度为X的双向道路。
//	再接下一行有两个整数S, T(0 <= S, T < N)，分别代表起点和终点。
//	Output
//	对于每组数据，请在一行里输出最短需要行走的距离。如果不存在从S到T的路线，就输出 - 1.

