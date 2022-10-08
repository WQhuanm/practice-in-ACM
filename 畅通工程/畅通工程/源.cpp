#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>

using namespace std;

                                     //方法，并查集
const int N = 1000001;
int a[N];

int find(int x) {   //查找x的最上级(a[x]表示x的最上级），当的最上级为自己时，a[x]=x
	if (x != a[x])a[x]=find(a[x]); //如果a[x]不是自己，说明他有上级，那么他的上级等于find(a[x])（即a[x]代表的这个值（t）的a[t]，如果a[t]=t，那么他自己就是最上级，不是继续找
	return a[x];   //最终返回最上级
}
void unit(int x, int y) {  //输入的俩个村庄合并为一个，（归一个上级管）
	a[find(x)] = find(y);   //把x的最上级t附属于y的最上级，那么a[t]不再等于t，而是等于find(y)(不直接写a[y]，因为还没刷新a[y]
}


int main() {
	int n, m;
	while (scanf("%d", &n) == 1 && n) {
		scanf("%d", &m);
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= n; ++i)a[i] = i;  //初始化最上级为自己
		int x, y;
		for (int i = 1; i <= m; ++i) {
			scanf("%d %d", &x, &y); unit(x, y);
		}
		int sum = 0;
		for (int i = 1; i <= n; ++i)if (a[i] == i)sum++;
		cout << sum - 1 << "\n";
	}

}

//某市调查城镇交通状况，得到现有城镇道路统计表。表中列出了每条道路直接连通的城镇。市政府 "村村通工程" 的目标是使全市任何两个城镇间都可以实现交通（但不一定有直接的道路相连，只要相互之间可达即可）。请你计算出最少还需要建设多少条道路？
//
//输入格式
//输入包含若干组测试数据，每组测试数据的第一行给出两个用空格隔开的正整数，分别是城镇数目 nn 和道路数目 mm ；随后的 mm 行对应 mm 条道路，每行给出一对用空格隔开的正整数，分别是该条道路直接相连的两个城镇的编号。简单起见，城镇从 11 到 nn 编号。
//
//注意：两个城市间可以有多条道路相通。
//
//在输入数据的最后，为一行一个整数 00，代表测试数据的结尾。
//
//输出格式
//对于每组数据，对应一行一个整数。表示最少还需要建设的道路数目。