#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>

const int w = 2e9;
using namespace std;
//
//本题目包含多组测试，请处理到文件结束。每个测试包括四行：
//第一行是一个整数L代表跑道的总长度
//第二行包含三个整数N，C，T，分别表示充电站的个数，电动车冲满电以后能行驶的距离以及每次充电所需要的时间
//第三行也是三个整数VR，VT1，VT2，分别表示兔子跑步的速度，乌龟开电动车的速度，乌龟脚蹬电动车的速度
//第四行包含了N(N <= 100)个整数p1, p2...pn, 分别表示各个充电站离跑道起点的距离，其中0 < p1 < p2 < ... < pn < L
//	其中每个数都在32位整型范围之内。



double dp[110];   //储存到每个站点最小时间
double arr[110];   //储存每个站点到起点距离

int main() {
	double L, C, T, vr, vt1, vt2;
	int N;
	while (scanf("%lf %d %lf %lf %lf %lf %lf", &L, &N, &C, &T, &vr, &vt1, &vt2) == 7) {
		memset(dp, 0, sizeof(dp));
		memset(arr, 0, sizeof(arr));
		arr[0] = 0; arr[N + 1] = L;   //一个起点，一个终点的距离
		double tmin = 0;
		for (int i = 1; i <= N; ++i)scanf("%lf", &arr[i]);
		for (int i = 1; i <= N + 1; ++i) {
			double mymin = w;     //一定要在每次进入j循环时重置，否则会保留上一个循环的最小值，mymin只是用于求每轮j循环的最小值，不是整个i循环
			for (int j = 0; j < i; ++j) {      //表示第j站到第i站的最短时间  ，所以i从1开始，就从0开始
				if (C >= arr[i] - arr[j])
					tmin = (arr[i] - arr[j]) / vt1;
				else {
					tmin = C / vt1 + ((arr[i] - arr[j])-C) / vt2;   //(arr[i] - arr[j])这个大，是他减去C
				}
				if (j)tmin += T;   //只要j不是0（即不是起点），就加充电时间，不用管究竟有没有必要，因为dp时会自动筛选，如从j到i充电一次就好，那我最小时间是dp[j]+tmin
				                        //但是如果我中间每次都充电，时间肯定大了，会被min除掉
				mymin = min(mymin, dp[j] + tmin);
			}
			dp[i] = mymin;  //第二个循环是求到第i个站点的tmin，所以遍历循环后的时间再赋予就行，减少时间计算
		}
		double tr = L / vr;//兔子时间
		if (tr > dp[N + 1])printf("What a pity rabbit!\n");
		if (tr < dp[N + 1])printf("Good job,rabbit!\n");
	}
	return 0;
}